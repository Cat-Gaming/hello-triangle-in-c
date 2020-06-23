#version 120

layout (location = 0) in vec3 position;

void main() {
    gl_Position = position;
}