#include <iostream>
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include "constants.h"
#include "Renderer.h"
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


	// DeltaTime variables
	GLfloat deltaTime = 0.0f;
	GLfloat lastFrame = 0.0f;

	// Start Game within Menu State
	//Renderer ren;
	//ren.initSquare();
	MazeGen maze;
	maze.setupMaze();

	while(!glfwWindowShouldClose(window))
	{
		// Calculate delta time
		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		glfwPollEvents();
		// Manage user input


		// Update Game state


		// Render
		glClearColor(0.0f, 0.4f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		//ren.drawSquare(glm::vec2(0, 0), glm::vec2(40, 40), glm::vec3(0.0f, 1.0f, 0.0f));
		maze.drawMaze();
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}