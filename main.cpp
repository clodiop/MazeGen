#include <iostream>
#include <GL\glew.h>

#include <GLFW\glfw3.h>
#include "constants.h"
#include "MazeGen.h"

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "MAZE", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	glewInit();
	glGetError(); // Call it once to catch glewInit() bug, all other errors are now from our application.

	// OpenGL configuration
	glViewport(0, 0, WIDTH, HEIGHT);

	// Initialize game


	// Start Game within Menu State
	MazeGen* maze = new MazeGen;
	maze->setupMaze();

	while(!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		// Manage user input


		// Update Game state


		// Render
		glClearColor(0.0f, 0.4f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		maze->drawMaze();
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	//delete maze;

	return 0;
}