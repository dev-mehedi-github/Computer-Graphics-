#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include<math.h>
# define PI           3.14159265358979323846

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

void drawTeaTree() {
    // bottom
    glColor3f(0.1f, 0.05f, 0.0f);
    glLineWidth(5.0f);
    glBegin(GL_LINE_STRIP);
        glVertex2f(0.0f,0.0f);
        glVertex2f(0.0f,-0.1f);
        glVertex2f(-0.05f,0.0f);
        glVertex2f(0.05f,0.0f);
        glVertex2f(0.0f,-0.1f);

    glEnd();

    // Upper Body
    glColor3f(0.0f, 0.15f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.05f,0.0f);
    glVertex2f(-0.05f,0.0f);
    glVertex2f(-0.15f,0.05f);
    glVertex2f(-0.13f,0.12f);
    glVertex2f(-0.1f,0.15f);
    glVertex2f(0.1f,0.15f);
    glVertex2f(0.13f,0.12f);
    glVertex2f(0.15f,0.05f);
    glEnd();

    //Border
    glLineWidth(2.5f);
    glColor3f(0.0f, 0.4f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.05f, 0.0f);
    glVertex2f(-0.05f,0.0f);
    glVertex2f(-0.15f,0.05f);
    glVertex2f(-0.13f,0.12f);
    glVertex2f(-0.1f,0.15f);
    glVertex2f(0.1f,0.15f);
    glVertex2f(0.13f,0.12f);
    glVertex2f(0.15f,0.05f);
    glEnd();


    /*
   // upper
    glBegin(GL_TRIANGLE_FAN);

        glVertex2f(0.0f, 0.0f);
        glVertex2f(-0.1f, -0.05f);
        glVertex2f(-0.08f, 0.02f);
        glVertex2f(-0.05f, 0.05f);
        glVertex2f( 0.0f,  0.07f);
        glVertex2f( 0.05f, 0.05f);
        glVertex2f( 0.08f, 0.02f);
        glVertex2f( 0.1f, -0.05f);
        glVertex2f( 0.05f, -0.07f);
        glVertex2f(-0.05f, -0.07f);
        glVertex2f(-0.1f, -0.05f);
    glEnd();

    // border
    glLineWidth(1.5f);
    glColor3f(0.0f, 0.4f, 0.0f);
    glBegin(GL_LINE_LOOP);

        glVertex2f(-0.1f, -0.05f);
        glVertex2f(-0.08f, 0.02f);
        glVertex2f(-0.05f, 0.05f);
        glVertex2f( 0.0f,  0.07f);
        glVertex2f( 0.05f, 0.05f);
        glVertex2f( 0.08f, 0.02f);
        glVertex2f( 0.1f, -0.05f);
        glVertex2f( 0.05f, -0.07f);
        glVertex2f(-0.05f, -0.07f);
    glEnd();
*/
}

void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

//sky
glBegin(GL_QUADS);
glColor3f(0.529f,0.808f,0.922f);
glVertex2f(-1.0f,1.0f);
glVertex2f(-1.0f,0.3f);
glVertex2f(1.0f,0.3f);
glVertex2f(1.0f,1.0f);
glEnd();

//Hill
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.13f, 0.54f, 0.13f);

glVertex2f(0.0f, 0.0f);

glVertex2f(-1.0f, 0.0f);
glVertex2f(-1.0f, 0.5f);
glVertex2f(-0.95f, 0.4f);
glVertex2f(-0.9f, 0.35f);
glVertex2f(-0.8f, 0.6f);
glVertex2f(-0.7f, 0.45f);
glVertex2f(-0.6f, 0.7f);
glVertex2f(-0.4f, 0.35f);
glVertex2f(-0.3f, 0.5f);
glVertex2f(-0.2f, 0.4f);
glVertex2f(0.0f, 0.8f);
glVertex2f(0.2f, 0.5f);
glVertex2f(0.3f, 0.6f);
glVertex2f(0.4f, 0.5f);
glVertex2f(0.5f, 0.7f);
glVertex2f(0.7f, 0.8f);
glVertex2f(0.8f, 0.6f);
glVertex2f(0.9f, 0.7f);
glVertex2f(1.0f, 0.5f);
glVertex2f(1.0f, 0.0f);
glEnd();

//Sun
int i;
    GLfloat x = 0.4f;
    GLfloat y = 0.85f;
    GLfloat radius = 0.1f;
    int triangleAmount = 100;
    GLfloat twicePi = 2.0f * PI;

    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
        {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
        }
glEnd();

//surface
glBegin(GL_QUADS);
    glColor3f(0.30f, 0.32f, 0.20f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(-1.0f, 0.0f);
glEnd();

//road
glBegin(GL_QUADS);
    glColor3f(0.4f, 0.26f, 0.13f);
    glVertex2f(1.0f, -0.4f);
    glVertex2f(1.0f, -0.7f);
    glVertex2f(0.2f, -1.0f);
    glVertex2f(-0.4f, -1.0f);
glEnd();

//tree

//col 11
glLoadIdentity(); glTranslatef(0.9f, -0.02f, 0.0f); glScalef(0.40f, 0.40f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.98f, -0.05f, 0.0f); glScalef(0.45f, 0.45f, 0.0f); drawTeaTree();


//col 10
glLoadIdentity(); glTranslatef(0.75f, -0.02f, 0.0f); glScalef(0.43f, 0.43f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.8f, -0.05f, 0.0f); glScalef(0.43f, 0.43f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.88f, -0.1f, 0.0f); glScalef(0.48f, 0.48f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.94f, -0.15f, 0.0f); glScalef(0.5f, 0.5f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.98f, -0.2f, 0.0f); glScalef(0.52f, 0.52f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(1.0f, -0.24f, 0.0f); glScalef(0.52f, 0.52f, 0.0f); drawTeaTree();

//col9
glLoadIdentity(); glTranslatef(0.6f, -0.02f, 0.0f); glScalef(0.45f, 0.45f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.7f, -0.05f, 0.0f); glScalef(0.45f, 0.45f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.75f, -0.1f, 0.0f); glScalef(0.48f, 0.48f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.82f, -0.18f, 0.0f); glScalef(0.49f, 0.49f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.9f, -0.24f, 0.0f); glScalef(0.5f, 0.5f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.94f, -0.29f, 0.0f); glScalef(0.52f, 0.52f, 0.0f); drawTeaTree();

//col8
glLoadIdentity(); glTranslatef(0.45f, -0.02f, 0.0f); glScalef(0.45f, 0.45f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.52f, -0.05f, 0.0f); glScalef(0.45f, 0.45f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.62f, -0.12f, 0.0f); glScalef(0.45f, 0.45f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.68f, -0.19f, 0.0f); glScalef(0.48f, 0.48f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.75f, -0.25f, 0.0f); glScalef(0.5f, 0.5f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.83f, -0.32f, 0.0f); glScalef(0.52f, 0.52f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.9f, -0.38f, 0.0f); glScalef(0.55f, 0.55f, 0.0f); drawTeaTree();

//col 7
glLoadIdentity(); glTranslatef(0.29f, -0.02f, 0.0f); glScalef(0.45f, 0.45f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.38f, -0.08f, 0.0f); glScalef(0.45f, 0.45f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.46f, -0.14f, 0.0f); glScalef(0.48f, 0.48f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.52f, -0.2f, 0.0f); glScalef(0.5f, 0.5f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.62f, -0.28f, 0.0f); glScalef(0.54f, 0.54f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.68f, -0.34f, 0.0f); glScalef(0.58f, 0.58f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.73f, -0.4f, 0.0f); glScalef(0.6f, 0.6f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.78f, -0.43f, 0.0f); glScalef(0.62f, 0.62f, 0.0f); drawTeaTree();

//col 6
glLoadIdentity(); glTranslatef(0.15f, -0.05f, 0.0f); glScalef(0.45f, 0.45f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.2f, -0.1f, 0.0f); glScalef(0.5f, 0.5f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.28f, -0.15f, 0.0f); glScalef(0.5f, 0.5f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.32f, -0.2f, 0.0f); glScalef(0.55f, 0.55f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.38f, -0.25f, 0.0f); glScalef(0.58f, 0.58f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.44f, -0.3f, 0.0f); glScalef(0.6f, 0.6f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.50f, -0.38f, 0.0f); glScalef(0.65f, 0.65f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.55f, -0.44f, 0.0f); glScalef(0.68f, 0.68f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.62f, -0.5f, 0.0f); glScalef(0.7f, 0.7f, 0.0f); drawTeaTree();

//col 5
glLoadIdentity(); glTranslatef(-0.05f, -0.02f, 0.0f); glScalef(0.50f, 0.50f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(-0.03f, -0.05f, 0.0f); glScalef(0.53f, 0.53f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.01f, -0.1f, 0.0f); glScalef(0.55f, 0.55f, 0.0f); drawTeaTree();
//glLoadIdentity(); glTranslatef(0.099f, -0.15f, 0.0f); glScalef(0.60f, 0.60f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.1f, -0.2f, 0.0f); glScalef(0.65f, 0.65f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.18f, -0.25f, 0.0f); glScalef(0.68f, 0.68f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.22f, -0.3f, 0.0f); glScalef(0.70f, 0.70f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.32f, -0.4f, 0.0f); glScalef(0.75f, 0.75f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.4f, -0.5f, 0.0f); glScalef(0.8f, 0.8f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.45f, -0.56f, 0.0f); glScalef(0.8f, 0.8f, 0.0f); drawTeaTree();

//col 4
glLoadIdentity(); glTranslatef(-0.25f, -0.02f, 0.0f); glScalef(0.53f, 0.53f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(-0.18f, -0.1f, 0.0f); glScalef(0.57f, 0.57f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(-0.12f, -0.2f, 0.0f); glScalef(0.68f, 0.68f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(-0.04f, -0.3f, 0.0f); glScalef(0.73f, 0.73f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.06f, -0.4f, 0.0f); glScalef(0.85f, 0.85f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.15f, -0.5f, 0.0f); glScalef(0.9f, 0.9f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.23f, -0.6f, 0.0f); glScalef(1.0f, 1.0f, 0.0f); drawTeaTree();

//col 3
glLoadIdentity(); glTranslatef(-0.48f, -0.05f, 0.0f); glScalef(0.68f, 0.68f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(-0.44f, -0.1f, 0.0f); glScalef(0.7f, 0.7f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(-0.40f, -0.2f, 0.0f); glScalef(0.8f, 0.8f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(-0.33f, -0.3f, 0.0f); glScalef(0.83f, 0.83f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(-0.25f, -0.4f, 0.0f); glScalef(0.85f, 0.85f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(-0.2f, -0.5f, 0.0f); glScalef(1.0f, 1.0f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(-0.15f, -0.6f, 0.0f); glScalef(1.1f, 1.1f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(-0.05f, -0.7f, 0.0f); glScalef(1.2f, 1.2f, 0.0f); drawTeaTree();

//col 2
glLoadIdentity(); glTranslatef(-0.72f, -0.05f, 0.0f); glScalef(0.68f, 0.68f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(-0.69f, -0.1f, 0.0f); glScalef(0.7f, 0.7f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(-0.65f, -0.2f, 0.0f); glScalef(0.8f, 0.8f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(-0.63f, -0.3f, 0.0f); glScalef(0.83f, 0.83f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(-0.58f, -0.4f, 0.0f); glScalef(0.85f, 0.85f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(-0.52f, -0.5f, 0.0f); glScalef(1.0f, 1.0f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(-0.50f, -0.6f, 0.0f); glScalef(1.1f, 1.1f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(-0.48f, -0.7f, 0.0f); glScalef(1.2f, 1.2f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(-0.44f, -0.8f, 0.0f); glScalef(1.3f, 1.3f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(-0.42f, -0.85f, 0.0f); glScalef(1.32f, 1.32f, 0.0f); drawTeaTree();


//col 1
glLoadIdentity(); glTranslatef(-1.0f, -0.05f, 0.0f); glScalef(0.68f, 0.68f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(-0.98f, -0.1f, 0.0f); glScalef(0.7f, 0.7f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(-0.96f, -0.2f, 0.0f); glScalef(0.8f, 0.8f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(-0.93f, -0.3f, 0.0f); glScalef(0.83f, 0.83f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(-0.91f, -0.4f, 0.0f); glScalef(0.85f, 0.85f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(-0.9f, -0.5f, 0.0f); glScalef(1.0f, 1.0f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(-0.88f, -0.6f, 0.0f); glScalef(1.1f, 1.1f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(-0.87f, -0.7f, 0.0f); glScalef(1.2f, 1.2f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(-0.86f, -0.8f, 0.0f); glScalef(1.3f, 1.3f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(-0.84f, -0.88f, 0.0f); glScalef(1.35f, 1.35f, 0.0f); drawTeaTree();



//road tree
glLoadIdentity(); glTranslatef(0.9f, -0.75f, 0.0f); glScalef(1.2f, 1.2f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.5f, -0.95f, 0.0f); glScalef(1.4f, 1.4f, 0.0f); drawTeaTree();
glLoadIdentity(); glTranslatef(0.85f, -0.95f, 0.0f); glScalef(1.4f, 1.4f, 0.0f); drawTeaTree();


     glFlush(); // Render now
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1280, 720); // Set the window's initial width & height
    glutInitWindowPosition(80, 50);  // Set the window's initial position according to the monitor
    glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}
