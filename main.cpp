#include<GL/glut.h>
void Init(void)
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void simpleline(void)
{
    glClear(GL_COLOR_BUFFER_BIT);


    glColor3f(0.0,0.4,0.2);
    glBegin(GL_POLYGON);
    glVertex3f (0.1, 0.1, 0.0);
    glVertex3f (0.4, 0.1, 0.0);
    glVertex3f (0.4, 0.5, 0.0);
    glVertex3f (0.1, 0.5, 0.0);
    glEnd();

    // The door
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex3f (0.15, 0.1, 0.0);
    glVertex3f (0.25, 0.1, 0.0);
    glVertex3f (0.25, 0.3, 0.0);
    glVertex3f (0.15, 0.3, 0.0);
    glEnd();

    // The window on the front
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex3f (0.3, 0.3, 0.0);
    glVertex3f (0.35, 0.3, 0.0);
    glVertex3f (0.35, 0.45, 0.0);
    glVertex3f (0.3, 0.45, 0.0);
    glEnd();


    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex3f (0.10, 0.5, 0.0);
    glVertex3f (0.4, 0.5, 0.0);
    glVertex3f (0.25, 0.75, 0.0);
    glEnd();


    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex3f (0.4, 0.1, 0.0);
    glVertex3f (0.8, 0.4, 0.0);
    glVertex3f (0.8, 0.75, 0.0);
    glVertex3f (0.4, 0.5, 0.0);
    glEnd();

    glColor3f(0.4,0.0,0.4);
    glBegin(GL_POLYGON);
    glVertex3f (0.4, 0.5, 0.0);
    glVertex3f (0.8, 0.75, 0.0);
    glVertex3f (0.62, 0.93, 0.0);
    glVertex3f (0.25, 0.75, 0.0);
    glEnd();
    glFlush();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(640,480);
    glutCreateWindow("Drawing a house");
    Init();
    glutDisplayFunc(simpleline);
    glutMainLoop();
}