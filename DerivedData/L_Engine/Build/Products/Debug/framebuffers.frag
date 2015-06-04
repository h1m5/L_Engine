#version 410 core
uniform sampler2D texture1;

in vec2 tCoord;

out vec4 fragColor;
void main()
{
    fragColor = texture(texture1, tCoord);
}