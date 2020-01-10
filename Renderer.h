#pragma once
#include <vector>
#include <GL\glew.h>
#include <glm\ext\matrix_transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm\glm.hpp>
#include "errorHandler.h"
#include "constants.h"


class Renderer
{
public:
	Renderer();

	/*	initializes the LINE vertex data...............	 ALWAYS DO THIS BEFORE drawing line!
	*/
	void initline();

	// actually draws the line, rotation is 0.0f by default
	void drawLine(glm::vec2 position, glm::vec2 size, glm::vec3 color, GLfloat rotate = 0.0f);
	//void drawLine(glm::vec2 position, glm::vec3 color, glm::vec2 size, GLfloat rotate = 0.0f);

	void initSquare();

	void drawSquare(glm::vec2 position, glm::vec2 ScaleSize, glm::vec3 color);

	~Renderer();
private:
	// initalized the shader with the default shader. ALWAYS DO THIS BEFORE initalizing vertex data
	void initShader();

	void compileShader(unsigned int shader, const char** ppShaderSrc);

	void linkProgram(unsigned int vertexShader, unsigned int fragmentShader);

	unsigned int VBO, VAO;
	unsigned int s_Shader;
	glm::mat4 projection;
};

// i should split the draw line and draw sqaure blah blah to different classes that inherit like a base renderer but that would make the project quite big..