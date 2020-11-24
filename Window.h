#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

typedef unsigned int uint;
//struct GLFWwindow;

class Window
{
public:
	static int width;
	static int height;
	static double deltaTime;
	static GLFWwindow* window;

	static int Init(const uint width, const uint height, const char* title);
	static void Terminate();

	static bool IsShouldClose();
	static void SetShouldClose(bool flag);
	static void SetCursorMode(int mode);
	static void SwapBuffers();
};
