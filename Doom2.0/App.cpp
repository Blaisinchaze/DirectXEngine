#include "App.h"
#include <sstream>
#include <iomanip>
#include "Image.h"
namespace dx = DirectX;
App::App()
	:
	wnd(800,600,"Doom2.0")
{}

int App::Go()
{


	while (true)
	{
		{
			if (const auto ecode = Window::ProcessMessages())
			{
				return *ecode;
			}
			DoFrame();
		}
	}
}

void App::DoFrame()
{
	InputManager();
	const float c = sin(timer.Peek()) / 2.0f + 0.5f;
	wnd.Gfx().ClearBuffer(1.0f, 0.83f, 0.8f);
	wnd.Gfx().DrawTestTriangle(0.0f + xAngle,0.0f + yAngle,0.0f + zAngle,
		-5.0f + xOffset,0.0f + yOffset, 0.0f + zOffset,
		1,2,5);
	wnd.Gfx().DrawTestTriangle(0.0f + xAngle, 0.0f + yAngle, 0.0f + zAngle,
		+5.0f + xOffset, 0.0f + yOffset, 0.0f + zOffset,
		1, 2, 5);
	wnd.Gfx().DrawTestTriangle(0.0f + xAngle, 0.0f + yAngle, 0.0f + zAngle,
		0.0f + xOffset, 0.0f + yOffset, 5.0f + zOffset,
		5, 2, 1);	
	wnd.Gfx().DrawTestTriangle(0.0f + xAngle, 0.0f + yAngle, 0.0f + zAngle,
		0.0f + xOffset, 0.0f + yOffset, -5.0f + zOffset,
		5, 2, 1);
	wnd.Gfx().DrawTestTriangle(timer.Peek() + xAngle, timer.Peek() + yAngle, 0.0f + zAngle,
		0.0f + xOffset, 0.0f + yOffset, 0.0f + zOffset,
		0.2, 0.2, 0.2);

	wnd.Gfx().EndFrame();
}

void App::InputManager()
{
	if (wnd.kbd.KeyIsPressed('W'))
	{
		wnd.Gfx().GetCamera().zPos += dx::XMVectorGetZ(wnd.Gfx().GetCamera().forward) * 0.02f;
		wnd.Gfx().GetCamera().xPos += dx::XMVectorGetX(wnd.Gfx().GetCamera().forward) * 0.02f;
	}	
	if (wnd.kbd.KeyIsPressed('A'))
	{
		wnd.Gfx().GetCamera().zPos -= dx::XMVectorGetZ(wnd.Gfx().GetCamera().right) * 0.02f;
		wnd.Gfx().GetCamera().xPos -= dx::XMVectorGetX(wnd.Gfx().GetCamera().right) * 0.02f;
	}
	if (wnd.kbd.KeyIsPressed('S'))
	{
		wnd.Gfx().GetCamera().zPos -= dx::XMVectorGetZ(wnd.Gfx().GetCamera().forward) * 0.02f;
		wnd.Gfx().GetCamera().xPos -= dx::XMVectorGetX(wnd.Gfx().GetCamera().forward) * 0.02f;
	}
	if (wnd.kbd.KeyIsPressed('D'))
	{
		wnd.Gfx().GetCamera().zPos += dx::XMVectorGetZ(wnd.Gfx().GetCamera().right) * 0.02f;
		wnd.Gfx().GetCamera().xPos += dx::XMVectorGetX(wnd.Gfx().GetCamera().right) * 0.02f;
	}
	if (wnd.mouse.GetPosX() > 600 ||
		wnd.mouse.GetPosX() < 200)
	{
		turnSpeed += 0.001f;
		if (turnSpeed > 0.002)
		{
			turnSpeed = 0.02;
		}
		if (wnd.mouse.GetPosX() > 600)
			wnd.Gfx().GetCamera().xRotation -= turnSpeed;
		if (wnd.mouse.GetPosX() < 200)
			wnd.Gfx().GetCamera().xRotation += turnSpeed;
	}
	if (wnd.mouse.GetPosX() < 600 &&
		wnd.mouse.GetPosX() > 200)
	{
		turnSpeed -= 0.001f;
		if (turnSpeed <= 0)
			turnSpeed = 0;
	}
}
