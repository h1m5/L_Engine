//
//  Cube.cpp
//  L_Engine
//
//  Created by Imhoisili Otokhagua on 04/05/15.
//  Copyright (c) 2015 TriKomand. All rights reserved.
//

#include "Cube.h"
static const GLfloat vertices[] = {
    -0.5, -0.5,  0.5,   //front
    0.5, -0.5,  0.5,
    0.5,  0.5,  0.5,
    0.5,  0.5,  0.5,
    -0.5,  0.5,  0.5,
    -0.5, -0.5,  0.5,
    
    0.5, -0.5, -0.5,    //back
    -0.5, -0.5, -0.5,
    -0.5,  0.5, -0.5,
    -0.5,  0.5, -0.5,
    0.5,  0.5, -0.5,
    0.5, -0.5, -0.5,
    
    -0.5, -0.5, -0.5,   //left
    -0.5, -0.5,  0.5,
    -0.5,  0.5,  0.5,
    -0.5,  0.5,  0.5,
    -0.5,  0.5, -0.5,
    -0.5, -0.5, -0.5,
    
    0.5, -0.5,  0.5,    //right
    0.5, -0.5, -0.5,
    0.5,  0.5, -0.5,
    0.5,  0.5, -0.5,
    0.5,  0.5,  0.5,
    0.5, -0.5,  0.5,
    
    -0.5,  0.5,  0.5,   //top
    0.5,  0.5,  0.5,
    0.5,  0.5, -0.5,
    0.5,  0.5, -0.5,
    -0.5,  0.5, -0.5,
    -0.5,  0.5,  0.5,
    
    -0.5, -0.5, -0.5,   //bottom
    0.5, -0.5, -0.5,
    0.5, -0.5,  0.5,
    0.5, -0.5,  0.5,
    -0.5, -0.5,  0.5,
    -0.5, -0.5, -0.5,
};

static const GLfloat texCoords[] = {
    1, 1, 0, 1, 0, 0,
    0, 0, 1, 0, 1, 1,
    
    1, 1, 0, 1, 0, 0,
    0, 0, 1, 0, 1, 1,
    
    1, 1, 0, 1, 0, 0,
    0, 0, 1, 0, 1, 1,
    
    1, 1, 0, 1, 0, 0,
    0, 0, 1, 0, 1, 1,
    
    1, 1, 0, 1, 0, 0,
    0, 0, 1, 0, 1, 1,
    
    1, 1, 0, 1, 0, 0,
    0, 0, 1, 0, 1, 1,
};

static const GLfloat normals[] = {
    0,  0,  1,  //front
    0,  0,  1,
    0,  0,  1,
    0,  0,  1,
    0,  0,  1,
    0,  0,  1,
    
    0,  0, -1,  //back
    0,  0, -1,
    0,  0, -1,
    0,  0, -1,
    0,  0, -1,
    0,  0, -1,
    
    -1,  0,  0, //left
    -1,  0,  0,
    -1,  0,  0,
    -1,  0,  0,
    -1,  0,  0,
    -1,  0,  0,
    
    1,  0,  0,  //right
    1,  0,  0,
    1,  0,  0,
    1,  0,  0,
    1,  0,  0,
    1,  0,  0,
    
    0,  1,  0,  //top
    0,  1,  0,
    0,  1,  0,
    0,  1,  0,
    0,  1,  0,
    0,  1,  0,
    
    0, -1,  0,  //bottom
    0, -1,  0,
    0, -1,  0,
    0, -1,  0,
    0, -1,  0,
    0, -1,  0,
};

Cube::Cube()
{
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) + sizeof(normals) + sizeof(texCoords), 0, GL_STATIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), (void*)(vertices));
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices), sizeof(normals), (void*)(normals));
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices) + sizeof(normals), sizeof(texCoords), (void*)(texCoords));
    
    int offset = 0;
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0 , (void*)offset);
    glEnableVertexAttribArray(0);
    offset += 36 * 3;
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)(sizeof(float) * offset));    //  normals
    glEnableVertexAttribArray(1);
    offset += 36 * 3;
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, (void*)(sizeof(float) * offset));    //  textureCoordinates
    
    glBindVertexArray(0);
    
    //load cube texture
    tex = ResourceManager::LoadTexture("hanna.png", GL_FALSE, "underWater");
}

void Cube::draw()
{
    glActiveTexture(GL_TEXTURE0);
    tex.Bind();
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
}







