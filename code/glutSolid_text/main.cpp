#include <iostream>
#include <GL/freeglut.h>

using namespace std;
float xRot(0), yRot(0);

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(yRot, 0, 1, 0);
    glRotatef(xRot, 1, 0, 0);
    glColor3f(1,1,1);
    //glutSolidCube(1.0);
    //glutSolidCone(1,1,25,25);
    //glutSolidCylinder(1,1,25,25);
   // glutSolidDodecahedron();
   //glutSolidIcosahedron();
   //glutSolidOctahedron();
   //glutSolidRhombicDodecahedron();
    //glutSolidTeacup(1);
    //glutSolidSphere(1,25,25);
    glutSolidTeaspoon(1.0);
    //glutSolidTetrahedron();
    //glutSolidTorus(1,1,5,5);
    glutSwapBuffers();
}
void reshape(int w, int h)
{
    glViewport(0,0, w ,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.5,1.5,-1.5,1.5,-1.5,1.5);
}

void key(unsigned char k, int x, int y)
{
    switch(k)
    {
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
    xRot += 1.0;
    yRot -= 1.0;
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(512,512);
    glutCreateWindow("Hello FreeGLUT");
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glutMainLoop();
    return 0;
}
