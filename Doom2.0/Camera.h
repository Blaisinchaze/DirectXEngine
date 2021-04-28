#pragma once
//#include "Graphics.h"

#include <DirectXMath.h>
namespace dx = DirectX;
class Camera
{
public:
	DirectX::XMMATRIX GetMatrix() noexcept;
	Camera() = default;
	~Camera() = default;


	void setRotation(float p, float y, float r);
	void setPosition(float x, float y, float z);

	float Distance = 20.0f;
	float theta = 0.0f;
	float phi = 0.0f;
	float pitch = 0.0f;
	float yaw = 0.0f;
	float roll = 0.0f;

	float xLookAt = 0.0f;
	float yLookAt = 0.0f;
	float zLookAt = 0.0f;

	float xPos = 0.0f;
	float yPos = 0.0f;
	float zPos = -1.0f;

	float xRotation = 0.0f;
	float yRotation = 0.0f;
	float zRotation = 0.0f;

	dx::XMVECTOR forward;
	dx::XMVECTOR right;

};


