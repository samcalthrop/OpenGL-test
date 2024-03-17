
// IF AN ERROR OCCURS, TRY CHANGING THE VERSION NUMBER (in `#version 410 core`)
#version 410 core

in vec3 myColor;
out vec4 color;

void main() {
    color = vec4(myColor, 0.5f);
}
