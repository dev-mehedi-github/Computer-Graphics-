#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void renderBitmapString(float x, float y, float z, void *font, char *string) {
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

void display() {
    glClearColor(0.8f, 0.8f, 0.8f,0.0f);//(1.0f, 1.0f, 1.0f, 0.0f); // // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

glBegin(GL_LINES);
 glColor3f(1.0f,0.0f,0.0f);
 glVertex2f(0.0f,1.0f);
 glVertex2f(0.0f,-1.0f);
 glVertex2f(-1.0f,0.0f);
 glVertex2f(1.0f,0.0f);
 glEnd();

 glBegin(GL_QUADS);
 glColor3f(0.15f,0.14f,0.76f);
 glVertex2f(0.1f,0.1f);
 glVertex2f(0.9f,0.1f);
 glVertex2f(0.9f,0.7f);
 glVertex2f(0.1f,0.7f);
 glEnd();

 glBegin(GL_QUADS);
 glColor3f(1.0f, 1.0f, 1.0f);
 glVertex2f(0.1f,0.1f);
 glVertex2f(0.1f,0.3f);
 glVertex2f(0.3f,0.3f);
 glVertex2f(0.3f,0.1f);
 glEnd();

 glBegin(GL_QUADS);
 glColor3f(1.0f, 1.0f, 1.0f);
 glVertex2f(0.5f,0.1f);
 glVertex2f(0.5f,0.3f);
 glVertex2f(0.9f,0.3f);
 glVertex2f(0.9f,0.1f);
 glEnd();

 glBegin(GL_QUADS);
 glColor3f(1.0f, 1.0f, 1.0f);
 glVertex2f(0.9f,0.5f);
 glVertex2f(0.9f,0.7f);
 glVertex2f(0.5f,0.7f);
 glVertex2f(0.5f,0.5f);
 glEnd();

 glBegin(GL_QUADS);
 glColor3f(1.0f, 1.0f, 1.0f);
 glVertex2f(0.3f,0.7f);
 glVertex2f(0.3f,0.5f);
 glVertex2f(0.1f,0.5f);
 glVertex2f(0.1f,0.7f);
 glEnd();

 //Georgia
 glBegin(GL_QUADS);
 glColor3f(1.0f, 0.0f, 0.0f);
 glVertex2f(0.1f,-0.1f);
 glVertex2f(0.1f,-0.7f);
 glVertex2f(0.9f,-0.7f);
 glVertex2f(0.9f,-0.1f);
 glEnd();

 glBegin(GL_QUADS);
 glColor3f(1.0f, 1.0f, 1.0f);
 glVertex2f(0.1f,-0.1f);
 glVertex2f(0.4f,-0.1f);
 glVertex2f(0.4f,-0.3f);
 glVertex2f(0.1f,-0.3f);
 glEnd();

 glLineWidth(3.5f);
 glBegin(GL_LINES);
 glColor3f(1.0f, 0.0f, 0.0f);
 glVertex2f(0.25f,-0.16f);
 glVertex2f(0.25f,-0.24f);
 glEnd();

 glLineWidth(3.5f);
 glBegin(GL_LINES);
 glColor3f(1.0f, 0.0f, 0.0f);
 glVertex2f(0.22f,-0.2f);
 glVertex2f(0.28f,-0.2f);
 glEnd();

  glBegin(GL_QUADS);
 glColor3f(1.0f, 1.0f, 1.0f);
 glVertex2f(0.6f,-0.1f);
 glVertex2f(0.9f,-0.1f);
 glVertex2f(0.9f,-0.3f);
 glVertex2f(0.6f,-0.3f);
 glEnd();

 glLineWidth(3.5f);
 glBegin(GL_LINES);
 glColor3f(1.0f, 0.0f, 0.0f);
 glVertex2f(0.75f,-0.16f);
 glVertex2f(0.75f,-0.24f);
 glEnd();

 glLineWidth(3.5f);
 glBegin(GL_LINES);
 glColor3f(1.0f, 0.0f, 0.0f);
 glVertex2f(0.72f,-0.2f);
 glVertex2f(0.78f,-0.2f);
 glEnd();

 glBegin(GL_QUADS);
 glColor3f(1.0f, 1.0f, 1.0f);
 glVertex2f(0.1f,-0.5f);
 glVertex2f(0.4f,-0.5f);
 glVertex2f(0.4f,-0.7f);
 glVertex2f(0.1f,-0.7f);
 glEnd();

 glLineWidth(3.5f);
 glBegin(GL_LINES);
 glColor3f(1.0f, 0.0f, 0.0f);
 glVertex2f(0.25f,-0.56f);
 glVertex2f(0.25f,-0.64f);
 glEnd();

 glLineWidth(3.5f);
 glBegin(GL_LINES);
 glColor3f(1.0f, 0.0f, 0.0f);
 glVertex2f(0.22f,-0.6f);
 glVertex2f(0.28f,-0.6f);
 glEnd();

  glBegin(GL_QUADS);
 glColor3f(1.0f, 1.0f, 1.0f);
 glVertex2f(0.6f,-0.5f);
 glVertex2f(0.9f,-0.5f);
 glVertex2f(0.9f,-0.7f);
 glVertex2f(0.6f,-0.7f);
 glEnd();

 glLineWidth(3.5f);
 glBegin(GL_LINES);
 glColor3f(1.0f, 0.0f, 0.0f);
 glVertex2f(0.75f,-0.56f);
 glVertex2f(0.75f,-0.64f);
 glEnd();

 glLineWidth(3.5f);
 glBegin(GL_LINES);
 glColor3f(1.0f, 0.0f, 0.0f);
 glVertex2f(0.72f,-0.6f);
 glVertex2f(0.78f,-0.6f);
 glEnd();

 //Morocco
 glBegin(GL_QUADS);
 glColor3f(0.757f, 0.153f, 0.176f);
 glVertex2f(-0.1f,0.1f);
 glVertex2f(-0.9f,0.1f);
 glVertex2f(-0.9f,0.7f);
 glVertex2f(-0.1f,0.7f);
 glEnd();

 glLineWidth(3.5f);
 glBegin(GL_LINE_LOOP);
 glColor3f(0.0f, 0.384f, 0.2f);
 glVertex2f(-0.5f,0.5f);
 glVertex2f(-0.54f,0.42f);
 glVertex2f(-0.66f,0.42f);
 glVertex2f(-0.56f,0.38f);
 glVertex2f(-0.6f,0.3f);
 glVertex2f(-0.5f,0.34f);
 glVertex2f(-0.4f,0.3f);
 glVertex2f(-0.44f,0.38f);
 glVertex2f(-0.34f,0.42f);
 glVertex2f(-0.46f,0.42f);
 glVertex2f(-0.5f,0.5f);

 glVertex2f(-0.54f,0.42f);
 glVertex2f(-0.56f,0.38f);
 glVertex2f(-0.5f,0.34f);
 glVertex2f(-0.44f,0.38f);
 glVertex2f(-0.46f,0.42f);
 glVertex2f(-0.54f,0.42f);
 glEnd();

 //Somalia
 glBegin(GL_QUADS);
 glColor3f(0.255f, 0.537f, 0.867f);
 glVertex2f(-0.1f,-0.1f);
 glVertex2f(-0.9f,-0.1f);
 glVertex2f(-0.9f,-0.7f);
 glVertex2f(-0.1f,-0.7f);
 glEnd();

 glBegin(GL_POLYGON);
 glColor3f(1.0f, 1.0f, 1.0f);
 //glVertex2f(-0.5f,-0.3f);
 glVertex2f(-0.54f,-0.38f);
 glVertex2f(-0.66f,-0.38f);
 glVertex2f(-0.56f,-0.43f);
 glVertex2f(-0.6f,-0.5f);
 glVertex2f(-0.5f,-0.46f);
 glVertex2f(-0.4f,-0.5f);
 glVertex2f(-0.44f,-0.43f);
 glVertex2f(-0.34f,-0.38f);
 glVertex2f(-0.46f,-0.38f);
 glVertex2f(-0.5f,-0.3f);
 glEnd();


 glFlush(); // Render now
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480); // Set the window's initial width & height
    glutInitWindowPosition(80, 50);  // Set the window's initial position according to the monitor
    glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}
