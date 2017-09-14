//
// Created by heri on 9/14/17.
//

#include "../DDA.h"
#include <cmath>
#include <cstdio>


GLfloat DDA::round_up(GLfloat number) {
    return (GLfloat)floor(number + 0.5);
}

void DDA::draw() {
    GLfloat x = point1.x,
            y = point1.y;
    steps++;
    //printf(" X | Y\n");
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(10.0);
    glBegin(GL_POINTS);
        do{
            //printf("%0.1lf | %0.1lf\n",x, y);
            glVertex2d(round_up(x), round_up(y));
            if(gradient <= 1){
                x += 1.0;
                y += gradient;
            }else{
                y += 1.0;
                x += (1.0/gradient);
            }
            steps--;
        }while( steps );
    glEnd();
    glFlush();
}

DDA::DDA(Point a, Point b) {
        point1 = a;
        point2 = b;
        double dx=(b.x-a.x);
        double dy=(b.y-a.y);
        gradient = (GLfloat)(abs(b.y) - abs(a.y))/(GLfloat)(abs(b.x) - abs(a.x));
        steps=(abs(dx)>abs(dy))?(abs(dx)):(abs(dy));

}
