//
//  Entity.h
//  L_Engine
//
//  Created by Imhoisili Otokhagua on 04/06/15.
//  Copyright (c) 2015 TriKomand. All rights reserved.
//

#ifndef __L_Engine__Entity__
#define __L_Engine__Entity__

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <vector>
#include "Texture.h"
#include "RenderManager.h"

class Entity
{
    
public:
    
};

class Entity2D : public Entity
{
protected:
    struct VertexData
    {
        glm::vec3 vertex;
        glm::vec2 uv;
        float tid; // texture ID
        unsigned int color;
    };
    
    glm::vec3 m_position;
    glm::vec2 m_size;
    unsigned m_color;
    std::vector<glm::vec2> m_uv;
    Texture2D *m_texture;
public:
    Entity2D();
    Entity2D(glm::vec3 position, glm::vec2 size, unsigned color);
    
    virtual ~Entity2D(){}
    
    virtual void submit (RenderManager* renderer) const;
    
    void setColor(unsigned color);
    void setColor(const glm::vec4& color);
    
    inline const glm::vec3& getPosition() const { return m_position; }
    inline const glm::vec2& getSize() const { return m_size; }
    inline const unsigned getColor() const { return m_color; }
    inline const std::vector<glm::vec2>& getUV() const { return m_uv; }
    
    inline const GLuint getTID() const { return m_texture ? m_texture->ID : 0; }
    void setUVDefaults();
};

class Entity3D : public Entity
{
    
};

#endif /* defined(__L_Engine__Entity__) */
