#include <iostream>

#define GLEW_STATIC
#include <GL\glew.h>
#include <GLFW\glfw3.h>

using namespace std;
const GLint WIDTH = 800, HEIGHT = 600;

bool swapCulling = false;

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	//Al pulsar Esc cerrar aplicacion
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) glfwSetWindowShouldClose(window, GL_TRUE);
	if (key == GLFW_KEY_W && action == GLFW_PRESS) swapCulling = !swapCulling;
}

void drawSmailey();
void drawSmailey(GLfloat posX, GLfloat posY, GLfloat radius);
void drawHouse();

int main() {

	GLFWwindow* window;
	//glfwSetErrorCallback(error_callback);

	if (!glfwInit()) exit(EXIT_FAILURE);

	window = glfwCreateWindow(WIDTH, HEIGHT, "Primera Ventana", nullptr, nullptr);
	if (!window) {
		cout << "Error al crear ventana" << endl;
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);

	glewExperimental = GLU_TRUE;

	if (GLEW_OK != glewInit()) {
		cout << "Error al iniciar glew" << endl;
		glfwTerminate();
		return NULL;
	}

	glfwSetKeyCallback(window, key_callback);
	int screenWidth, screenHeight;
	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

	while (!glfwWindowShouldClose(window)) {

		glViewport(0, 0, screenWidth, screenHeight);
		glClear(GL_COLOR_BUFFER_BIT);

		glClearColor(0.0, 1.0, 1.0, 1.0);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-10, 10, -10, 10, -1, 10);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		//Draw Point
		/*glPointSize(25.0);
		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POINTS);
		glVertex3f(-9.5, 5, 0.0);
		glEnd();

		//Draw Line
		glLineWidth(10.0);
		glBegin(GL_LINES);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-9.5, 7, 0.0);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(9.5, 7, 0.0);
		glEnd();

		//Draw LineStrip
		glLineWidth(5.0);
		glBegin(GL_LINE_STRIP);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-9.5, 8, 0.0);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(9.5, 8, 0.0);
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(9.5, 9.5, 0.0);
		glEnd();

		//Draw LineLoop
		glLineWidth(5.0);
		glBegin(GL_LINE_LOOP);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-9.5, -8, 0.0);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(9.5, -8, 0.0);
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(9.5, -9.5, 0.0);
		glEnd();*/

		//Draw LineStipple
		/*glLineWidth(2.0);
		glEnable(GL_LINE_STIPPLE);
		for (int i = 0; i < 7; i++) {
			glTranslatef(1.0, 0.0, 0.0);
			glLineStipple(i, 0xAAAA);
			glBegin(GL_LINES);
			glColor3f(1.0, 1.0, 1.0);
			glVertex3f(9.5, -8, 0.0);
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(9.5, -9.5, 0.0);
		}*/

		//Draw Triangle
		/*glBegin(GL_TRIANGLES);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(0.f, 0.f, 0.0f);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(-5.f, 5.f, 0.0f);
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(5.f, 5.f, 0.0f);
		glEnd();

		//Draw Polygon
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		glFrontFace(GL_CCW);
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(5.f, 6.f, 0.0f);
		glVertex3f(6.f, 6.f, 0.0f);
		glVertex3f(6.5f, 6.5f, 0.0f);
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(6.f, 7.f, 0.0f);
		glVertex3f(5.f, 7.f, 0.0f);
		glVertex3f(4.5f, 6.5f, 0.0f);
		glEnd();*/

		//Draw Quad
		/*glBegin(GL_QUADS);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(2.f, 2.f, 0.0f);
		glVertex3f(1.f, 2.f, 0.0f);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(1.5f, 3.f, 0.0f);
		glVertex3f(2.5f, 3.f, 0.0f);
		glEnd();*/

		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);

		if (swapCulling) {
			glFrontFace(GL_CW);
		} else {
			glFrontFace(GL_CCW);
		}

		//Grass
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.5f, 1.0f, 0.5f);
		glVertex3f(-10.0f, -10.0f, 0.0f);
		glVertex3f(10.0f, -10.0f, 0.0f);
		glVertex3f(-10.0f, -6.5f, 0.0f);

		glVertex3f(10.0f, -6.5f, 0.0f);

		glVertex3f(-9.0f, -6.4f, 0.0f);
		glVertex3f(-8.0f, -6.4f, 0.0f);
		glVertex3f(-8.0f, -6.2f, 0.0f);
		glVertex3f(-6.0f, -6.4f, 0.0f);
		glVertex3f(-6.0f, -6.0f, 0.0f);
		glVertex3f(-5.0f, -6.5f, 0.0f);
		glVertex3f(-5.0f, -6.3f, 0.0f);
		glVertex3f(-4.0f, -6.5f, 0.0f);
		glVertex3f(-4.0f, -6.2f, 0.0f);
		glVertex3f(-3.0f, -6.5f, 0.0f);
		glVertex3f(3.0f, -6.5f, 0.0f);
		glVertex3f(4.0f, -6.5f, 0.0f);
		glVertex3f(4.0f, -6.2f, 0.0f);
		glVertex3f(5.0f, -6.5f, 0.0f);
		glVertex3f(5.0f, -6.3f, 0.0f);
		glVertex3f(6.0f, -6.5f, 0.0f);
		glVertex3f(6.0f, -6.0f, 0.0f);
		glVertex3f(7.0f, -6.5f, 0.0f);
		glVertex3f(8.0f, -6.0f, 0.0f);
		glVertex3f(8.0f, -6.5f, 0.0f);
		glVertex3f(10.0f, -6.3f, 0.0f);
		glVertex3f(10.0f, -6.5f, 0.0f);
		glEnd();

		//Street
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.5f, 0.5f, 0.5f);
		glVertex3f(-10.0f, -10.0f, 0.0f);
		glVertex3f(10.0f, -10.0f, 0.0f);
		glVertex3f(-10.0f, -8.5f, 0.0f);

		glVertex3f(10.0f, -8.5f, 0.0f);

		glVertex3f(-9.0f, -8.4f, 0.0f);
		glVertex3f(-8.0f, -8.4f, 0.0f);
		glVertex3f(-8.0f, -8.1f, 0.0f);
		glVertex3f(-6.0f, -8.4f, 0.0f);
		glVertex3f(-6.0f, -8.2f, 0.0f);
		glVertex3f(-5.0f, -8.5f, 0.0f);
		glVertex3f(-5.0f, -8.3f, 0.0f);
		glVertex3f(-4.0f, -8.5f, 0.0f);
		glVertex3f(-4.0f, -8.2f, 0.0f);
		glVertex3f(-3.0f, -8.5f, 0.0f);
		glVertex3f(3.0f, -8.4f, 0.0f);
		glVertex3f(4.0f, -8.5f, 0.0f);
		glVertex3f(4.0f, -8.3f, 0.0f);
		glVertex3f(5.0f, -8.5f, 0.0f);
		glVertex3f(5.0f, -8.2f, 0.0f);
		glVertex3f(6.0f, -8.5f, 0.0f);
		glVertex3f(6.0f, -8.0f, 0.0f);
		glVertex3f(7.0f, -8.5f, 0.0f);
		glVertex3f(8.0f, -8.0f, 0.0f);
		glVertex3f(8.0f, -8.5f, 0.0f);
		glVertex3f(10.0f, -8.3f, 0.0f);
		glVertex3f(10.0f, -8.5f, 0.0f);
		glEnd();

		drawHouse();

		drawSmailey(-8, 7, 1.5f);

		glfwSwapBuffers(window);
		glfwPollEvents();

	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);

	return 0;
}

void drawHouse() {
	//House
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.9f, 0.6f, 0.1f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-3.0f, -3.0f, 0.0f);
	glVertex3f(3.0f, -3.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-3.0f, -3.0f, 0.0f);
	glVertex3f(-3.0f, -9.0f, 0.0f);
	glVertex3f(3.0f, -9.0f, 0.0f);
	glVertex3f(3.0f, -3.0f, 0.0f);
	glEnd();

	//Door
	glBegin(GL_QUADS);
	glColor3f(0.9f, 0.6f, 0.1f);
	glVertex3f(-1.0f, -6.0f, 0.0f);
	glVertex3f(-1.0f, -9.0f, 0.0f);
	glVertex3f(1.0f, -9.0f, 0.0f);
	glVertex3f(1.0f, -6.0f, 0.0f);
	glEnd();

	glLineWidth(1.0f);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, -6.0f, 0.0f);
	glVertex3f(0.0f, -9.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.1f, -7.5f, 0.0f);
	glVertex3f(0.1f, -7.6f, 0.0f);
	glVertex3f(0.3f, -7.6f, 0.0f);
	glVertex3f(0.3f, -7.5f, 0.0f);

	glVertex3f(-0.3f, -7.5f, 0.0f);
	glVertex3f(-0.3f, -7.6f, 0.0f);
	glVertex3f(-0.1f, -7.6f, 0.0f);
	glVertex3f(-0.1f, -7.5f, 0.0f);
	glEnd();

	//Windows
	glBegin(GL_QUADS);
	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-2.25f, -3.5f, 0.0f);
	glVertex3f(-2.25f, -5.0f, 0.0f);
	glVertex3f(-1.0f, -5.0f, 0.0f);
	glVertex3f(-1.0f, -3.5f, 0.0f);

	glVertex3f(1.0f, -3.5f, 0.0f);
	glVertex3f(1.0f, -5.0f, 0.0f);
	glVertex3f(2.25f, -5.0f, 0.0f);
	glVertex3f(2.25f, -3.5f, 0.0f);
	glEnd();

	glLineWidth(1.0f);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-1.6f, -3.5f, 0.0f);
	glVertex3f(-1.6f, -5.0f, 0.0f);
	glVertex3f(-1.0f, -4.25f, 0.0f);
	glVertex3f(-2.25f, -4.25f, 0.0f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(1.6f, -3.5f, 0.0f);
	glVertex3f(1.6f, -5.0f, 0.0f);
	glVertex3f(1.0f, -4.25f, 0.0f);
	glVertex3f(2.25f, -4.25f, 0.0f);
	glEnd();

	//Chimney
	glBegin(GL_QUADS);
	glColor3f(0.75f, 0.45f, 0.02f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glVertex3f(2.0f, -2.0f, 0.0f);
	glVertex3f(2.0f, 1.0f, 0.0f);

	glColor3f(0.6f, 0.3f, 0.0f);
	glVertex3f(0.9f, 1.0f, 0.0f);
	glVertex3f(0.9f, 0.85f, 0.0f);
	glVertex3f(2.1f, 0.85f, 0.0f);
	glVertex3f(2.1f, 1.0f, 0.0f);
	glEnd();
}

void drawSmailey(GLfloat posX, GLfloat posY, GLfloat radius) {

	//Face
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(posX, posY, 0.0f);
	for (int i = 0; i <= 50; i++) {
		glVertex3f(posX + (radius * cos(i * (3.14f * 2.0f) / 50.0f)), posY + (radius * sin(i * (3.14f * 2.0f) / 50.0f) * 1.5f), 0.0f);
	}
	glEnd();

	//Eyes
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	for (int i = 0; i <= 20; i++) {
		glVertex3f(posX - (radius / 2.65f) + ((radius / 8) * cos(i * 3.14f / 20.0f)), posY + (radius / 2.65f) + ((radius / 8) * sin(i * 3.14f / 20.0f) * 1.75f), 0.0f);
	}
	glVertex3f(posX - (radius / 2), posY + (radius / 4), 0.0f);
	glVertex3f(posX - (radius / 4), posY + (radius / 4), 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	for (int i = 0; i <= 20; i++) {
		glVertex3f(posX + (radius / 2.65f) + ((radius / 8) * cos(i * 3.14f / 20.0f)), posY + (radius / 2.65f) + ((radius / 8) * sin(i * 3.14f / 20.0f) * 1.75f), 0.0f);
	}
	glVertex3f(posX + (radius / 4), posY + (radius / 4), 0.0f);
	glVertex3f(posX + (radius / 2), posY + (radius / 4), 0.0f);
	glEnd();

	glPointSize(radius*5);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POINTS);
	glVertex3f(posX - (radius / 3.05f), posY + (radius / 3.05f), 0.0f);
	glVertex3f(posX + (radius / 2.35f), posY + (radius / 3.05f), 0.0f);
	glEnd();

	//Mouth
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	for (int i = 20; i >= 0; i--) {
		glVertex3f(posX + ((radius / 2) * cos(i * 3.14f / 20.0f)), posY - (radius / 2.65f) + ((radius / 2) * sin(i * 3.14f / 20.0f) * -1.0f), 0.0f);
	}
	glEnd();
}

void drawSmailey() {
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);

	//Draw SMILE
	//Face
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	for (int i = 0; i <= 50; i++) {
		glVertex3f((2.0f * cos(i * (3.14f * 2.0f) / 50.0f)), (2.0f * sin(i * (3.14f * 2.0f) / 50.0f) * 1.5f), 0.0f);
	}
	glEnd();

	//Eyes
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	for (int i = 0; i <= 20; i++) {
		glVertex3f(-0.75f + (0.25f * cos(i * 3.14f / 20.0f)), 0.75f + (0.25f * sin(i * 3.14f / 20.0f) * 1.75f), 0.0f);
	}
	glVertex3f(-1.0f, 0.5f, 0.0f);
	glVertex3f(-0.5f, 0.5f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	for (int i = 0; i <= 20; i++) {
		glVertex3f(0.75f + (0.25f * cos(i * 3.14f / 20.0f)), 0.75f + (0.25f * sin(i * 3.14f / 20.0f) * 1.75f), 0.0f);
	}
	glVertex3f(0.5f, 0.5f, 0.0f);
	glVertex3f(1.0f, 0.5f, 0.0f);
	glEnd();

	glPointSize(10.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POINTS);
	glVertex3f(-0.65f, 0.65f, 0.0f);
	glVertex3f(0.85f, 0.65f, 0.0f);
	glEnd();

	//Mouth
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	for (int i = 20; i >= 0; i--) {
		glVertex3f((1.0f * cos(i * 3.14f / 20.0f)), -0.75f + (1.0f * sin(i * 3.14f / 20.0f) * -1.0f), 0.0f);
	}
	glEnd();
}