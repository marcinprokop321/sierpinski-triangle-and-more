#include "graphics.hpp"


GLFWwindow* createWin()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	GLFWwindow* window;
	int count = 1;
	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	window = glfwCreateWindow(mode->height, mode->height, "Calculator", NULL,NULL);
	return window;
}

void renderLine(unsigned int lin, unsigned int shader)
{
	glUseProgram(shader);
	glBindVertexArray(lin);
	glDrawArrays(GL_LINES, 0, 2);
}

int setup(GLFWwindow* win)
{
	glfwMakeContextCurrent(win);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	return 1;
}
unsigned int setupGrid(glm::vec3 color)
{
	float* data = (float*)malloc(256*sizeof(float));
	for (float x = -16.0f; x < 16.0f; x += 1)
	{
			data[(int)((x+16)*4)] = x / 16;
			data[(int)((x + 16) * 4)+1] = -1.0f;
			data[(int)((x + 16) * 4)+2] = x/16;
			data[(int)((x + 16) * 4) + 3] = 1.0f;
	}
	for (float x = -16.0f; x < 16.0f; x += 1)
	{
		data[(int)((x + 16) * 4)+128] = -1.0f;
		data[(int)((x + 16) * 4) + 129] = x / 16;
		data[(int)((x + 16) * 4) + 130] = 1.0f;
		data[(int)((x + 16) * 4) + 131] = x / 16;
	}
	unsigned int VAO;
	unsigned int VBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, 256*sizeof(float), data, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	free(data);
	return VAO;
}
void renderGrid(unsigned int data, unsigned int shader)
{
	glUseProgram(shader);
	glBindVertexArray(data);
	glDrawArrays(GL_LINES, 0, 128);
}

unsigned int genLine(glm::vec4 lin, glm::vec3 col1, glm::vec3 col2, unsigned int *vbo)
{
	float* data = (float*)malloc(10*sizeof(float));
	data[0] = lin.x;
	data[1] = lin.y;
	data[2] = col1.x;
	data[3] = col1.y;
	data[4] = col1.z;
	data[5] = lin.z;
	data[6] = lin.w;
	data[7] = col2.x;
	data[8] = col2.y;
	data[9] = col2.z;
	unsigned int VAO;
	unsigned int VBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, 10 * sizeof(float), data, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2*sizeof(float)));
	glEnableVertexAttribArray(1);
	free(data);
	*vbo = VBO;
	return VAO;
}
