//
//  VideoManager.cpp
//  L_Engine
//
//  Created by Imhoisili Otokhagua on 25/03/15.
//  Copyright (c) 2015 TriKomand. All rights reserved.
//

#include "VideoManager.h"
#include <gl/glew.h>

VideoManager *VideoManager::m_video = nullptr;

VideoManager::VideoManager(int width, int height, const std::string& title)
:   m_width(width)
,   m_height(height)
,   m_title(title)
,   m_isCloseRequested(false)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE,32);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,16);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
    
//	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
//	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);
    
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 4 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );
    
    m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    
    m_glContext = SDL_GL_CreateContext(m_window);
    
    SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1");
    SDL_GL_SetSwapInterval(1);
    
    glewExperimental = GL_TRUE;
    GLenum res = glewInit();
    if (res != GLEW_OK) {
        fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
        shutDown();
    }
}

VideoManager::~VideoManager()
{
    
}

void VideoManager::starUp()
{

}

void VideoManager::shutDown()
{
    SDL_GL_DeleteContext(m_video->m_glContext);
    SDL_DestroyWindow(m_video->m_window);
    SDL_Quit();
}

VideoManager* VideoManager::get(int width, int height, const std::string& title)
{
    if (!m_video) {
        m_video = new VideoManager(width, height, title);
    }
    return m_video;
}

void VideoManager::update()
{
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        //do something
        if (e.type == SDL_QUIT) {
            m_isCloseRequested = true;
        }
    }
}

void VideoManager::swapBuffers()
{
    SDL_GL_SwapWindow(m_window);
}