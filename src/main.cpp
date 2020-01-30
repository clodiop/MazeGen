#include <iostream>
#include <GL\glew.h>

#include <GLFW\glfw3.h>
#include "constants.h"
#include "MazeGen.h"

#include <Windows.h>

int main()
{
	if(!glfwInit())
		return -1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(800, 800, "MAZE", nullptr, nullptr);
	if(!window)
	{
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	glewInit();
	glGetError(); // Call it once to catch glewInit() bug, all other errors are now from our application.

	// OpenGL configuration
	glViewport(0, 0, 800, 800);

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
	delete maze;

	return 0;
}