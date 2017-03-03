#include <iostream>

#define GLEW_STATIC
#include <GL\glew.h>
#include <GLFW\glfw3.h>

using namespace std;
const GLint WIDTH = 800, HEIGHT = 600;

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	//Al pulsar Esc cerrar aplicacion
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) glfwSetWindowShouldClose(window, GL_TRUE);
}

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

	//glfwSetKeyCallback(window, key_callback);
	int screenWidth, screenHeight;
	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

	while (!glfwWindowShouldClose(window)) {

		glViewport(0, 0, screenWidth, screenHeight);
		glClear(GL_COLOR_BUFFER_BIT);

		glClearColor(1.0, 0.0, 0.0, 1.0);

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

		//Draw SMILE
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		glFrontFace(GL_CCW);
		glBegin(GL_POLYGON);

		glColor3f(1.0, 1.0, 0.0);

		//Face
		glVertex3f(0.0, 3.0, 0.0);

		glVertex3f(-1.5, 2.5, 0.0);
		glVertex3f(-2.5, 1.5, 0.0);

		glVertex3f(-3.0, 0.0, 0.0);
		
		glVertex3f(-2.5, -1.5, 0.0);
		glVertex3f(-1.5, -2.5, 0.0);

		glVertex3f(0.0, -3.0, 0.0);

		glVertex3f(1.5, -2.5, 0.0);
		glVertex3f(2.5, -1.5, 0.0);

		glVertex3f(3.0, 0.0, 0.0);

		glVertex3f(2.5, 1.5, 0.0);
		glVertex3f(1.5, 2.5, 0.0);
		glEnd();
		
		//Eyes
		glPointSize(15.0);
		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POINTS);
		glVertex3f(1.0, 0.5, 0.0);
		glVertex3f(-1.0, 0.5, 0.0);
		glEnd();


		glfwSwapBuffers(window);
		glfwPollEvents();

	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);

	return 0;
}