//
//  EntityFactory.h
//  L_Engine
//
//  Created by Imhoisili Otokhagua on 04/06/15.
//  Copyright (c) 2015 TriKomand. All rights reserved.
//

#ifndef __L_Engine__EntityFactory__
#define __L_Engine__EntityFactory__

#include "Entity.h"

enum E_TYPE{
    ENTITY_2D,
    ENTITY_3D,
};

class EntityFactory
{
public:
    static Entity *createEntity(E_TYPE);
};

#endif /* defined(__L_Engine__EntityFactory__) */
