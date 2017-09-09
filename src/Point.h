//
// Created by heri on 9/9/17.
//
#include <GL/glut.h>
#include <cstdio>

#ifndef OPENGL_POINT_H
#define OPENGL_POINT_H

struct Position{
    GLfloat x, y;
};

struct Color{
    GLfloat red, green, blue;
};

class Point {

    Position *position;

    Color *color;

    GLfloat psize;

public:
    void draw_point();
    static void draw_shape(Point points[], Color *_color, GLfloat _size);
    Point(Position *_position, Color *_color, GLfloat _size);
    Point(Position *_position);
};


#endif //OPENGL_POINT_H
