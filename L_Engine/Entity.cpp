//
//  Entity.cpp
//  L_Engine
//
//  Created by Imhoisili Otokhagua on 04/06/15.
//  Copyright (c) 2015 TriKomand. All rights reserved.
//

#include "Entity.h"

Entity2D::Entity2D() : m_texture(nullptr)
{
    setUVDefaults();
}

Entity2D::Entity2D(glm::vec3 position, glm::vec2 size, unsigned color)
:m_position(position)
,m_size(size)
,m_color(color)
{
    setUVDefaults();
}

void Entity2D::submit(RenderManager *renderer) const
{
//    renderer->submit(this);
}

void Entity2D::setColor(unsigned color)
{
    m_color = color;
}

void Entity2D::setColor(const glm::vec4& color)
{
    int r = color.x * 255.0f;
    int g = color.y * 255.0f;
    int b = color.z * 255.0f;
    int a = color.w * 255.0f;
    
    m_color = a << 24 | b << 16 | g << 8 | r;
}

void Entity2D::setUVDefaults()
{
    m_uv.push_back(glm::vec2(0, 0));
    m_uv.push_back(glm::vec2(0, 1));
    m_uv.push_back(glm::vec2(1, 1));
    m_uv.push_back(glm::vec2(1, 0));
}