#include <iostream>
#include <cmath>
#include <GL/freeglut.h>

using namespace std;
float xRot(0), yRot(0);
float r(1.0), delta(3.141592654*5.0/180.0);

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(0,0,0);
    glPushMatrix();
    glRotatef(yRot, 0, 1, 0);
    glRotatef(xRot, 1, 0, 0);

    for(float phi = 0.0; phi<3.141592654; phi+=delta)
    {
        glBegin(GL_TRIANGLE_STRIP);
        for(float theta = 0.0; theta<=2*3.141592654; theta+=delta)
        {
            glNormal3f(
                        r*sin(phi)*cos(theta),
                        r*cos(phi),
                        -r*sin(phi)*sin(theta)
                      );
            glColor3f(
                        r*sin(phi)*cos(theta),
                        r*cos(phi),
                        -r*sin(phi)*sin(theta)
                     );
            glVertex3f(
                        r*sin(phi)*cos(theta),
                        r*cos(phi),
                        -r*sin(phi)*sin(theta)
                   );
            glNormal3f(
                        r*sin(phi+delta)*cos(theta),
                        r*cos(phi+delta),
                        -r*sin(phi+delta)*sin(theta)
                   );
            glColor3f(
                        r*sin(phi+delta)*cos(theta),
                        r*cos(phi+delta),
                        -r*sin(phi+delta)*sin(theta)
                     );
            glVertex3f(
                        r*sin(phi+delta)*cos(theta),
                        r*cos(phi+delta),
                        -r*sin(phi+delta)*sin(theta)
                      );
        }
    }
    glEnd();
    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    //Device Transform
    glViewport(0,0, w ,h);
    //projection Transform
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.5,1.5,-1.5,1.5,-1.5,1.5);
}

void key(unsigned char k, int x, int y)
{
    switch(k)
    {
        case 'p':case 'P':glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);break;
        case 'l':case 'L':glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);break;
        case 'f':case 'F':glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);break;
    }
    glutPostRedisplay();
}

void idle()
{
    xRot += 1.0;
    yRot -= 1.0;
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutCreateWindow("CUBE");

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_CULL_FACE);
    glPointSize(3.0);       //點的大小

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glutMainLoop();
    return 0;
}
