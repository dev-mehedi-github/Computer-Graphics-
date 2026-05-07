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
//birds
float birdPos = -1.2f;
float birdScale = 1.0f;
bool isStarted = false;
//rain
float rainY_move = 0.0f;
bool isRaining = false;
//cloud
float cloudPos = -0.6f;
bool cloudMoving = false;



void updateBirds(int value) {
    if (isStarted) {
        birdPos += 0.01f;
        if (birdPos > 1.1f) birdPos = -1.1f;
        birdScale = 1.0f - (birdPos + 1.0f) * 0.4f;
    }
    glutPostRedisplay();
    glutTimerFunc(50, updateBirds, 0);
}


void updateRain(int value) {
    if (isRaining) {
        rainY_move += 0.08f;
        if (rainY_move > 0.3f) {
            rainY_move = 0.0f;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(40, updateRain, 0);
}

void updateClouds(int value) {
    if (cloudMoving) {
        cloudPos += 0.0005f;
        if (cloudPos > 1.1f) {
            cloudPos = -1.1f; // Repeat
        }
    }
    glutPostRedisplay();
    glutTimerFunc(50, updateClouds, 0);
}

void teaRainSound() {
    if (isRaining) {
    PlaySound("raincg.wav", NULL, SND_ASYNC|SND_FILENAME);
    } else {
        PlaySound(NULL, 0, 0);
    }
}
void teabirdsSound() {
    if (isStarted) {
    PlaySound("teabird.wav", NULL, SND_ASYNC|SND_FILENAME);
    } else {
        PlaySound(NULL, 0, 0);
    }
}


void teaKeyboard(unsigned char key, int x, int y) {
    switch(key) {
        case 'r':
        case 'R':
            isRaining = !isRaining;
            if (isRaining) {
                isStarted = false;
                teabirdsSound();
            }

            teaRainSound();
            glutPostRedisplay();
            break;

        case 'b':
        case 'B':
            if (!isRaining) {
                isStarted = !isStarted;
                teabirdsSound();
            }
            glutPostRedisplay();
            break;
    }
}
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        cloudMoving = true;
    }
}

void drawteaRain() {
    if (!isRaining) return;

    glPushMatrix();
    glTranslatef(0.0f, -rainY_move, 0.0f);

    glLineWidth(1.0f);
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_LINES);
    for(float x = -1.0f; x <= 1.0f; x += 0.1f) {
        glVertex2f(x, 1.1f);
        glVertex2f(x, 1.0f);

        glVertex2f(x, 0.7f);
        glVertex2f(x, 0.6f);

        glVertex2f(x, 0.4f);
        glVertex2f(x, 0.3f);

        glVertex2f(x, 0.1f);
        glVertex2f(x, 0.0f);

        glVertex2f(x, -0.2f);
        glVertex2f(x, -0.3f);

        glVertex2f(x, -0.5f);
        glVertex2f(x, -0.6f);

        glVertex2f(x, -0.8f);
        glVertex2f(x, -0.9f);
    }
    glEnd();
    glPopMatrix();
}

//sky color
void teaSky() {
    glBegin(GL_QUADS);
    if (!isRaining) {
        glColor3f(0.529f, 0.808f, 0.922f);
    } else {
        glColor3f(0.2f, 0.2f, 0.2f);
    }
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(-1.0f, 0.2f);
    glVertex2f(1.0f, 0.2f);
    glVertex2f(1.0f, 1.0f);
    glEnd();
}



void teaBirdsShape() {
    glLineWidth(2.0f);
    glColor3f(0.05f, 0.05f, 0.05f);
    glBegin(GL_LINES);

    glVertex2f(-0.05f, 0.05f);
    glVertex2f(0.0f, 0.0f);

    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.05f, 0.05f);

    glVertex2f(-0.15f, -0.05f);
    glVertex2f(-0.10f, -0.10f);

    glVertex2f(-0.10f, -0.10f);
    glVertex2f(-0.05f, -0.05f);

    glVertex2f(0.05f, -0.05f);
    glVertex2f(0.10f, -0.10f);

    glVertex2f(0.10f, -0.10f);
    glVertex2f(0.15f, -0.05f);
    glEnd();
}

void teaHill()
{
    glColor3f(0.01f, 0.05f, 0.01f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.7f, 0.6f);
    glVertex2f(-0.2f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(-1.0f, 0.3f);
    glEnd();

    glColor3f(0.02f, 0.07f, 0.02f);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(0.8f, 0.3f);
    glVertex2f(1.0f, 0.6f);
    glVertex2f(1.0f, 0.0f);
    glEnd();

    glColor3f(0.03f, 0.12f, 0.03f);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(0.1f, 0.0f);
    glVertex2f(0.6f, 0.6f);
    glVertex2f(1.0f, 0.0f);
    glEnd();

    glColor3f(0.05f, 0.18f, 0.05f);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(-0.2f, 0.0f);
    glVertex2f(0.3f, 0.5f);
    glVertex2f(0.7f, 0.0f);
    glEnd();

    glColor3f(0.08f, 0.25f, 0.08f);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(-0.7f, 0.0f);
    glVertex2f(-0.1f, 0.7f);
    glVertex2f(0.5f, 0.0f);
    glEnd();
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

}
void drawCircle(float radius) {
    int triangleAmount = 100;
    float twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.0f, 0.0f); // Center
        for (int i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                radius * cos(i * twicePi / triangleAmount),
                radius * sin(i * twicePi / triangleAmount)
            );
        }
    glEnd();
}
// cloud
void renderClouds() {
    glPushMatrix();
    glTranslatef(cloudPos, 0.88f, 0.0f);

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    drawCircle(0.08f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.08f, 0.0f, 0.0f);
    drawCircle(0.07f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.08f, 0.0f, 0.0f);
    drawCircle(0.07f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 0.05f, 0.0f);
    drawCircle(0.08f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.05f, 0.04f, 0.0f);
    drawCircle(0.06f);
    glPopMatrix();

    glPopMatrix();
}

// 2. Define the Sunny version
void sunnyCloud() {
    glColor3f(1.0f, 1.0f, 1.0f); // White
    renderClouds();
}

// 3. Define the Stormy version
void rainCloud() {
    glColor3f(0.4f, 0.4f, 0.4f); // Gray
    renderClouds();
}

void drawBigTree() {
    // lower body
    glColor3f(0.36f, 0.25f, 0.20f);
    glBegin(GL_QUADS);
        glVertex2f(-0.01f, -0.1f);
        glVertex2f( 0.01f, -0.1f);
        glVertex2f( 0.01f,  0.0f);
        glVertex2f(-0.01f,  0.0f);
    glEnd();

    // uper body 1
    glColor3f(0.0f, 0.35f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.12f, 0.0f);
        glVertex2f( 0.12f, 0.0f);
        glVertex2f( 0.0f,  0.08f);
    glEnd();

    // uper body side Border
    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.12f, 0.0f);
        glVertex2f( 0.12f, 0.0f);
        glVertex2f( 0.0f,  0.08f);
    glEnd();

    // Upper Body 2
    glColor3f(0.0f, 0.40f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.09f, 0.05f);
        glVertex2f( 0.09f, 0.05f);
        glVertex2f( 0.0f,  0.14f);
    glEnd();

    // Upper Body2 side Border
    glColor3f(0.0f, 0.55f, 0.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.09f, 0.05f);
        glVertex2f( 0.09f, 0.05f);
        glVertex2f( 0.0f,  0.14f);
    glEnd();

    // Upper Body 3
    glColor3f(0.0f, 0.45f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.05f, 0.11f);
        glVertex2f( 0.05f, 0.11f);
        glVertex2f( 0.0f,  0.19f);
    glEnd();

    // Layer 3 Border
    glColor3f(0.0f, 0.6f, 0.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.05f, 0.11f);
        glVertex2f( 0.05f, 0.11f);
        glVertex2f( 0.0f,  0.19f);
    glEnd();
}

void teaSun(){
glLoadIdentity();
glColor3f(1.0f, 1.0f, 0.0f);
glTranslatef(0.4f, 0.85f, 0.0f);
drawCircle(0.1f);
glLoadIdentity();
}
void teaRoad(){
glBegin(GL_QUADS);
    glColor3f(0.4f, 0.26f, 0.13f);
    glVertex2f(1.0f, -0.4f);
    glVertex2f(1.0f, -0.7f);
    glVertex2f(0.2f, -1.0f);
    glVertex2f(-0.4f, -1.0f);
glEnd();
}
void teaSurface(){
glBegin(GL_QUADS);
    glColor3f(0.30f, 0.32f, 0.20f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(-1.0f, 0.0f);
glEnd();
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void displayTeaGarden()
{
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)


teaSky();

    // Weather Logic
    if (!isRaining) {
        teaSun();
        sunnyCloud();
    }
    else {
        rainCloud();
        drawteaRain();
    }

teaHill();
teaSurface();
teaRoad();

//transformation
//tea trees

//col 11
glPushMatrix();
glTranslatef(0.9f, -0.02f, 0.0f);
glScalef(0.40f, 0.40f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.98f, -0.05f, 0.0f);
glScalef(0.45f, 0.45f, 0.0f);
drawTeaTree();
glPopMatrix();

//col 10
glPushMatrix();
glTranslatef(0.75f, -0.02f, 0.0f);
glScalef(0.43f, 0.43f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.8f, -0.05f, 0.0f);
glScalef(0.43f, 0.43f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.88f, -0.1f, 0.0f);
glScalef(0.48f, 0.48f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.94f, -0.15f, 0.0f);
glScalef(0.5f, 0.5f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.98f, -0.2f, 0.0f);
glScalef(0.52f, 0.52f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
 glTranslatef(1.0f, -0.24f, 0.0f);
 glScalef(0.52f, 0.52f, 0.0f);
 drawTeaTree();
 glPopMatrix();

//col9
glPushMatrix();
glTranslatef(0.6f, -0.02f, 0.0f);
glScalef(0.45f, 0.45f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.7f, -0.05f, 0.0f);
glScalef(0.45f, 0.45f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.75f, -0.1f, 0.0f);
glScalef(0.48f, 0.48f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.82f, -0.18f, 0.0f);
glScalef(0.49f, 0.49f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.9f, -0.24f, 0.0f);
glScalef(0.5f, 0.5f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.94f, -0.29f, 0.0f);
glScalef(0.52f, 0.52f, 0.0f);
drawTeaTree();
glPopMatrix();

//col8
glPushMatrix();
glTranslatef(0.45f, -0.02f, 0.0f);
glScalef(0.45f, 0.45f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.52f, -0.05f, 0.0f);
glScalef(0.45f, 0.45f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.62f, -0.12f, 0.0f);
glScalef(0.45f, 0.45f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.68f, -0.19f, 0.0f);
glScalef(0.48f, 0.48f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.75f, -0.25f, 0.0f);
glScalef(0.5f, 0.5f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.83f, -0.32f, 0.0f);
glScalef(0.52f, 0.52f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.9f, -0.38f, 0.0f);
glScalef(0.55f, 0.55f, 0.0f);
drawTeaTree();
glPopMatrix();

//big tree
glPushMatrix();
glTranslatef(0.4f, 0.1f, 0.0f);
glScalef(0.7f, 1.3f, 0.0f);
drawBigTree();
glPopMatrix();

//col 7
glPushMatrix();
glTranslatef(0.29f, -0.02f, 0.0f);
glScalef(0.45f, 0.45f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.38f, -0.08f, 0.0f);
glScalef(0.45f, 0.45f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.46f, -0.14f, 0.0f);
glScalef(0.48f, 0.48f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.52f, -0.2f, 0.0f);
glScalef(0.5f, 0.5f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.62f, -0.28f, 0.0f);
glScalef(0.54f, 0.54f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.68f, -0.34f, 0.0f);
glScalef(0.58f, 0.58f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.73f, -0.4f, 0.0f);
glScalef(0.6f, 0.6f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.78f, -0.43f, 0.0f);
glScalef(0.62f, 0.62f, 0.0f);
drawTeaTree();
glPopMatrix();

//col 6
glPushMatrix();
glTranslatef(0.15f, -0.05f, 0.0f);
glScalef(0.45f, 0.45f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.2f, -0.1f, 0.0f);
glScalef(0.5f, 0.5f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.28f, -0.15f, 0.0f);
glScalef(0.5f, 0.5f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.32f, -0.2f, 0.0f);
glScalef(0.55f, 0.55f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.38f, -0.25f, 0.0f);
glScalef(0.58f, 0.58f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.44f, -0.3f, 0.0f);
glScalef(0.6f, 0.6f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.50f, -0.38f, 0.0f);
glScalef(0.65f, 0.65f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.55f, -0.44f, 0.0f);
glScalef(0.68f, 0.68f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.62f, -0.5f, 0.0f);
glScalef(0.7f, 0.7f, 0.0f);
drawTeaTree();
glPopMatrix();

//col 5
glPushMatrix();
glTranslatef(-0.05f, -0.02f, 0.0f);
glScalef(0.50f, 0.50f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.03f, -0.05f, 0.0f);
glScalef(0.53f, 0.53f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.01f, -0.1f, 0.0f);
glScalef(0.55f, 0.55f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.1f, -0.2f, 0.0f);
glScalef(0.65f, 0.65f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.18f, -0.25f, 0.0f);
glScalef(0.68f, 0.68f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.22f, -0.3f, 0.0f);
glScalef(0.70f, 0.70f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.32f, -0.4f, 0.0f);
glScalef(0.75f, 0.75f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.4f, -0.5f, 0.0f);
glScalef(0.8f, 0.8f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.45f, -0.56f, 0.0f);
glScalef(0.8f, 0.8f, 0.0f);
drawTeaTree();
glPopMatrix();

//big tree 3
glPushMatrix();
glTranslatef(-0.3f, -0.01f, 0.0f);
glScalef(1.0f, 1.5f, 0.0f);
drawBigTree();
glPopMatrix();

//col 4
glPushMatrix();
glTranslatef(-0.25f, -0.02f, 0.0f);
glScalef(0.53f, 0.53f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.18f, -0.1f, 0.0f);
glScalef(0.57f, 0.57f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.12f, -0.2f, 0.0f);
glScalef(0.68f, 0.68f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.04f, -0.3f, 0.0f);
glScalef(0.73f, 0.73f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.06f, -0.4f, 0.0f);
glScalef(0.85f, 0.85f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.15f, -0.5f, 0.0f);
glScalef(0.9f, 0.9f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.23f, -0.6f, 0.0f);
glScalef(1.0f, 1.0f, 0.0f);
drawTeaTree();
glPopMatrix();

//col 3
glPushMatrix();
glTranslatef(-0.48f, -0.05f, 0.0f);
glScalef(0.68f, 0.68f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.44f, -0.1f, 0.0f);
glScalef(0.7f, 0.7f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.40f, -0.2f, 0.0f);
glScalef(0.8f, 0.8f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.33f, -0.3f, 0.0f);
glScalef(0.83f, 0.83f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.25f, -0.4f, 0.0f);
glScalef(0.85f, 0.85f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.2f, -0.5f, 0.0f);
glScalef(1.0f, 1.0f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.15f, -0.6f, 0.0f);
glScalef(1.1f, 1.1f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.05f, -0.7f, 0.0f);
glScalef(1.2f, 1.2f, 0.0f);
drawTeaTree();
glPopMatrix();


//col 2
glPushMatrix();
glTranslatef(-0.72f, -0.05f, 0.0f);
glScalef(0.68f, 0.68f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.69f, -0.1f, 0.0f);
glScalef(0.7f, 0.7f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.65f, -0.2f, 0.0f);
glScalef(0.8f, 0.8f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.63f, -0.3f, 0.0f);
glScalef(0.83f, 0.83f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.58f, -0.4f, 0.0f);
glScalef(0.85f, 0.85f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.52f, -0.5f, 0.0f);
glScalef(1.0f, 1.0f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.50f, -0.6f, 0.0f);
glScalef(1.1f, 1.1f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.48f, -0.7f, 0.0f);
glScalef(1.2f, 1.2f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.44f, -0.8f, 0.0f);
glScalef(1.3f, 1.3f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.42f, -0.85f, 0.0f);
glScalef(1.32f, 1.32f, 0.0f);
drawTeaTree();
glPopMatrix();


//col 1
glPushMatrix();
glTranslatef(-1.0f, -0.05f, 0.0f);
glScalef(0.68f, 0.68f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.98f, -0.1f, 0.0f);
glScalef(0.7f, 0.7f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.96f, -0.2f, 0.0f);
glScalef(0.8f, 0.8f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.93f, -0.3f, 0.0f);
glScalef(0.83f, 0.83f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.91f, -0.4f, 0.0f);
glScalef(0.85f, 0.85f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.9f, -0.5f, 0.0f);
glScalef(1.0f, 1.0f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.88f, -0.6f, 0.0f);
glScalef(1.1f, 1.1f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.87f, -0.7f, 0.0f);
glScalef(1.2f, 1.2f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.86f, -0.8f, 0.0f);
glScalef(1.3f, 1.3f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.84f, -0.88f, 0.0f);
glScalef(1.35f, 1.35f, 0.0f);
drawTeaTree();
glPopMatrix();

// big tree 1 road side
glPushMatrix();
glTranslatef(0.8f, -0.4f, 0.0f);
glScalef(3.0f, 5.0f, 0.0f);
drawBigTree();
glPopMatrix();

//road tree
glPushMatrix();
glTranslatef(0.9f, -0.75f, 0.0f);
glScalef(1.2f, 1.2f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.5f, -0.95f, 0.0f);
glScalef(1.4f, 1.4f, 0.0f);
drawTeaTree();
glPopMatrix();

glPushMatrix();
glTranslatef(0.85f, -0.95f, 0.0f);
glScalef(1.4f, 1.4f, 0.0f);
drawTeaTree();
glPopMatrix();

//big tree 2
glPushMatrix();
glTranslatef(-0.78f, -0.1f, 0.0f);
glScalef(1.0f, 2.0f, 0.0f);
drawBigTree();
glPopMatrix();

drawteaRain();

if (!isRaining) {
    glPushMatrix();
        glTranslatef(birdPos, 0.85f, 0.0f);
        glScalef(birdScale, birdScale, 1.0f);
        teaBirdsShape();
    glPopMatrix();
}

     glFlush(); // Render now
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(950, 650); // Set the window's initial width & height
    glutInitWindowPosition(80, 50);  // Set the window's initial position according to the monitor
    glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
    glutDisplayFunc(displayTeaGarden); // Register display callback handler for window re-paint

    glutKeyboardFunc(teaKeyboard);
    glutMouseFunc(mouse);

    glutTimerFunc(1000, updateBirds, 0);
    glutTimerFunc(1000, updateRain, 0);
    glutTimerFunc(1000, updateClouds, 0);
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}
