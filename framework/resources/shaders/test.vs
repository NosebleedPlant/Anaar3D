#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
out vec3 ourColor;
uniform float offset;
void main()
{
   vec3 new_pos = vec3(aPos.x + offset, aPos.y*-1, aPos.z);
   gl_Position = vec4(new_pos, 1.0);
   ourColor = aColor;
};