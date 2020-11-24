#include <iostream>
#include "console_color.h"
#include "Window.h"

GLFWwindow* Window::window;
int Window::width = 0;
int Window::height = 0;
double Window::deltaTime = 0.0;

int Window::Init(const uint width, const uint height, const char* title)
{
	// GLFW initialization
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // for MacOS X
#endif

	// Creating window
	window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if (window == nullptr)
	{
		SetErrorColor(std::cout << "Failed to create GLFW window" << std::endl);
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// GLAD initialization
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		SetErrorColor(std::cout << "Failed to initialize GLAD" << std::endl);
		return -1;
	}

	SetOkColor(std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl);
	SetOkColor(std::cout << "Vendor: " << glGetString(GL_VENDOR) << " Renderer: " << glGetString(GL_RENDERER) << std::endl);
	
	glEnable(GL_DEPTH_TEST);

	Window::width = width;
	Window::height = height;

	glViewport(0, 0, width, height);
	return 0;
}

void Window::Terminate()
{
	glfwTerminate();
}

bool Window::IsShouldClose()
{
	return glfwWindowShouldClose(window);
}

void Window::SetShouldClose(bool flag)
{
	glfwSetWindowShouldClose(window, flag);
}

void Window::SetCursorMode(int mode)
{
	glfwSetInputMode(window, GLFW_CURSOR, mode);
}

void Window::SwapBuffers()
{
	glfwSwapBuffers(window);
}
