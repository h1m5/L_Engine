//
//  RenderManager.h
//  L_Engine
//
//  Created by Imhoisili Otokhagua on 25/03/15.
//  Copyright (c) 2015 TriKomand. All rights reserved.
//

#ifndef __L_Engine__RenderManager__
#define __L_Engine__RenderManager__

#include <stdio.h>
#include "VideoManager.h"
#include "ResourceManager.h"
#include <gl/glew.h>
#include "Cube.h"
#include "Camera.h"
#include "Shader.h"

class RenderManager {
    static RenderManager *m_instance;
    VideoManager *m_window;
    RenderManager(VideoManager *);
    
    //main camera
    Camera *mainCamera;
    
public:
    RenderManager();
    ~RenderManager();
    void startUp();
    void shutDown();
    void render(/*Render Object*/);
    static RenderManager *get();
    
    //
    void createFBO();
    GLuint fbo;
    GLuint tbo;
    GLuint rbo;
    GLuint quadVAO, quadVBO;
    
    //test cube
    Cube *aCube;
    
    //set main camera;
    void setMainCamera(Camera *cam);
    
    Shader frameShader;
    Shader screenShader;
};

#endif /* defined(__L_Engine__RenderManager__) */
