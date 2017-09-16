//
// Created by heri on 9/14/17.
//

#include "../DDA.h"
#include <cmath>


GLfloat DDA::round_up(GLfloat number) {
    // rounds up any given decimal point passed
    return (GLfloat)floor(number + 0.5);
}


void DDA::draw() {
    // initialize the first cordinates
    // to be posted to the first point
    GLfloat x = point1.x,
            y = point1.y;
    // add one to the step otherwise
    // the last point wont be plotted
    steps++;
    //printf(" X | Y\n");
    glColor3f(0.0, 1.0, 0.0);
    glPointSize(10.0);
    glBegin(GL_POINTS);
        do{
            //printf("%0.1lf | %0.1lf\n",x, y);

            // plot the specific point in the loop
            glVertex2d(round_up(x), round_up(y));
            glColor3f(1.0, 0.0, 0.0);
            // check the value of gradient in oders
            // to use an accuracte formula
            if(gradient <= 1){
                x += 1.0;
                y += gradient;
            }else{
                y += 1.0;
                x += (1.0/gradient);
            }

            // decrese step by one
            steps--;
            // loop until the steps is zero
        }while( steps );
    glEnd();
}


DDA::DDA(Point a, Point b) {
        point1 = a;
        point2 = b;
        double dx=(b.x-a.x);
        double dy=(b.y-a.y);
        gradient = (GLfloat)(abs(b.y) - abs(a.y))/(GLfloat)(abs(b.x) - abs(a.x));
        // calculates the number on steps required to execute when in the loop
        // And assigns the biggest value between dy and dx, removes the decimal place and negatives
        steps=(abs(dx)>abs(dy))?(abs(dx)):(abs(dy));
}
