#include <iostream>
#include <GL/freeglut.h>

using namespace std;
float xRot(0), yRot(0);


void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(0.6,0.6,0.6); //灰色

    glPushMatrix();

    glRotatef(45.0,0,1,0);
    glRotatef(25.0,1,0,0);
    glutSolidCube(1.0);
    glPopMatrix();
    glEnd();
    glutSwapBuffers();
}
void reshape(int w, int h)
{
    //Device Transform
    glViewport(0,0, w ,h);
    //projection Transform
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.2,1.2,-1.2,1.2,-1.2,1.2);
}

void key(unsigned char k, int x, int y)
{
    switch(k)
    {
        case 'p':case 'P':glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);break;
        case 'l':case 'L':glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);break;
        case 'f':case 'F':glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);break;

        case 27:
        case 'q':
        case 'Q':exit(0);break;
        case 'w':xRot += 5.0; break;
        case 's':xRot -= 5.0; break;
        case 'a':yRot += 5.0; break;
        case 'd':yRot -= 5.0; break;
    }
    glutPostRedisplay();
}

void idle()
{
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(700,700);
    glutCreateWindow("CUBE");

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_CULL_FACE);
    glPointSize(10.0);  //點的大小

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glutMainLoop();
    return 0;
}
