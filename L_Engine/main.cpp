//
//  main.cpp
//  L_Engine
//
//  Created by Imhoisili Otokhagua on 25/03/15.
//  Copyright (c) 2015 TriKomand. All rights reserved.
//

#include <iostream>
#include "ResourceManager.h"
#include "RenderManager.h"
#include "VideoManager.h"
#include "TextureManager.h"
#include "MemoryManager.h"
using namespace std;

RenderManager gRenderManager;
TextureManager gTextureManager;
VideoManager gVideoManager;

int main(int argc, const char * argv[]) {
    MemoryManager *gMemoryManager = MemoryManager::get();
    gVideoManager = *VideoManager::get(640, 480, "L_Engine");
    gRenderManager = *RenderManager::get();
    
    cout << "hello world\n";
    
    Allocator *alloc = gMemoryManager->getAllocator();

    
    unsigned *mem = NULL;
    
    while (!gVideoManager.isCloseRequested()) {
        if (mem == NULL) {
            mem = reinterpret_cast<unsigned *>(alloc->Allocate());
        }
        *mem = 0u;
        gRenderManager.render();
        gVideoManager.update();
        gVideoManager.swapBuffers();
    }
    
    alloc->Free(mem);
    return 0;
}

