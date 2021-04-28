#pragma once
#include "Window.h"
#include "Timer.h"
#include "Camera.h"

class App
{
public:
	App();
	int Go();
private:
	void DoFrame();
	void InputManager();
private:
	Window wnd;
	Timer timer;
	Camera cam;
	float xOffset = 0;
	float yOffset = 0;
	float zOffset = 0;
	float xAngle = 0;
	float yAngle = 0;
	float zAngle = 0;
	float xScale = 0;
	float yScale = 0;
	float zScale = 0;

	float turnSpeed = 0;
};

