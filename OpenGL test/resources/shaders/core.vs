
// IF AN ERROR OCCURS, TRY CHANGING THE VERSION NUMBER (in `#version 410 core`)
#version 410 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;

out vec3 myColor;

void main() {
    gl_Position = vec4(position, 1.0);
    myColor = color;
}
