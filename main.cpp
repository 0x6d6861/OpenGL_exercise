#include <GL/glut.h>
#include <cstdio>
#include "src/Point.h"


void init () {
    glClearColor (1.0,1.0,1.0,1.0);
    gluOrtho2D (-1.5,1.5,-1.5,1.5);
}

void shapepoint (){

    GLfloat psize = 10.0;

    Color pColors[6][3] = {
            {0.0, 0.000, 1.000},
            {0.647, 0.165, 0.165},
            {0.0, 1.000, 1.000},
            {0.0, 1.0, 0.000},
            {1.0, 0.000, 1.0},
            {1.0, 0.000, 0.000}
    };
    Position pCordinate[6][2] = {
            {0,-1},
            {-0.87,-0.5},
            {-0.87,0.5},
            {0.0,1.0},
            {0.87,0.5},
            {0.87,-0.5}
    };

    glClear (GL_COLOR_BUFFER_BIT);

    for(int i = 0; i < 6; ++i){ // TODO: Point by the size of point
        Point myPoint = Point(pCordinate[i], pColors[i], psize);
        myPoint.draw_point();
    }
    glFlush();//enables fast execution of statements

}

int main (int argc , char** argv)
{
    glutInit (&argc, argv);
    glutInitWindowPosition (50,100);
    glutInitWindowSize(500,500);
    glutCreateWindow ("Shape Point");

    init();
    glutDisplayFunc(shapepoint);
    glutMainLoop();
    return 1;
}
