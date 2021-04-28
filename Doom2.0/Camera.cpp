#include "Camera.h"

namespace dx = DirectX;

DirectX::XMMATRIX Camera::GetMatrix() noexcept
{
    dx::XMMATRIX transformMatrix = dx::XMMatrixIdentity();
    transformMatrix = dx::XMMatrixRotationRollPitchYaw(zRotation, xRotation, yRotation)*
        dx::XMMatrixTranslation(xPos,yPos,zPos);
    dx::XMMATRIX inverse = dx::XMMatrixInverse(nullptr, transformMatrix);

    forward = dx::XMVector3Normalize(inverse.r[2]);
    right = dx::XMVector3Normalize(inverse.r[0]);

    const auto pos = dx::XMVector3Transform(
        dx::XMVectorSet(xPos, yPos, zPos, 0.0f),
        dx::XMMatrixRotationRollPitchYaw(phi, -theta, 0.0f)
    );
    return dx::XMMatrixLookAtLH(
        pos,
        dx::XMVectorAdd(pos, forward),
        //dx::XMVectorSet(xLookAt, yLookAt, zLookAt, 0.0f),
        dx::XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f)
    );
}

void Camera::setRotation(float p, float y, float r)
{
    pitch += p;
    yaw += y;
    roll += r;
}

void Camera::setPosition(float x, float y, float z)
{
}
