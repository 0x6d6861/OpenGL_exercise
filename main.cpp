#include <GL/glut.h>
#include "src/DDA.h"
#include <cstdio>
#include <iostream>

using namespace std;

void init () {
    glClearColor (1.0,1.0,1.0,1.0);
    gluOrtho2D (0,50,0,50);
    glColor3f(1.0,0.0,0.0);
}



void shapepoint (){

    char comma;

    // Initialiase the two points to be used
    Point a{}, b{};

    // Assigns coordinates to the specfic points
    //a = {3,3};
    //b = {40,30};

    cout << "Please enter the first point int the format x,y: ";
    cin >> a.x >> comma >> a.y;

    cout << "Please enter the second point int the format x,y: ";
    cin >> b.x >> comma >> b.y;

    cout << "Ploting line from (" << a.x << "," << a.y << ") to (" << b.x << "," << b.y << ")\n";

    // Pass the the two points to the DDA object
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
