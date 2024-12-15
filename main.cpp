#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include "graphics.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <immintrin.h>
#pragma warning( disable : 4996)
typedef struct
{
	double x, y;
}dot;


int main()
{
	int points = 3;
	double factor1 = 1, factor2 = 2;
	glm::vec3 col = { 1.0f,0.0f,0.0f };
	GLFWwindow* win = createWin();
	setup(win);
	const double PI = 22.l / 7.l;
	unsigned int grid = setupGrid(col);
	unsigned int shader = genShader("vertex.txt", "fragment.txt");
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	dot* circleDots = (dot*)malloc(sizeof(dot) * points);
	for (int i = 0; i < points; i++)
	{
		circleDots[i].x = sin(((360.l / points) * (double)(i)) * (PI / 180.l)) + 2.l;
		circleDots[i].y = cos(((360.l / points) * (double)(i)) * (PI / 180.l)) + 2.l;
	}
	double factor = (double)factor1 / (double)factor2;
	unsigned short rand1 = 0;
	dot current = { 1,1 };
	std::vector<unsigned int> dots;
	glfwSwapInterval(0);
	for (int i = 0; i < 1000000; i++)
	{
		_rdrand16_step(&rand1);
		dot acLine = { (current.x + fabs(current.x - circleDots[rand1 % points].x) * factor)-1.l,(current.y + fabs(current.y - circleDots[rand1 % points].y) * factor) - 1.l };
		current = acLine;
		unsigned int xp = genLine({ (acLine.x - 0.0008)  ,(acLine.y )  ,(acLine.x )  ,(acLine.y )  }, { 1.0f,1.0f,1.0f }, { 1.0f,1.0f,1.0f });
		dots.push_back(xp);
	}
	while (!glfwWindowShouldClose(win))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glfwPollEvents();
		glUseProgram(shader);
		
		//renderGrid(grid, shader);
		for (int i = 0; i < dots.size(); i++)
			renderLine(dots[i],shader);
		glfwSwapBuffers(win);
	}
	ExitProcess(0);
}