#include <GL/glut.h>
#include <cstdio>

struct Point {
    GLint x, y;
};

void bresenham(Point a, Point b);
void draw_axis(int min_x, int max_x, int min_y, int max_y);

void init () {
    gluOrtho2D (-15,65,-15,65);
    glClearColor(0.0f,0.0f,0.0f,0.2f);
    glClear(GL_COLOR_BUFFER_BIT);
}



void shapepoint (){

    Point point1, point2;

    point1.x = 4;
    point1.y = 2;

    point2.x = 10;
    point2.y = 6;


    draw_axis(-10, 60, -10, 60);

    bresenham( point1, point2);

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


void bresenham(Point a, Point b){
    GLint x = a.x;
    GLint y = a.y;
    GLint dx = b.x - a.x;
    GLint dy = b.y - a.y;
    GLfloat m = GLfloat(dy) / GLfloat(dx);
    GLint steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);
    steps++;
    GLint Pk = (m > 1) ? 2*dx - dy : 2*dy - dx;
    glColor3f(0.0, 1.0, 0.0);
    glPointSize(10.0);
    glBegin(GL_POINTS);
        do{
            printf("%i | %i\n",x, y);
            glVertex2d(x, y); // Plots the first point
            if(Pk > 0){
                x += 1;
                y += 1;
                Pk += (m > 1) ? 2*dx - 2*dy : 2*dy - 2*dx;
            }else{
                x += (m > 1) ? 0 : 1;
                y += (m > 1) ? 1 : 0;
                Pk += (m > 1) ? 2*dx  : 2*dy;
            }
            --steps;
        }while(steps);
    glEnd();
    glFlush();

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
        glVertex3f(-0.5f, i, 0.0f);
        glVertex3f(0.5f, i, 0.0f);
        glEnd();

        if(i > 0) {
            glColor3f(0.1f, 0.1f, 0.1f);
            glBegin(GL_LINES);
            glVertex3f(2, i, 0.0f);
            glVertex3f((max_x - 10), i, 0.0f);
            glEnd();
        }

    }
    glFlush();

}
