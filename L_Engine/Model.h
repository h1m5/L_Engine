//
//  Model.h
//  nfghdg
//
//  Created by Imhoisili Otokhagua on 27/01/15.
//  Copyright (c) 2015 TriKomand. All rights reserved.
//

#ifndef __nfghdg__Model__
#define __nfghdg__Model__

#include <iostream>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "Mesh.h"

class Model {
    vector<Mesh> meshes;
    string directory;
    vector<Texture> textures_loaded;
    
    void loadModel(string path);
    void processNode(aiNode *node, const aiScene *scene);
    Mesh processMesh(aiMesh *mesh, const aiScene *scene);
    vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, string typeName);
    
public:
    Model(string path){
        loadModel(path);
    }
    Model(){}
    
    void Draw(Shader shader);
};

GLint TextureFromFile(const char* path, string directory);

#endif /* defined(__nfghdg__Model__) */
