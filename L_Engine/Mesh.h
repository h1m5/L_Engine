//
//  Mesh.h
//  nfghdg
//
//  Created by Imhoisili Otokhagua on 27/01/15.
//  Copyright (c) 2015 TriKomand. All rights reserved.
//

#ifndef __nfghdg__Mesh__
#define __nfghdg__Mesh__

#include <iostream>
#include <gl/glew.h>
#include <glm/glm.hpp>
#include <vector>
#include "Shader.h"
#include <assimp/types.h>

using namespace std;

struct Vertex{
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoords;
};

struct Texture{
    GLuint id;
    string type;
    aiString path;
};

class Mesh {
    GLuint VAO, VBO, EBO;
    void setupMesh();
    
public:
    vector<Vertex> vertices;
    vector<Texture> textures;
    vector<GLuint> indices; 
    
    Mesh(vector<Vertex> vertices, vector<GLuint> indices, vector<Texture> textures);
    void draw(Shader shader);
};

#endif /* defined(__nfghdg__Mesh__) */
