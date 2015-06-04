//
//  EntityFactory.cpp
//  L_Engine
//
//  Created by Imhoisili Otokhagua on 04/06/15.
//  Copyright (c) 2015 TriKomand. All rights reserved.
//

#include "EntityFactory.h"

Entity* EntityFactory::createEntity(E_TYPE typ)
{
    switch (typ) {
        case ENTITY_2D: return new Entity2D(); break;
        case ENTITY_3D: return new Entity3D(); break;
        default: break;
    }
}