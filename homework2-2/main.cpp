#include <GL/glew.h>
#include <GL/freeglut.h>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "LoadShaders.h"

using namespace std;
int mode;
GLuint vboId1;
GLuint vboId2;
float xRot(0), yRot(0);
float VB[8][3]=
{
    {0,0,0},     //V0
    {0,1,0},     //V1
    {1,1,0},     //V2
    {1,0,0},     //V3
    {0,0,-1},     //V4
    {0,1,-1},     //V5
    {1,1,-1},     //V6
    {1,0,-1}     //V7
};
float VNB[8][3]=
{
    {-0.5,-0.5,0.5},     //V0
    {-0.5,0.5 ,0.5},     //V1
    { 0.5,0.5 ,0.5},     //V2
    { 0.5,-0.5,0.5},     //V3
    {-0.5,-0.5,-0.5},     //V4
    {-0.5,0.5 ,-0.5},     //V5
    {0.5 ,0.5 ,-0.5},     //V6
    {0.5 ,-0.5,-0.5}     //V7
};
float CB[8][3]=
{
   {0,0,0},       //T0
    {0,1,0},       //T1
    {1,1,0},       //T2
    {1,0,0},       //T3
    {0,0,1},       //T4
    {0,1,1},       //T5
    {1,1,1},       //T6
    {1,0,1}       //T7
};
int TB[12][3]=
{
    {0,3,1},     //T0
    {1,3,2},    //T1
    {5,1,2},     //T2
    {5,2,6},     //T3
    {4,5,6},     //T4
    {4,6,7},     //T5
    {0,4,7},     //T6
    {0,7,3},     //T7
    {5,4,0},    //T8
    {5,0,1},    //T9
    {2,3,7},   //T10
    {2,7,6}     //T11
};
float NB[12][3]=
{
    {0,0,1},       //T0
    {0,0,1},       //T1
    {0,1,0},       //T2
    {0,1,0},       //T3
    {0,0,-1},       //T4
    {0,0,-1},       //T5
    {0,-1,0},       //T6
    {0,-1,0},       //T7
    {-1,0,0},       //T8
    {-1,0,0},       //T9
    {1,0,0},       //T10
    {1,0,0}      //T11
};
void drawCubeIM()
{
    glBegin(GL_TRIANGLES);

    for(int i=0;i<12;i++)
    {
        glNormal3f(NB[i][0],
                   NB[i][1],
                   NB[i][2]
                   );
        glColor3f( CB[TB[i][0]][0],
                   CB[TB[i][0]][1],
                   CB[TB[i][0]][2]
                   );
        glVertex3f(VB[TB[i][0]][0],
                   VB[TB[i][0]][1],
                   VB[TB[i][0]][2]
                   );

        glColor3f(CB[TB[i][1]][0],
                   CB[TB[i][1]][1],
                   CB[TB[i][1]][2]
                   );
        glVertex3f(VB[TB[i][1]][0],
                   VB[TB[i][1]][1],
                   VB[TB[i][1]][2]
                   );

        glColor3f(CB[TB[i][2]][0],
                   CB[TB[i][2]][1],
                   CB[TB[i][2]][2]
                   );
        glVertex3f(VB[TB[i][2]][0],
                    VB[TB[i][2]][1],
                    VB[TB[i][2]][2]
                    );
    }
}
void drawCubeVA()
{
        glEnableClientState(GL_COLOR_ARRAY);
        glEnableClientState(GL_NORMAL_ARRAY);
        glEnableClientState(GL_VERTEX_ARRAY);

        glColorPointer(3, GL_FLOAT, 0,(void *)&CB[0][0]);
        glNormalPointer(GL_FLOAT, 0, (void *)&VNB[0][0]);
        glVertexPointer(3, GL_FLOAT, 0,(void *)&VB[0][0]);

        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT,(void *)&TB[0][0]);

        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_NORMAL_ARRAY);
        glDisableClientState(GL_COLOR_ARRAY);
}
void drawCube()
{
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);


    glGenBuffers(1, &vboId1);
    glBindBuffer(GL_ARRAY_BUFFER, vboId1);
    glBufferData(GL_ARRAY_BUFFER, sizeof(VB)+sizeof(NB)+sizeof(CB), 0, GL_STATIC_DRAW);

    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(VB), VB);// vertex data first
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(VB), sizeof(NB), NB);// then normal
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(VB)+sizeof(NB), sizeof(CB), CB);// color at last


    glGenBuffers(1, &vboId2);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboId2);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(TB), TB, GL_STATIC_DRAW);

    glVertexPointer(3, GL_FLOAT, 0, 0);
    glNormalPointer(GL_FLOAT, 0, (void*)(sizeof(VB)));
    glColorPointer(3, GL_FLOAT, 0, (void*)(sizeof(VB)+sizeof(NB)));

    glBindBuffer(GL_ARRAY_BUFFER, vboId1);// per vertex data
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboId2);// index data
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);// draw the elements with the indices

    glDisableClientState(GL_VERTEX_ARRAY);// deactivate vertex array
    glDisableClientState(GL_COLOR_ARRAY);// deactivate color array
    glDisableClientState(GL_NORMAL_ARRAY);// deactivate color array

    glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);
    glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, 0);

    glDeleteBuffersARB(1, &vboId1);
    glDeleteBuffersARB(1, &vboId2);

}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(yRot, 0, 1, 0);
    glRotatef(xRot, 1, 0, 0);
    glPushMatrix();


    switch(mode)
    {
        case 0:drawCubeIM();break;
        case 1:drawCubeVA();break;
        case 2:drawCube();break;
    }

    glPopMatrix();
    glEnd();
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
        case 'v':mode = 0;
        case 'i':mode = 1;
        case 'b':mode = 2;
        case '+':mode = (mode+1)%3; break;
        case '-':mode = (mode-1)%3; break;
    }
    glutPostRedisplay();
}

void idle()
{
    xRot += 0.5;
    yRot -= 0.5;
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


    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glutMainLoop();
    return 0;
}
