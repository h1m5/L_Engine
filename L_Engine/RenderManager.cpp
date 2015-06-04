//
//  RenderManager.cpp
//  L_Engine
//
//  Created by Imhoisili Otokhagua on 25/03/15.
//  Copyright (c) 2015 TriKomand. All rights reserved.
//

#include "RenderManager.h"
#include <iostream>

static const GLfloat quadVertices[] = {
    -1.0f,  1.0f,  0.0f, 1.0f,
    -1.0f, -1.0f,  0.0f, 0.0f,
    1.0f, -1.0f,  1.0f, 0.0f,
    
    -1.0f,  1.0f,  0.0f, 1.0f,
    1.0f, -1.0f,  1.0f, 0.0f,
    1.0f,  1.0f,  1.0f, 1.0f
};


RenderManager *RenderManager::m_instance;

RenderManager::RenderManager()
{

}

RenderManager::RenderManager(VideoManager *window)
: m_window(window)
{
    //read system get player initialization settings settings
    glFrontFace(GL_CW);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    
    createFBO();
    aCube = new Cube();
    
    setMainCamera(new Camera(vec3(1.0, 1.0, 5.0)));
    
    //setup shaders
    frameShader = ResourceManager::LoadShader("framebuffers.vs", "framebuffers.frag", nullptr, "frameShader");
    screenShader = ResourceManager::LoadShader("framebuffers_screen.vs", "framebuffers_screen.frag", nullptr, "screenShader");
    
    glGenVertexArrays(1, &quadVAO);
    glGenBuffers(1, &quadVBO);
    glBindVertexArray(quadVAO);
    glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)(2 * sizeof(GLfloat)));
    glBindVertexArray(0);
}

RenderManager::~RenderManager()
{
    
}

void RenderManager::startUp()
{
    get();
}

void RenderManager::render()
{
    //exercise: create rear mirror
    //TODO: 1) draw the back view of the scene to texture
    glBindFramebuffer(GL_FRAMEBUFFER, fbo);
    glDisable(GL_CULL_FACE);
    glClearColor(0.1, 0.2, 0.3, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    frameShader.Use();
    glm::mat4 view = mainCamera->getViewMatrix();
    view = translate(view, vec3(0, 0, -1));
    view = glm::rotate(view, 180.0f, vec3(0, 1, 0));
    
    mat4 projection = glm::perspective(mainCamera->getFov(), (float)m_window->getWindowWidth()/(float)m_window->getWindowHeight(), 0.1f, 100.0f);
    mat4 model = mat4();
    model = translate(model, vec3(2.0, 0.0, 0.0));
    frameShader.SetMatrix4("view", view);
    frameShader.SetMatrix4("model", model);
    frameShader.SetMatrix4("projection", projection);
    aCube->draw();
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    
    //TODO: 2) render scene in default framebuffer
    glDisable(GL_CULL_FACE);
    glClearColor(0.1, 0.5, 0.1, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    
//    frameShader.Use();
    mat4 frontView = mainCamera->getViewMatrix();
    frameShader.SetMatrix4("view", frontView);
//    frameShader.SetMatrix4("projection", projection);
    
    //cube
//    frameShader.SetMatrix4("model", model);
    frameShader.SetInteger("texture1", 0);
    aCube->draw();
    
    //TODO: now draw the quad with framebuffer texture over the scene
    screenShader.Use();
    glDisable(GL_DEPTH_TEST);
    projection = glm::ortho(-1, 1, -1, 1, -1, 2);
    model = mat4();
    model = glm::translate(model, vec3(0, 0.7, 0));
    model = glm::scale(model, vec3(0.5f));
    screenShader.SetMatrix4("mMatrix", model);
    screenShader.SetMatrix4("pMatrix", projection);
    glBindVertexArray(quadVAO);
    glBindTexture(GL_TEXTURE_2D, tbo);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
    
    
    //render to texture
//    glBindFramebuffer(GL_FRAMEBUFFER, fbo);
//    glDisable(GL_CULL_FACE);
//    glClearColor(0.1, 1.0, 0.1, 1.0);
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glEnable(GL_DEPTH_TEST);
//    
//    frameShader.Use();
//    mat4 projection = glm::perspective(mainCamera->getFov(), (float)m_window->getWindowWidth()/(float)m_window->getWindowHeight(), 0.1f, 100.0f);
//    mat4 view = mainCamera->getViewMatrix();
//    frameShader.SetMatrix4("view", view);
//    frameShader.SetMatrix4("projection", projection);
//    
//    //cube
//    mat4 model = mat4();
//    model = translate(model, vec3(0.0, 0.0, -1.0));
//    frameShader.SetMatrix4("model", model);
//    frameShader.SetInteger("texture1", 0);
//    aCube->draw();
//    glBindFramebuffer(GL_FRAMEBUFFER, 0);
//
//    glClearColor(0.1, 0.2, 0.3, 1.0);
//    glClear(GL_COLOR_BUFFER_BIT);
//    glDisable(GL_DEPTH_TEST);
    
//    //draw screen
//    screenShader.Use();
//    glBindVertexArray(quadVAO);
//    glBindTexture(GL_TEXTURE_2D, tbo);
//    glDrawArrays(GL_TRIANGLES, 0, 6);
//    glBindVertexArray(0);
}

void RenderManager::createFBO()
{
    glGenFramebuffers(1, &fbo);
    glBindFramebuffer(GL_FRAMEBUFFER, fbo);
    
    //create texture to render to
    glGenTextures(1, &tbo);
    glBindTexture(GL_TEXTURE_2D, tbo);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_window->getWindowWidth(), m_window->getWindowHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 0);
    
    //assign texture to fbo
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, tbo, 0);
    
    //create renderbuffer
    glGenRenderbuffers(1, &rbo);
    glBindRenderbuffer(GL_RENDERBUFFER, rbo);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, m_window->getWindowWidth(), m_window->getWindowHeight());
    glBindRenderbuffer(GL_RENDERBUFFER, 0);
    
    //attach render buffer to framebuffer
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);
    
    if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
        std::cout << "ERROR FRAMEBUFFER: Framebuffer is not complete" << std::endl;
    
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

}

void RenderManager::shutDown()
{
}

RenderManager* RenderManager::get()
{
    if (!m_instance) {
        m_instance = new RenderManager(VideoManager::get(0, 0, ""));
    }
    
    return m_instance;
}

void RenderManager::setMainCamera(Camera *cam)
{
    mainCamera = cam;
}