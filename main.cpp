// GlfwTest1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <GLFW\glfw3.h>

static void error_callback(int error, const char* description) 
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

int main()
{
	GLFWwindow * window; //creates GLFW window
	glfwSetErrorCallback(error_callback); //enables error report
	
	glfwInit(); //initializes glfw library
	if (!glfwInit()) //makes sure initialization has happened
	{
		exit(EXIT_FAILURE);
	}
	window = glfwCreateWindow(640, 480, "My first window", NULL, NULL); //makes the window into a glfw window object
	if (!window) //checks for window creation
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window); //makes the OpenGL context current (?)
	glfwSetKeyCallback(window, key_callback); //setting callback to close window
	while (!glfwWindowShouldClose(window)) //keeps window open
	{
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		glViewport(0,0,width,height);

		glfwSwapBuffers(window);
		//glfwPollEvents();
	}

	glfwDestroyWindow(window); //frees memory taken by the window
	glfwTerminate(); //removes glfw library usage
	exit (EXIT_SUCCESS);
}
