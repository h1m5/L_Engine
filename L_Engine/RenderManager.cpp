//
//  RenderManager.cpp
//  L_Engine
//
//  Created by Imhoisili Otokhagua on 25/03/15.
//  Copyright (c) 2015 TriKomand. All rights reserved.
//

#include "RenderManager.h"

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
    
    glClearColor(0.5, 0.5, 0.5, 1.0);
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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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