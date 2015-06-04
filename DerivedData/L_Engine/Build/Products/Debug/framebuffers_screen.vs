#version 410

uniform mat4 pMatrix;
uniform mat4 mMatrix;

layout(location=0) in vec3 vert;
layout(location=1) in vec2 texCoord;

out vec2 tCoord;

void main()
{
    gl_Position = pMatrix * mMatrix * vec4(vert, 1.0);
    tCoord = texCoord;
}