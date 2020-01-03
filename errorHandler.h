#pragma once
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>

#define ASSERT(x) if(!(x)) __debugbreak();
#define GLCALL(x) GLClearError();\
	x;\
	ASSERT(GLLogCall(#x,__LINE__))

static void GLClearError()
{
	while(glGetError() != GL_NO_ERROR);
}

// returns false if soemthing happened. returns true if fine
static bool GLLogCall(const char* function, int line)
{
	while(GLenum error = glGetError()) {
		std::cout << error << ": " << function << "  line : " << line << "\n";
		return false;
	}
	return true;
}
