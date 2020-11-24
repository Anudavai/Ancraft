#pragma once
#include "Window.h"
#include "Camera.h"

class EventManager
{
public:
	static bool* _keys;
	static uint* _frames;
	static uint _current;
	static float deltaX;
	static float deltaY;
	static float x;
	static float y;
	static bool _cursor_locked;
	static bool _cursor_started;

	static int Init();
	static void PullEvents();

	static bool IsPressed(int keycode);
	static bool JustPressed(int keycode);

	static bool IsClicked(int button);
	static bool JustClicked(int button);

	static void ToogleCursor();
};
