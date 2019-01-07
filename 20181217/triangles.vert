#version 430 core
in vec2 vPosition;
in vec3 vNormal;
in vec3 vColor;
out vec3 xNormal;
out vec3 xColor;
void
main()
{
gl_Position = vec4(vPosition, 0, 1);
xNormal = vNormal;
xColor  = vColor;
}
