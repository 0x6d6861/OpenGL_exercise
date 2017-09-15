#include <GL/glut.h>
#include "src/DDA.h"
#include <cstdio>
#include <iostream>

using namespace std;

void draw_axis(int min_x, int max_x, int min_y, int max_y);

void init () {

    gluOrtho2D (-15,65,-15,65);
    glClearColor(0,0,0,0.2);
    glClear(GL_COLOR_BUFFER_BIT);

    //glColor3f(1.0,0.0,0.0);

}



void shapepoint (){

    char comma;

    // Initialiase the two points to be used
    Point a{}, b{};

    // Assigns coordinates to the specfic points
    a = {5,5};
    b = {30,40};

    draw_axis(-10, 60, -10, 60);

  /*
   cout << "Please enter the first point int the format x,y: ";
   cin >> a.x >> comma >> a.y;

    cout << "Please enter the second point int the format x,y: ";
    cin >> b.x >> comma >> b.y;

    cout << "Ploting line from (" << a.x << "," << a.y << ") to (" << b.x << "," << b.y << ")\n";

    */


    // Pass the the two points to the DDA object
    DDA dda = DDA(a, b);

    dda.draw();
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


void draw_axis(int min_x, int max_x, int min_y, int max_y){
    // The x-axis
    glLineWidth(.7);
    glColor3f(0.282, 0.239, 0.545);
    glBegin(GL_LINES);
        glVertex3f(min_x, 0.0, 0.0);
        glVertex3f(max_x, 0, 0);
    glEnd();

    // The y-axis
    glLineWidth(1.0);
    glColor3f(0.282, 0.239, 0.545);
    glBegin(GL_LINES);
        glVertex3f(0, min_y, 0.0);
        glVertex3f(0, max_y, 0);
    glEnd();


    // x-axis
    for(int i = (min_x + 4); i <= (max_x - 10); i+=2){

        // x-axis
        glColor3f(1.0, 1.0, 0.0);
        glBegin(GL_LINES);
            glVertex3f(i, -.5, 0.0);
            glVertex3f(i, .5, 0);
        glEnd();


        if(i > 0) {
            glColor3f(0.1, 0.1, 0.1);
            glBegin(GL_LINES);
            glVertex3f(i, 2, 0.0);
            glVertex3f(i, (max_y - 10), 0);
            glEnd();

        }

    }

    // y-axis
    for(int i = (min_y + 4); i <= (max_y - 10); i+=2){
        // y-axis
        glColor3f(1.0, 1.0, 0.0);
        glBegin(GL_LINES);
        glVertex3f(-0.5, i, 0.0);
        glVertex3f(0.5, i, 0);
        glEnd();

        if(i > 0) {
            glColor3f(0.1, 0.1, 0.1);
            glBegin(GL_LINES);
            glVertex3f(2, i, 0.0);
            glVertex3f((max_x - 10), i, 0);
            glEnd();
        }

    }

}