//
//  Cube.h
//  L_Engine
//
//  Created by Imhoisili Otokhagua on 04/05/15.
//  Copyright (c) 2015 TriKomand. All rights reserved.
//

#ifndef __L_Engine__Cube__
#define __L_Engine__Cube__

#include <stdio.h>
#include <GL/glew.h>
#include "ResourceManager.h"

class Cube {
    GLuint vbo;
    Texture2D tex;
public:
    Cube();
    void draw();
    GLuint vao;
};
#endif /* defined(__L_Engine__Cube__) */
