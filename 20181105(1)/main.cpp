#include <iostream>
#include <GL/freeglut.h>

using namespace std;
float xRot(0), yRot(0);
float W,H;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluPerspective(45.0,    //光圈
                   W/H,
                   0.01,    //遠近
                   1000
                   );

 glMatrixMode(GL_MODELVIEW);

    gluLookAt(0,0,5,     //攝影機的位置
              0,0,0,    //攝影機看的方向
              0,1,0);   //攝影機方向  up and down

    glRotatef(yRot, 0, 1, 0);   //旋轉
    glRotatef(xRot, 1, 0, 0);

    glPushMatrix();
    glColor3f(1,0,0);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,1,0);
    glTranslated(0,1,0);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslated(1,0,0);
    glutSolidCube(1.0);
    glPopMatrix();

    glutSwapBuffers();
}
void reshape(int w, int h)
{
    glViewport(0,0, w ,h);
    W=w; H=h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.5,1.5,-1.5,1.5,-1.5,1.5);
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
    glutCreateWindow("CUBE");
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);

    glutMainLoop();
    return 0;
}
