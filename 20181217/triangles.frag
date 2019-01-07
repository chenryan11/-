#version 430 core
in vec3 xNormal;
in vec3 xColor;
out vec4 fColor;

void
main()
{
fColor = vec4(xColor, 1.0);
}
