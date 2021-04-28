#pragma once

#include<string>
#include<wrl.h>
#include<d3d11.h>


class Image
{
public:
	void load(std::string filePath, ID3D11Device* device);
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> pTextureView;

	Microsoft::WRL::ComPtr<ID3D11SamplerState> pSampler;
};

