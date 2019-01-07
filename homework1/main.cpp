#include <iostream>
#include <GL/freeglut.h>

void reshape(int width, int height)
 {
    const float ar = (float) width / (float) height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(120.0, ar, 0.1, 1000);
    gluLookAt(5, 0, 0, 1, 0, 0, 0, 1, 0);
}

void display()
{

    //glClearColor(1,1,1,0);  //改成白底

    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    glEnable(GL_LIGHTING);
    glColor3d(1,0,0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    // X Axis    紅
    glColor3f(1,0,0);
    glVertex3f(-10, 0, 0);
    glVertex3f(-10, 0, 0);
    // Y Axis    綠
    glColor3f(0,1,0);
    glVertex3f(0, -10, 0);
    glVertex3f(0, 10, 0);
    // Z Axis    藍
    glColor3f(0,0,1);
    glVertex3f(0, 0, -10);
    glVertex3f(0, 0, 10);
    glEnd();

    //右上
    glPushMatrix();
    glTranslated(0, 1, -2);
    glRotated(90,0,1,0);
    glColor3f(0, 0, 1);
    glBegin(GL_TRIANGLES);
    glVertex3f(0,1,0);
    glVertex3f(-1,0,0);
    glVertex3f(1,0,0);
    glEnd();
    //左上
    glPopMatrix();
    glPushMatrix();
    glTranslated(0, 1, 2);
    glRotated(90,0,1,0);
    glColor3f(0, 1, 0);
    glBegin(GL_TRIANGLES);
    glVertex3f(0,1,0);
    glVertex3f(-1,0,0);
    glVertex3f(1,0,0);
    glEnd();
    //左下
    glPopMatrix();
    glPushMatrix();
    glTranslated(0, -3, 2);
    glRotated(90,0,1,0);
    glColor3f(1, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex3f(0,1,0);
    glVertex3f(-1,0,0);
    glVertex3f(1,0,0);
    glEnd();
    //右下
    glPopMatrix();
    glPushMatrix();
    glTranslated(0, -3, -2);
    glRotated(90,0,1,0);
    glBegin(GL_TRIANGLES);
    glColor3f(1, 0, 0);
    glVertex3f(0,1,0);
    glColor3f(0, 1, 0);
    glVertex3f(-1,0,0);
    glColor3f(0, 0, 1);
    glVertex3f(1,0,0);
    glEnd();

    glPopMatrix();
    glutSwapBuffers();
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

    glutMainLoop();
    return 0;
}
