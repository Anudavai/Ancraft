#include "EventManager.h"
#include <string.h>

bool* EventManager::_keys;
uint* EventManager::_frames;
uint EventManager::_current = 0;
float EventManager::deltaX = 0.0f;
float EventManager::deltaY = 0.0f;
float EventManager::x = 0.0f;
float EventManager::y = 0.0f;
bool EventManager::_cursor_locked = false;
bool EventManager::_cursor_started = false;

Camera camera(glm::vec3(0.0f, 0.0f, 4.0f));

#define _MOUSE_BUTTONS 1024

void CursorPos_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (EventManager::_cursor_started) {
		EventManager::deltaX += xpos - EventManager::x;
		EventManager::deltaY += ypos - EventManager::y;
	}
	else
	{
		EventManager::_cursor_started = true;
	}
	EventManager::x = xpos;
	EventManager::y = ypos;
	//

	camera.ProcessMouseMovement(EventManager::deltaX, -EventManager::deltaY);
}

void MouseClick_callback(GLFWwindow* window, int button, int action, int mode)
{
	if (action == GLFW_PRESS) {
		EventManager::_keys[_MOUSE_BUTTONS + button] = true;
		EventManager::_frames[_MOUSE_BUTTONS + button] = EventManager::_current;
	}
	else if (action == GLFW_RELEASE) {
		EventManager::_keys[_MOUSE_BUTTONS + button] = false;
		EventManager::_frames[_MOUSE_BUTTONS + button] = EventManager::_current;
	}
}

void KeyClick_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (action == GLFW_PRESS) {
		EventManager::_keys[key] = true;
		EventManager::_frames[key] = EventManager::_current;
	}
	else if (action == GLFW_RELEASE)
	{
		EventManager::_keys[key] = false;
		EventManager::_frames[key] = EventManager::_current;
	}
}

void WindowResize_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	Window::width = width;
	Window::height = height;
}

int EventManager::Init()
{
	GLFWwindow* window = Window::window;
	_keys = new bool[1032];
	_frames = new uint[1032];

	memset(_keys, false, 1032 * sizeof(bool));
	memset(_frames, 0, 1032 * sizeof(uint));

	glfwSetKeyCallback(window, KeyClick_callback);
	glfwSetMouseButtonCallback(window, MouseClick_callback);
	glfwSetCursorPosCallback(window, CursorPos_callback);
	glfwSetWindowSizeCallback(window, WindowResize_callback);
	return 0;
}

bool EventManager::IsPressed(int keycode)
{
	if (keycode < 0 || keycode >= _MOUSE_BUTTONS)
		return false;
	return _keys[keycode];
}

bool EventManager::JustPressed(int keycode)
{
	if (keycode < 0 || keycode >= _MOUSE_BUTTONS)
		return false;
	return _keys[keycode] && _frames[keycode] == _current;
}

bool EventManager::IsClicked(int button)
{
	int index = _MOUSE_BUTTONS + button;
	return _keys[index];
}

bool EventManager::JustClicked(int button)
{
	int index = _MOUSE_BUTTONS + button;
	return _keys[index] && _frames[index] == _current;
}

void EventManager::ToogleCursor()
{
	_cursor_locked = !_cursor_locked;
	Window::SetCursorMode(_cursor_locked ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL);
}

void EventManager::PullEvents()
{
	_current++;
	deltaX = 0.0f;
	deltaY = 0.0f;
	glfwPollEvents();
}
