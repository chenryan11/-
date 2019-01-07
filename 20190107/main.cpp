#include <iostream>
#include <GL/freeglut.h>

using namespace std;

class point3D
{
public:
   float x, y, z;
    point3D(double ix=0.0, double iy=0.0, double iz=0.0)
    {
        x=ix; y=iy; z=iz;
    };
    point3D(const point3D & ip)
    {
        x=ip.x; y=ip.y; z=ip.z;
    }
    friend point3D operator*(double l, const point3D &r)
    {
        return(point3D(l*r.x, l*r.y, l*r.z));
    }
    friend point3D operator*(const point3D &l, double r)
    {
        return(point3D(l.x*r, l.y*r, l.z*r));
    }
    friend point3D operator+(const point3D &l, const point3D &r)
    {
        return(point3D(l.x+r.x, l.y+r.y, l.z+r.z));
    }
    friend point3D operator-(const point3D &l, const point3D &r)
    {
        return(point3D(l.x-r.x, l.y-r.y, l.z-r.z));
    }
};

point3D p(0, 1, 0), q(1, -1, 0), r(-1, -1, 0);

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(1,0,0);
    glPushMatrix();

    glColor3f(0.8, 0.6, 0.5);

    glBegin(GL_POINTS);
    for (float a=0.0; a<=1.0; a+=0.001)
    {
        for (float b=0.0; b<=1.0; b+=0.001)
        {
            point3D v;
            v=b*a*p+b*(1-a)*q+(1-b)*r;
            glColor3f(a*b, b*(1-a), 1-b);
            glVertex3f(v.x, v.y, v.z);
        }
    }
    glEnd();
    glutSwapBuffers();
}

void reshape(int iw, int ih)
{
    glViewport(0,0, iw, ih);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2, 2, -2, 2);
}

void initGL()
{
    glColorMaterial(GL_FRONT_AND_BACK,
    GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
}

int main(int argc, char *argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(512,512);
    glutCreateWindow("Triangle");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}
