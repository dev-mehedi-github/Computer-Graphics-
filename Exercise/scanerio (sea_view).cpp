#include <windows.h>
#include <GL/glut.h>
#include<math.h>

GLfloat position = 0.0f;
GLfloat position2 = 0.0f;
GLfloat position3 = 0.0f;

GLfloat speed = 0.05f;
# define PI 3.14159265358979323846

void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    int triangleAmount = 1000;
    GLfloat twicePi = 2.0f * PI;

    /**........................................ Sky ...........................................**/
    glColor3f(0.4f,0.69f,1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, 0.3f);
    glVertex2f(1.0f, 0.3f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();

    /**........................................ Sea ...........................................**/
    glColor3f(0.0f,0.29f,0.6f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, 0.3f);
    glVertex2f(1.0f, 0.3f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();

    /**....................................... Fan ..........................................**/
    glColor3f(0.376f,0.376f,0.376f);
    glBegin(GL_QUADS);
    glVertex2f(-0.71f, 0.7f);
    glVertex2f(-0.71f, 0.3f);
    glVertex2f(-0.69f, 0.3f);
    glVertex2f(-0.69f, 0.7f);
    glEnd();

    glLineWidth(10);
    glColor3f(0.8f,0.8f,0.8f);
    glBegin(GL_LINES);
    glVertex2f(-0.7f, 0.7f);
    glVertex2f(-0.71f, 0.55f);
    glVertex2f(-0.7f, 0.7f);
    glVertex2f(-0.8f, 0.8f);
    glVertex2f(-0.7f, 0.7f);
    glVertex2f(-0.6f, 0.8f);
    glEnd();

    GLfloat xL1=-0.7f;
    GLfloat yL1=0.7f;
    GLfloat radiusL1 =.02f;
    glColor3f(0.4f,0.2f,0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xL1, yL1);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xL1 + (radiusL1 * cos(i *  twicePi / triangleAmount)),
                    yL1 + (radiusL1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    glColor3f(0.376f,0.376f,0.376f);
    glBegin(GL_QUADS);
    glVertex2f(-0.11f, 0.7f);
    glVertex2f(-0.11f, 0.3f);
    glVertex2f(-0.09f, 0.3f);
    glVertex2f(-0.09f, 0.7f);
    glEnd();

    glLineWidth(10);
    glColor3f(0.8f,0.8f,0.8f);
    glBegin(GL_LINES);
    glVertex2f(-0.1f, 0.7f);
    glVertex2f(-0.11f, 0.55f);
    glVertex2f(-0.1f, 0.7f);
    glVertex2f(-0.2f, 0.8f);
    glVertex2f(-0.1f, 0.7f);
    glVertex2f(0.0f, 0.8f);
    glEnd();

    GLfloat xL2=-0.1f;
    GLfloat yL2=0.7f;
    GLfloat radiusL2 =.02f;
    glColor3f(0.4f,0.2f,0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xL2, yL2);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xL2 + (radiusL2 * cos(i *  twicePi / triangleAmount)),
                    yL2 + (radiusL2 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    glColor3f(0.376f,0.376f,0.376f);
    glBegin(GL_QUADS);
    glVertex2f(0.41f, 0.7f);
    glVertex2f(0.41f, 0.3f);
    glVertex2f(0.39f, 0.3f);
    glVertex2f(0.39f, 0.7f);
    glEnd();

    glLineWidth(10);
    glColor3f(0.8f,0.8f,0.8f);
    glBegin(GL_LINES);
    glVertex2f(0.4f, 0.7f);
    glVertex2f(0.39f, 0.55f);
    glVertex2f(0.4f, 0.7f);
    glVertex2f(0.3f, 0.8f);
    glVertex2f(0.4f, 0.7f);
    glVertex2f(0.5f, 0.8f);
    glEnd();

    GLfloat xL3=0.4f;
    GLfloat yL3=0.7f;
    GLfloat radiusL3 =.02f;
    glColor3f(0.4f,0.2f,0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xL3, yL3);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( xL3 + (radiusL3 * cos(i *  twicePi / triangleAmount)),
                    yL3 + (radiusL3 * sin(i * twicePi / triangleAmount)) );
    }

    glEnd();

    /**....................................... Hill ..........................................**/
    glColor3f(1.0f,0.5f,0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.8f, 0.3f);
    glVertex2f(-0.6f, 0.5f);
    glVertex2f(-0.4f, 0.3f);
    glEnd();

    glColor3f(0.4f,0.2f,0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.55f, 0.3f);
    glVertex2f(-0.35f, 0.55f);
    glVertex2f(-0.05f, 0.3f);
    glEnd();

    glColor3f(0.4f,0.2f,0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.3f, 0.3f);
    glVertex2f(0.2f, 0.4f);
    glVertex2f(0.7f, 0.3f);
    glEnd();

    /**....................................... Sun ..........................................**/
    GLfloat x17=0.7f;
    GLfloat y17=0.7f;
    GLfloat radius17 =.1f;
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x17, y17);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x17 + (radius17 * cos(i *  twicePi / triangleAmount)),
                    y17 + (radius17 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    /**.................................... small boat-1 .......................................**/
    glPushMatrix();
        glTranslatef(position, 0.0f, 0.0f);
        glColor3f(0.0f,0.5f,0.0f);
        glBegin(GL_QUADS);
        glVertex2f(0.6f, 0.2f);
        glVertex2f(0.7f, 0.1f);
        glVertex2f(0.8f, 0.1f);
        glVertex2f(0.9f, 0.2f);
        glEnd();

        glColor3f(1.0f,0.0f,0.0f);
        glBegin(GL_TRIANGLES);
        glVertex2f(0.71f, 0.22f);
        glVertex2f(0.74f, 0.3f);
        glVertex2f(0.74, 0.22f);
        glEnd();

        glColor3f(1.0f,0.0f,0.0f);
        glBegin(GL_TRIANGLES);
        glVertex2f(0.75f, 0.22f);
        glVertex2f(0.75f, 0.4f);
        glVertex2f(0.8, 0.22f);
        glEnd();
    glPopMatrix();

    /**.................................... small boat-3 .......................................**/
    glPushMatrix();
        glTranslatef(-1.3f, -0.2f, 0.0f);
        glColor3f(0.0f,0.5f,0.0f);
        glBegin(GL_QUADS);
        glVertex2f(0.6f, 0.2f);
        glVertex2f(0.7f, 0.1f);
        glVertex2f(0.8f, 0.1f);
        glVertex2f(0.9f, 0.2f);
        glEnd();

        glColor3f(1.0f,0.0f,0.0f);
        glBegin(GL_TRIANGLES);
        glVertex2f(0.71f, 0.22f);
        glVertex2f(0.74f, 0.3f);
        glVertex2f(0.74, 0.22f);
        glEnd();

        glColor3f(1.0f,0.0f,0.0f);
        glBegin(GL_TRIANGLES);
        glVertex2f(0.75f, 0.22f);
        glVertex2f(0.75f, 0.4f);
        glVertex2f(0.8, 0.22f);
        glEnd();
    glPopMatrix();

    /**.................................... small boat-2 .......................................**/
    glPushMatrix();
        glTranslatef(position2, 0.0f, 0.0f);
        glColor3f(0.0f,0.5f,0.0f);
        glBegin(GL_QUADS);
        glVertex2f(-0.5f, -0.4f);
        glVertex2f(-0.4f, -0.5f);
        glVertex2f(-0.3f, -0.5f);
        glVertex2f(-0.2f, -0.4f);
        glEnd();

        glColor3f(1.0f,0.0f,0.0f);
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.38f, -0.38f);
        glVertex2f(-0.36f, -0.3f);
        glVertex2f(-0.36, -0.38f);
        glEnd();

        glBegin(GL_TRIANGLES);
        glVertex2f(-0.3f, -0.38f);
        glVertex2f(-0.35f, -0.2f);
        glVertex2f(-0.35, -0.38f);
        glEnd();
    glPopMatrix();

    /**.................................... big boat-structure .......................................**/
    glPushMatrix();
        glTranslatef(position3, 0.0f, 0.0f);
        glColor3f(0.0f,0.0f,0.0f);
        glBegin(GL_QUADS);
        glVertex2f(-0.3f, -0.8f);
        glVertex2f(0.5f, -0.8f);
        glVertex2f(0.55f, -0.75f);
        glVertex2f(-0.35f, -0.75f);
        glEnd();

        glColor3f(0.8f,0.4f,0.0f);
        glBegin(GL_QUADS);
        glVertex2f(-0.35f, -0.75f);
        glVertex2f(0.55f, -0.75f);
        glVertex2f(0.7f, -0.6f);
        glVertex2f(-0.5f, -0.6f);
        glEnd();

        glColor3f(0.6f,0.29f,0.0f);
        glBegin(GL_QUADS);
        glVertex2f(-0.5f, -0.55f);
        glVertex2f(0.7f, -0.55f);
        glVertex2f(0.7f, -0.6f);
        glVertex2f(-0.5f, -0.6f);
        glEnd();

        glColor3f(0.5f,0.5f,0.5f);
        glBegin(GL_QUADS);
        glVertex2f(-0.4f, -0.55f);
        glVertex2f(0.6f, -0.55f);
        glVertex2f(0.6f, -0.45f);
        glVertex2f(-0.4f, -0.45f);
        glEnd();

        glColor3f(0.8f,0.6f,1.0f);
        glBegin(GL_QUADS);
        glVertex2f(-0.3f, -0.35f);
        glVertex2f(0.5f, -0.35f);
        glVertex2f(0.57f, -0.45f);
        glVertex2f(-0.3f, -0.45f);
        glEnd();

        glColor3f(0.6f,0.29f,0.0f);
        glBegin(GL_QUADS);
        glVertex2f(-0.3f, -0.35f);
        glVertex2f(0.5f, -0.35f);
        glVertex2f(0.4f, -0.3f);
        glVertex2f(-0.2f, -0.3f);
        glEnd();

        /**.................................... big boat-Pillar .......................................**/
        glColor3f(0.0f,0.0f,0.0f);
        glBegin(GL_QUADS);
        glVertex2f(-0.15f, -0.2f);
        glVertex2f(-0.05f, -0.2f);
        glVertex2f(-0.05f, -0.3f);
        glVertex2f(-0.15f, -0.3f);
        glEnd();

        glColor3f(0.6f,0.29f,0.0f);
        glBegin(GL_QUADS);
        glVertex2f(-0.15f, -0.2f);
        glVertex2f(-0.05f, -0.2f);
        glVertex2f(-0.05f, -0.15f);
        glVertex2f(-0.15f, -0.15f);
        glEnd();

        glColor3f(0.0f,0.0f,0.0f);
        glBegin(GL_QUADS);
        glVertex2f(0.15f, -0.2f);
        glVertex2f(0.05f, -0.2f);
        glVertex2f(0.05f, -0.3f);
        glVertex2f(0.15f, -0.3f);
        glEnd();

        glColor3f(0.6f,0.29f,0.0f);
        glBegin(GL_QUADS);
        glVertex2f(0.15f, -0.2f);
        glVertex2f(0.05f, -0.2f);
        glVertex2f(0.05f, -0.15f);
        glVertex2f(0.15f, -0.15f);
        glEnd();

        glColor3f(0.0f,0.0f,0.0f);
        glBegin(GL_QUADS);
        glVertex2f(0.25f, -0.2f);
        glVertex2f(0.35f, -0.2f);
        glVertex2f(0.35f, -0.3f);
        glVertex2f(0.25f, -0.3f);
        glEnd();

        glColor3f(0.6f,0.29f,0.0f);
        glBegin(GL_QUADS);
        glVertex2f(0.25f, -0.2f);
        glVertex2f(0.35f, -0.2f);
        glVertex2f(0.35f, -0.15f);
        glVertex2f(0.25f, -0.15f);
        glEnd();

        /**.................................... big boat-design-1 .......................................**/
        glColor3f(1.0f,1.0f,1.0f);
        glBegin(GL_QUADS);
        glVertex2f(0.4f, -0.38f);
        glVertex2f(0.52f, -0.38f);
        glVertex2f(0.55f, -0.42f);
        glVertex2f(0.4f, -0.42f);
        glEnd();

        GLfloat x5=-0.25f;
        GLfloat y5=-0.4f;
        GLfloat radius =.03f;

        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x5, y5);
        for(int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f( x5 + (radius * cos(i *  twicePi / triangleAmount)),
                        y5 + (radius * sin(i * twicePi / triangleAmount)) );
        }
        glEnd();


        GLfloat x6=-0.15f;
        GLfloat y6=-0.4f;

        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x6, y6);
        for(int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f( x6 + (radius * cos(i *  twicePi / triangleAmount)),
                        y6 + (radius * sin(i * twicePi / triangleAmount)) );
        }
        glEnd();


        GLfloat x7=-0.05f;
        GLfloat y7=-0.4f;

        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x7, y7);
        for(int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f( x7 + (radius * cos(i *  twicePi / triangleAmount)),
                        y7 + (radius * sin(i * twicePi / triangleAmount)) );
        }
        glEnd();

        GLfloat x8=0.05f;
        GLfloat y8=-0.4f;

        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x8, y8);
        for(int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f( x8 + (radius * cos(i *  twicePi / triangleAmount)),
                        y8 + (radius * sin(i * twicePi / triangleAmount)) );
        }
        glEnd();


        GLfloat x9=0.15f;
        GLfloat y9=-0.4f;

        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x9, y9);
        for(int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f( x9 + (radius * cos(i *  twicePi / triangleAmount)),
                        y9 + (radius * sin(i * twicePi / triangleAmount)) );
        }
        glEnd();

        GLfloat x10=0.25f;
        GLfloat y10=-0.4f;

        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x10, y10);
        for(int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f( x10 + (radius * cos(i *  twicePi / triangleAmount)),
                        y10 + (radius * sin(i * twicePi / triangleAmount)) );
        }
        glEnd();


        GLfloat x11=0.35f;
        GLfloat y11=-0.4f;

        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x11, y11);
        for(int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f( x11 + (radius * cos(i *  twicePi / triangleAmount)),
                        y11 + (radius * sin(i * twicePi / triangleAmount)) );
        }
        glEnd();

        /**.................................... big boat-design-2 .......................................**/
        GLfloat x1=-0.2f;
        GLfloat y1=-0.5f;

        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x1, y1);
        for(int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f( x1 + (radius * cos(i *  twicePi / triangleAmount)),
                        y1 + (radius * sin(i * twicePi / triangleAmount)) );
        }
        glEnd();

        GLfloat x2=0.0f;
        GLfloat y2=-0.5f;

        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x2, y2);
        for(int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f( x2 + (radius * cos(i *  twicePi / triangleAmount)),
                        y2 + (radius * sin(i * twicePi / triangleAmount)) );
        }
        glEnd();

        GLfloat x3=0.2f;
        GLfloat y3=-0.5f;

        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x3, y3);
        for(int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f( x3 + (radius * cos(i *  twicePi / triangleAmount)),
                        y3 + (radius * sin(i * twicePi / triangleAmount)) );
        }
        glEnd();


        GLfloat x4=0.4f;
        GLfloat y4=-0.5f;

        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x4, y4);
        for(int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f( x4 + (radius * cos(i *  twicePi / triangleAmount)),
                        y4 + (radius * sin(i * twicePi / triangleAmount)) );
        }
        glEnd();

        /**.................................... big boat-design-3 .......................................**/
        GLfloat x12=-0.3f;
        GLfloat y12=-0.675f;
        GLfloat radius2 =.05f;

        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x12, y12);
        for(int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f( x12 + (radius2 * cos(i *  twicePi / triangleAmount)),
                        y12 + (radius2 * sin(i * twicePi / triangleAmount)) );
        }
        glEnd();

        GLfloat x13=-0.1f;
        GLfloat y13=-0.675f;

        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x13, y13);
        for(int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f( x13 + (radius2 * cos(i *  twicePi / triangleAmount)),
                        y13 + (radius2 * sin(i * twicePi / triangleAmount)) );
        }
        glEnd();

        GLfloat x14=0.1f;
        GLfloat y14=-0.675f;

        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x14, y14);
        for(int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f( x14 + (radius2 * cos(i *  twicePi / triangleAmount)),
                        y14 + (radius2 * sin(i * twicePi / triangleAmount)) );
        }
        glEnd();

        GLfloat x15=0.3f;
        GLfloat y15=-0.675f;

        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x15, y15);
        for(int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f( x15 + (radius2 * cos(i *  twicePi / triangleAmount)),
                        y15 + (radius2 * sin(i * twicePi / triangleAmount)) );
        }
        glEnd();

        GLfloat x16=0.5f;
        GLfloat y16=-0.675f;

        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x16, y16);
        for(int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f( x16 + (radius2 * cos(i *  twicePi / triangleAmount)),
                        y16 + (radius2 * sin(i * twicePi / triangleAmount)) );
        }
        glEnd();
    glPopMatrix();

    glFlush();  // Render now
}

void update(int value)
{
    if(position < -1.5)
            position = 1.5f;

    if(position2 > 1.5)
            position2 = -1.5f;

    if(position3 < -2.0)
            position3 = 2.0f;

    position -= speed;
    position2 += speed;
    position3 -= speed;
	glutPostRedisplay();
	glutTimerFunc(100, update, 0);
}

void update2(int value)
{
    if(position > 1.5)
            position = -1.5f;

    if(position2 < -1.5)
            position2 = 1.5f;

    if(position3 > 2.0)
            position3 = -2.0f;

    position += speed;
    position2 -= speed;
    position3 += speed;
	glutPostRedisplay();
	glutTimerFunc(100, update2, 0);
}

void SpecialInput(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_UP:
            speed = speed + 0.01;
            break;

        case GLUT_KEY_DOWN:
            speed = speed - 0.01;
            break;

        case GLUT_KEY_LEFT:
            glutTimerFunc(100, update, 0);
            break;

        case GLUT_KEY_RIGHT:
            glutTimerFunc(100, update2, 0);
            break;
    }
    glutPostRedisplay();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);                 // Initialize GLUT
    glutInitWindowSize(320, 320);   // Set the window's initial width & height
    glutInitWindowPosition(80, 50);  // Set the window's initial position according to the monitor
    glutCreateWindow("Sea view"); // Create a window with the given title
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    /// init();
    glutSpecialFunc(SpecialInput);
    glutMainLoop();           // Enter the event-processing loop
    return 0;
}
