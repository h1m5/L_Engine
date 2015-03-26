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
    gVideoManager.starUp();
//    gTextureManager.startUp();
//    gRenderManager.startUp();
    
    cout << "hello world\n";
    
    Allocator *alloc = gMemoryManager->getAllocator();

    
    unsigned *mem = NULL;
    
    char x;
    while (x != 'x') {
        if (mem == NULL) {
            mem = reinterpret_cast<unsigned *>(alloc->Allocate());
        }
        *mem = 0u;
        cin >> x;
    }
    
    alloc->Free(mem);
    return 0;
}

