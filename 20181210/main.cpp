#include <iostream>
#include <GL/freeglut.h>

using namespace std;
float xRot(0), yRot(0);
int w,h;

void reshape(int iw, int ih)
{
    w=iw;h=ih;
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
//1 紅 左下
    glViewport(0,0,w/2,h/2);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1,1,-1,1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glColor3f(1.0f,0.0f,0.0f);
    glRotated(45,0,1,0);
    glutSolidTeapot(0.5);
    glPopMatrix();
//2 綠 左上
    glViewport(0,h/2,w/2,h/2);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1,1,-1,1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glColor3f(0.0f,1.0f,0.0f);
    glRotated(45,1,0,0);
    glutSolidTeapot(0.5);
    glPopMatrix();
    glEnd();
//3 藍 右下
    glViewport(w/2,0,w/2,h/2);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(-1,1,-1,1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glColor3f(0.0f,0.0f,1.0f);
    glRotated(90,1,0,0);
    glutSolidTeapot(0.5);
    glPopMatrix();
//4 黃 右上
    glViewport(w/2,h/2,w/2,h/2);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(-1,1,-1,1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glColor3f(1.0f,1.0f,0.0f);
    glRotated(45,1,1,0);
    glutSolidTeapot(0.5);
    glPopMatrix();

    glutSwapBuffers();
}
int main(int argc, char *argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(700,700);
    glutCreateWindow("Hello FreeGLUT");
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}
