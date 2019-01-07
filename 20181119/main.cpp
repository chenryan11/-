#include <iostream>
#include <GL/freeglut.h>

using namespace std;

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

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotatef(yRot, 0, 1, 0);
    glRotatef(xRot, 1, 0, 0);
    glColor3f(1,0,0);

    glPushMatrix();

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
    glPopMatrix();
    glEnd();
    glutSwapBuffers();
}
void reshape(int w, int h)
{
    glViewport(0,0, w ,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.2,1.2,-1.2,1.2,-1.2,1.2);
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
    glutInitWindowSize(700,700);
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
