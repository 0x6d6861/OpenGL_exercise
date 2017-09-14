#include <GL/glut.h>
#include <cstdio>
#include "src/DDA.h"
#include <cstring>


void init () {
    glClearColor (1.0,1.0,1.0,1.0);
    gluOrtho2D (0,50,0,50);
    glColor3f(0.0,0.0,0.0);
}



void shapepoint (){

    Point a{}, b{};
    a = {2,3};
    b = {40,30};


    DDA dda = DDA(a, b);

    dda.draw();
    //glFlush();//enables fast execution of statements

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
