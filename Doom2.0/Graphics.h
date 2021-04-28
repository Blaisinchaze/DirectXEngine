#pragma once
#include "CleanWindows.h"
#include <d3d11.h>
#include <wrl.h>
#include <DirectXMath.h>
#include "Camera.h"
#include "Image.h"

class Graphics
{
public:

	Graphics(HWND hWnd);
	Graphics(const Graphics&) = delete;
	Graphics& operator = (const Graphics&) = delete;
	~Graphics() = default;
	Camera& GetCamera();
	void EndFrame();
	void ClearBuffer(float red, float green, float blue) noexcept;
	void DrawTestTriangle(float angleX, float angleY, float angleZ, float x, float y, float z, float xScale, float yScale, float zScale);
	void Vertex();
private:
	DirectX::XMMATRIX projection = dx::XMMatrixIdentity();
	Microsoft::WRL::ComPtr<ID3D11Device> pDevice ;
	Microsoft::WRL::ComPtr < IDXGISwapChain> pSwap;
	Microsoft::WRL::ComPtr < ID3D11DeviceContext> pContext;
	Microsoft::WRL::ComPtr < ID3D11RenderTargetView> pTarget;
	Microsoft::WRL::ComPtr < ID3D11DepthStencilView> pDSV;
	Camera camera;
	Image image;
};

