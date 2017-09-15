//
// Created by heri on 9/14/17.
//

#ifndef OPENGL_DDA_H
#define OPENGL_DDA_H
#include "GL/glut.h"

// struct definition for a Point
struct Point{
    GLfloat x, y;
};

class DDA {

private:
    Point point1, point2;
    GLfloat gradient;
    GLint steps;
    GLfloat round_up(GLfloat number);

public:
    void draw();
    // constructor
    DDA(Point a, Point b);

};


#endif //OPENGL_DDA_H
