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
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


unsigned int genShader(const char* vertexPath, const char* fragmentPath);
void checkCompileErrors(GLuint shader, std::string type);