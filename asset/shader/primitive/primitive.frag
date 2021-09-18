#version 330 core
out vec4 FragColor;
in vec3 ourColor;

uniform vec3 u_color;
void main()
{
   FragColor = vec4(u_color, 1.0f);
}