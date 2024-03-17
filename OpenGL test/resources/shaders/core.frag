
// IF AN ERROR OCCURS, TRY CHANGING THE VERSION NUMBER (in `#version 410 core`)
#version 410 core

in vec3 myColor;
in vec2 TexCoord;

out vec4 color;

uniform sampler2D texture1;

void main() {
    color = texture(texture1, TexCoord);
}
