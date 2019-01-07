#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED
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

void drawCubeVA()
{
        // Classic Client-Side Vertex Array Method
        glEnableClientState(GL_COLOR_ARRAY);
        glEnableClientState(GL_NORMAL_ARRAY);
        glEnableClientState(GL_VERTEX_ARRAY);
        // before draw, specify vertex arrays
        glColorPointer(3, GL_FLOAT, 0,(void *)&CB[0][0]);
        glNormalPointer(GL_FLOAT, 0, (void *)&VNB[0][0]);
        glVertexPointer(3, GL_FLOAT, 0,(void *)&VB[0][0]);

        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT,(void *)&TB[0][0]);
        glDisableClientState(GL_VERTEX_ARRAY);
        // disable vertex arrays
         glDisableClientState(GL_NORMAL_ARRAY);
         glDisableClientState(GL_COLOR_ARRAY);
}

//Classic Client-Side Vertex Array Method

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



#endif // TEXT_H_INCLUDED
