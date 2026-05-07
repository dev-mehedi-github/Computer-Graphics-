#include<cstdio>
#include <GL/gl.h>
#include <GL/glut.h>

void init(){
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  };

void display(){

    glBegin(GL_QUADS);
    glColor3ub(174, 225, 230);
    glVertex2f(-1.0f, -0.1f);
    glVertex2f(1.0f, -0.1f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(34, 139, 34);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(-1.0f, 0.1f);
    glVertex2f(1.0f, 0.1f);
    glVertex2f(1.0f, -1.0f);
    glEnd();

    glFlush();

};

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(1200, 600);
   glutInitWindowPosition(80, 50);
   glutCreateWindow(" Performance");
   glutDisplayFunc(display);
   init();
   glutMainLoop();
   return 0;
}
