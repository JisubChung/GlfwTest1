// GlfwTest1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define GLFW_INCLUDE_GLU
#include <GLFW\glfw3.h>

int main()
{
	glfwInit();
	GLFWwindow * window = glfwCreateWindow(640, 480, "My first window", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return (0);
	}

	glfwMakeContextCurrent(window);

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}

