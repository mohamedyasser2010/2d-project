#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


#include <stdlib.h>
#include <math.h>
#include <windows.h>

void display();
void reshape(int w,int h);
void timer(int);
void init(){
    glClearColor(0.0,0.67,1.0,1.0);
}

int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(200,0);
    glutInitWindowSize(1200,800);

    glutCreateWindow("20100806 - 20102447");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0,timer,0);
    init();

    glutMainLoop();
}
float step=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glLineWidth(1.0);

    // black GROUND
    glColor3f(0, 0, 0);
    glRecti(100,-150,-100,-90);

//house
glBegin(GL_QUADS);
glColor3f(1, 1, 1);
 glVertex2f(-20, -100);
    glVertex2f(-20, -50);
    glVertex2f(10, -50);
        glVertex2f(10, -100);
        glEnd();
//door
glBegin(GL_QUADS);
glColor3f(0.36, 0.25, 0.20);
 glVertex2f(-10, -100);
    glVertex2f(-10, -75);
    glVertex2f(5, -75);
        glVertex2f(5, -100);
        glEnd();

//housetop
    glBegin(GL_TRIANGLES);
glColor3f(0, 0, 0);
 glVertex2f(-20, -50);
    glVertex2f(10, -50);
    glVertex2f(-5, -25);
    glEnd();

    //Sun
    glColor3f(1, 0.5, 0);
    glBegin(GL_POLYGON);
    double r = 25;
    glVertex2f(100, 150);
    for(double i = 180; i <= 270; i++){
        double angle = i * 3.14/ 180;
        glVertex2f(r * cos(angle) + 100, 2.2 * r * sin(angle)+150);
    }
    glEnd();

    //Sun Rays Animation


    glColor3f(1, 0.5, 0);

    glLineWidth(3.5);

    glBegin(GL_LINE_STRIP);
    glVertex2f(75, 135);
    glVertex2f(75 - step, 135 - step);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(77, 125);
    glVertex2f(77 - step, 125 - step * 1.25);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(74, 145);
    glVertex2f(74 - step * 1.1, 145 - step * 0.9);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(79, 117);
    glVertex2f(79 - step * 1.0, 117 - step*1.5);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(82, 108);
    glVertex2f(82 - step * 1.0, 108 - step*1.7);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(86, 101.5);
    glVertex2f(86 - step * 1.0, 101.5 - step*1.9);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(90, 96);
    glVertex2f(90 - step * 1.0, 96 - step*2.1);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(94, 93.5);
    glVertex2f(94 - step * 1.0, 93.5 - step*2.4);
    glEnd();

    glFlush();
}

void reshape(int w,int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100,100,-150,150, 10, -10);
    glMatrixMode(GL_MODELVIEW);
}
void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);
	step+=0.15;
    if(step > 8) step = 0;

}
