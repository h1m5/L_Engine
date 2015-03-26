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
#include <gl/glew.h>

class RenderManager {
    static RenderManager *m_instance;
    VideoManager *m_window;
    RenderManager(VideoManager *);
public:
    RenderManager();
    ~RenderManager();
    void startUp();
    void shutDown();
    void render(/*Render Object*/);
    static RenderManager *get();
};

#endif /* defined(__L_Engine__RenderManager__) */
