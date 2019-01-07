#include <GL/glew.h>
#include <GL/freeglut.h>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "loadshaders.h"

typedef float* pfloat;

using namespace std;

GLuint nVBOs(3), nVAOs(2);  
GLuint  VBOs[2][3],  VAOs[2];
GLuint sizes[] = {2, 3, 3};
//Triangle 1
GLfloat v1[6] = { -0.90, -0.90, 0.85, -0.90, -0.90, 0.85 };
GLfloat n1[9] = { 0.0, 0.0, 0.90, 0.5, 0.0, 0.90, 0.0, 0.0, 0.90};
GLfloat c1[9] = { 0, 0, 1, 1, 0, 0, 0, 1, 0 };
//Triangle 2
GLfloat v2[6] = { 0.90, -0.85, 0.90, 0.90, -0.85, 0.90 };
GLfloat n2[9] = { 0.0, 0.0, 0.90, 0.0, 0.0, 0.90, 0.0, 0.0, 0.90};
GLfloat c2[9] = { 1, 1, 0, 0, 1, 1, 1, 0, 1 };
// pointers to the buffers of the two triangles
GLfloat *t[2][3]={{v1, n1, c1}, {v2, n2, c2}};

void display(void) {
glClear(GL_COLOR_BUFFER_BIT);
	for (int i=0; i<nVAOs; i++) {
		glBindVertexArray(VAOs[i]);
		glDrawArrays(GL_TRIANGLES, 0, 3); // draw the Triangle 1
	}
glFlush();
}

void init(void) {
	// set shaders
	ShaderInfo shaders[] = {{ GL_VERTEX_SHADER, "triangles.vert" },	{ GL_FRAGMENT_SHADER, "triangles.frag" }, { GL_NONE, NULL }};
	GLuint program = LoadShaders(shaders);
	glUseProgram(program);
	
	// set VAOs and their associated VBOs	
	glGenVertexArrays(nVAOs, VAOs);	
	for (int i=0; i<nVAOs; i++) {
		glBindVertexArray(VAOs[i]);
		glGenBuffers(nVBOs, VBOs[i]);

		for (int j=0; j<nVBOs; j++) {
			glBindBuffer(GL_ARRAY_BUFFER, VBOs[i][j]);
			glBufferData(GL_ARRAY_BUFFER, 3*sizes[j]*sizeof(float), t[i][j], GL_STATIC_DRAW);
			glEnableVertexAttribArray(j);
			glVertexAttribPointer(j, sizes[j], GL_FLOAT, GL_FALSE, 0, 0);
		}
		
	}
}

int
main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGBA);
glutInitWindowSize(512, 512);
glutInitContextVersion(4, 3);
glutInitContextProfile(GLUT_CORE_PROFILE);
glutCreateWindow(argv[0]);
if (glewInit()) {
cerr << "Unable to initialize GLEW ... exiting" << endl;
exit(EXIT_FAILURE);
}
init();
glutDisplayFunc(display);
glutMainLoop();
}
