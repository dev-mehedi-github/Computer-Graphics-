# Computer Graphics - Spring 2025-26 Semester

Welcome to the Computer Graphics course repository! This repository contains comprehensive code examples, projects, and resources for learning computer graphics fundamentals using **OpenGL** and **GLUT**.

## 📚 Course Overview

This repository covers essential computer graphics concepts and practical implementations:

- **Basic GLUT Window Setup** - Creating and managing OpenGL windows
- **2D Graphics Rendering** - Drawing primitives and shapes
- **Transformations** - Translation, rotation, and scaling
- **2D Animation** - Creating dynamic animations with time-based updates
- **Color Management** - Working with colors and gradients
- **Event Handling** - Keyboard and mouse input
- **Coordinate Systems** - Understanding viewport and projection

## 🛠️ Technologies & Tools

- **OpenGL** - Graphics library for rendering 2D/3D graphics
- **GLUT (OpenGL Utility Toolkit)** - Window management and input handling
- **C/C++** - Programming language
- **Visual Studio / Code::Blocks / Dev-C++** - IDEs (choose any compatible environment)

## 📁 Repository Structure

```
Computer-Graphics-/
├── README.md
├── basic-glut/
│   ├── hello_triangle.cpp
│   ├── hello_square.cpp
│   └── basic_shapes.cpp
├── 2d-shapes/
│   ├── polygon_drawing.cpp
│   ├── circle_drawing.cpp
│   └── complex_shapes.cpp
├── transformations/
│   ├── translation_example.cpp
│   ├── rotation_example.cpp
│   ├── scaling_example.cpp
│   └── combined_transformations.cpp
├── 2d-animations/
│   ├── rotating_square.cpp
│   ├── moving_circle.cpp
│   ├── bouncing_ball.cpp
│   ├── animated_shapes.cpp
│   └── particle_system.cpp
├── advanced-projects/
│   ├── solar_system.cpp
│   ├── traffic_light.cpp
│   ├── digital_clock.cpp
│   └── interactive_scene.cpp
└── resources/
    ├── setup_guide.md
    ├── compilation_guide.md
    └── troubleshooting.md
```

## 🚀 Getting Started

### Prerequisites

- **C/C++ Compiler** (GCC, MinGW, MSVC, or Clang)
- **OpenGL Libraries** installed on your system
- **GLUT Libraries** (freeglut or legacy GLUT)

### Installation & Setup

#### Windows (MinGW + Code::Blocks)
```bash
# Install freeglut development files
# Download from: http://freeglut.sourceforge.net/

# Add library paths to your IDE settings
```

#### Linux (Ubuntu/Debian)
```bash
sudo apt-get install freeglut3 freeglut3-dev
sudo apt-get install binutils-gold g++ cmake
```

#### macOS
```bash
brew install freeglut
```

### Basic Compilation

#### Using g++ (Linux/macOS)
```bash
g++ -o program program.cpp -lglut -lGL -lGLU
./program
```

#### Using g++ (Windows MinGW)
```bash
g++ -o program.exe program.cpp -lfreeglut -lopengl32 -lglu32
program.exe
```

## 📖 Sample Programs

### 1. Hello Triangle (Basic GLUT Window)
```cpp
#include <GL/glut.h>
#include <iostream>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(0.0, 0.5);
    glEnd();
    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Hello Triangle");
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
```

### 2. 2D Animation Example (Rotating Square)
```cpp
#include <GL/glut.h>
#include <cmath>

float rotation = 0.0;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(rotation, 0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(-0.3, -0.3);
    glVertex2f(0.3, -0.3);
    glVertex2f(0.3, 0.3);
    glVertex2f(-0.3, 0.3);
    glEnd();
    glPopMatrix();
    glutSwapBuffers();
}

void timer(int value) {
    rotation += 2.0;
    if (rotation > 360) rotation -= 360;
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Rotating Square");
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(16, timer, 0);
    glutMainLoop();
    return 0;
}
```

## 📌 Key Concepts Covered

| Concept | Description |
|---------|-------------|
| **GLUT Basics** | Window creation, event handling, main loop |
| **Primitives** | Points, lines, triangles, quads, polygons |
| **Colors** | RGB color model, color blending |
| **Transformations** | Matrix operations, translation, rotation, scaling |
| **2D Animation** | Time-based animation, frame updates |
| **Keyboard Input** | Keyboard event handling and controls |
| **Mouse Input** | Mouse clicks and movement tracking |

## 🎮 Controls (Common Across Projects)

- **ESC** - Exit program
- **SPACE** - Pause/Resume animation
- **Arrow Keys** - Move objects
- **R** - Reset/Restart
- **Mouse Click** - Interact with scenes

## 📚 Learning Resources

- [OpenGL Documentation](https://www.opengl.org/documentation/)
- [GLUT Reference](http://www.lighthouse3d.com/tutorials/glut-tutorial/)
- [LearnOpenGL](https://learnopengl.com/)
- [Computer Graphics Principles](https://www.scratchapixel.com/)

## 🐛 Troubleshooting

### Common Issues

**Linker Errors (undefined reference to `glXXX`)**
- Ensure OpenGL/GLUT libraries are properly linked: `-lGL -lGLU -lglut`

**GLUT Library Not Found**
- Install freeglut development package for your OS
- Check library paths in your IDE settings

**Window Won't Open**
- Verify X11 forwarding (if using SSH on Linux)
- Check display server configuration

**Animation Running Slow**
- Reduce `glutTimerFunc()` interval (lower value = faster updates)
- Optimize rendering code to reduce polygon count

## 📝 Assignment Guidelines

When submitting assignments:

1. **Code Structure** - Well-organized and commented
2. **Functionality** - All requirements met
3. **Documentation** - Include brief explanation of what the program does
4. **Compilation** - Provide exact compilation commands
5. **Screenshots** - Include output screenshots where applicable

## 📞 Support & Contributing

For issues, questions, or suggestions:
- Check existing issues in the repository
- Create a new issue with detailed description
- Include error messages and system information

## 📄 License

This educational repository is provided for learning purposes. Feel free to use and modify the code for your studies.

---

**Happy Learning! 🎨🖥️**

*Last Updated: May 7, 2026*
*Course: Computer Graphics - Spring 2025-26 Semester*
