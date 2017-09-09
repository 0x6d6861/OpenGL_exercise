//
// Created by heri on 9/9/17.
//

#include "../Point.h"

void Point::draw_point() {
    glPointSize(psize);
    glColor3f(color->red, color->green, color->blue);
    glBegin(GL_POINTS);
        glVertex2f(position->x, position->y);
    glEnd();
}

Point::Point(Position *_position, Color *_color, GLfloat _size) {
    position = _position;
    color = _color;
    psize = _size;
}

Point::Point(Position *_position) {
    position = _position;
}

void Point::draw_shape(Point *points, Color *_color, GLfloat _size){
    glColor3b(_color->red, _color->green, _color->blue);
    glBegin(GL_POLYGON);
        for(int i=0; i <= sizeof(points); ++i){
            glVertex2d(points[i].position->x, points[i].position->y);
        }
    glEnd();
}

