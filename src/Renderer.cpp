#include "Renderer.h"

Renderer::Renderer()
{
	projection = glm::ortho(0.0f, 800.0f, 800.0f, 0.0f, -1.0f, 1.0f);
	initShader();
}

void Renderer::initline()
{
	float vertices[] = {
		-1.0, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0);
}

void Renderer::drawLine(glm::vec2 position, glm::vec2 size, glm::vec3 color, GLfloat rotate)
{
	GLCALL(glUseProgram(s_Shader));

	glm::mat4 model = glm::mat4(1.0f);

	model = glm::translate(glm::mat4(1.0f), glm::vec3(position.x, position.y, 0.0f)); // position of the line

	model = glm::rotate(model, glm::radians(rotate), glm::vec3(0.0f, 0.0f, 1.0f)); // rotates the line
	model = glm::translate(model, glm::vec3(size.x, size.y, 0.0f)); // shifts the position of the box by sizeX again

	model = glm::scale(model, glm::vec3(size.x, size.y, 0.0f));


	glUniform3f(glGetUniformLocation(s_Shader, "u_Color"), color.r, color.g, color.b);
	glUniformMatrix4fv(glGetUniformLocation(s_Shader, "u_Model"), 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(glGetUniformLocation(s_Shader, "u_Projection"), 1, GL_FALSE, glm::value_ptr(projection));

	glBindVertexArray(VAO);
	GLCALL(glDrawArrays(GL_LINES, 0, 2));
}

void Renderer::initSquare()
{
	float vertices[] = {
		// first triangle
		 0.5f,  0.5f, 0.0f,  // top right
		 0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f,  0.5f, 0.0f,  // top left 
		// second triangle
		 0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  // bottom left
		-0.5f,  0.5f, 0.0f   // top left
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0);
}

void Renderer::drawSquare(glm::vec2 position, glm::vec2 ScaleSize, glm::vec3 color)
{
	GLCALL(glUseProgram(s_Shader));

	glm::mat4 model = glm::mat4(1.0f);

	model = glm::translate(glm::mat4(1.0f), glm::vec3(position.x, position.y, 0.0f)); // sets the position of the square

	model = glm::translate(model, glm::vec3(0.5f * ScaleSize.x, 0.5f * ScaleSize.y, 0.0f)); // take the scaling into account

	model = glm::scale(model, glm::vec3(ScaleSize.x, ScaleSize.y, 1.0f)); // scales the square

	glUniform3f(glGetUniformLocation(s_Shader, "u_Color"), color.r, color.g, color.b);
	glUniformMatrix4fv(glGetUniformLocation(s_Shader, "u_Model"), 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(glGetUniformLocation(s_Shader, "u_Projection"), 1, GL_FALSE, glm::value_ptr(projection));

	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);
}

void Renderer::initShader()
{
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	const char* VertexShaderSrc{
		"#version 330 core\n"
		"layout(location = 0) in vec2 v_Pos;\n"
		"uniform mat4 u_Model;\n"
		"uniform mat4 u_Projection;\n"
		"void main() {\n"
		"	gl_Position = u_Projection * u_Model * vec4(v_Pos, 0.0, 1.0);\n"
		"}\0"
	};
	const char* FragmentShaderSrc{
		"#version 330 core\n"
		"out vec4 FragColor;\n"
		"uniform vec3 u_Color;\n"
		"void main() {\n"
		"	FragColor = vec4(u_Color.r, u_Color.g, u_Color.b, 1.0f);\n"
		"}\0"
	};

	compileShader(vertexShader, &VertexShaderSrc);
	compileShader(fragmentShader, &FragmentShaderSrc);
	linkProgram(vertexShader, fragmentShader);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

Renderer::~Renderer()
{
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);
	glDeleteProgram(s_Shader);
}

void Renderer::compileShader(unsigned int shader, const char** ppShaderSrc)
{
	glShaderSource(shader, 1, ppShaderSrc, nullptr);
	glCompileShader(shader);
#ifdef _DEBUG
	int success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		char infoLog[512];
		glGetShaderInfoLog(shader, 512, nullptr, infoLog);
		//LOG_ERROR("Failed to compile Shader. InfoLog:\n{0}", infoLog);
		__debugbreak();
	}
#endif
}

void Renderer::linkProgram(unsigned int vertexShader, unsigned int fragmentShader)
{
	s_Shader = glCreateProgram();
	glAttachShader(s_Shader, vertexShader);
	glAttachShader(s_Shader, fragmentShader);
	glLinkProgram(s_Shader);

#ifdef _DEBUG
	int success;
	glGetShaderiv(s_Shader, GL_LINK_STATUS, &success);
	if(!success)
	{
		char infoLog[512];
		glGetShaderInfoLog(s_Shader, 512, nullptr, infoLog);
		//LOG_ERROR("Failed to link Program. InfoLog:\n{0}", infoLog);
		__debugbreak();
	}
#endif
}
