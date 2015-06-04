#version 410 core
uniform sampler2D screenTexture;

out vec4 fragColor;
in vec2 tCoord;

const float offset = 1.0 / 300;

void main()
{
    
    vec2 offsets[9] = vec2[](
                             vec2(-offset, offset),  // top-left
                             vec2(0.0f,    offset),  // top-center
                             vec2(offset,  offset),  // top-right
                             vec2(-offset, 0.0f),    // center-left
                             vec2(0.0f,    0.0f),    // center-center
                             vec2(offset,  0.0f),    // center-right
                             vec2(-offset, -offset), // bottom-left
                             vec2(0.0f,    -offset), // bottom-center
                             vec2(offset,  -offset)  // bottom-right    
                             );
    
    float kernel[9] = float[](
                              -1, -3, -1,
                              -1,  13, -1,
                              -1, -3, -1
                              );
    
    vec3 sampleTex[9];
    for(int i = 0; i < 9; i++)
    {
        sampleTex[i] = vec3(texture(screenTexture, tCoord.st + offsets[i]));
    }
    vec3 col;
    for(int i = 0; i < 9; i++)
        col += sampleTex[i] * kernel[i];
    
    fragColor = vec4(col, 1.0);
}