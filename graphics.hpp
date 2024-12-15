#pragma once
#include "glad.h"
#include <thread>
#include <vector>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <Windows.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#define GLFW_EXPOSE_NATIVE_WGL
#define GLFW_NATIVE_INCLUDE_NONE
#include <GLFW/glfw3native.h>
#include "Shader.h"
#define CHUJ
typedef struct vec2
{
	float x;
	float y;
} vec2;

GLFWwindow* createWin();
void renderLine(unsigned int lin, unsigned int shader);
int setup(GLFWwindow* win);
unsigned int setupGrid(glm::vec3 color);
void renderGrid(unsigned int data, unsigned int shader);
unsigned int genLine(glm::vec4 lin, glm::vec3 col1, glm::vec3 col2);
