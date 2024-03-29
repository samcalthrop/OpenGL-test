
// IF AN ERROR OCCURS, TRY CHANGING THE VERSION NUMBER (in `#version 410 core`)
#version 410 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 texCoord;

out vec3 myColor;
out vec2 TexCoord;

void main() {
    gl_Position = vec4(position, 1.0f);
    myColor = color;
    
    TexCoord = vec2(texCoord.x, 1.0-texCoord.y);
}
