//
//  Texture.h
//  Breakout
//
//  Created by Imhoisili Otokhagua on 19/03/15.
//  Copyright (c) 2015 TriKomand. All rights reserved.
//

#ifndef __Breakout__Texture__
#define __Breakout__Texture__

#include <gl/glew.h>

// Texture2D is able to store and configure a texture in OpenGL.
// It also hosts utility functions for easy management.
class Texture2D
{
public:
    // Holds the ID of the texture object, used for all texture operations to reference to this particlar texture
    
    GLuint ID;
    // Texture image dimensions
    GLuint Width, Height; // Width and height of loaded image in pixels
    // Texture Format
    GLuint Internal_Format; // Format of texture object
    GLuint Image_Format; // Format of loaded image
    // Texture configuration
    GLint Wrap_S; // Wrapping mode on S axis
    GLint Wrap_T; // Wrapping mode on T axis
    GLint Filter_Min; // Filtering mode if texture pixels < screen pixels
    GLint Filter_Max; // Filtering mode if texture pixels > screen pixels
    // Constructor (sets default texture modes)
    Texture2D();
    // Generates texture from image data
    void Generate(GLuint width, GLuint height, unsigned char* data);
    // Binds the texture as the current active GL_TEXTURE_2D texture object
    void Bind() const;
};

#endif /* defined(__Breakout__Texture__) */
