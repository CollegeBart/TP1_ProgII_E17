#include "stdafx.h"
#include "Basket.h"
#include "D3DApp.h"


Basket::Basket()
	: center(.0f, .0f, .0f)
	, position(250.0f, 335.0f, .0f)
	, maxPosition(-250.0f, 335.0f, .0f)
{
	HR(D3DXCreateTextureFromFileEx(gD3DDevice, L"baskleft.png", 0, 0, 1, 0,
		D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_FILTER_NONE, D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 255, 255), &info, NULL, &texture));

	HR(D3DXCreateTextureFromFileEx(gD3DDevice, L"baskright.png", 0, 0, 1, 0,
		D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_FILTER_NONE, D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 255, 255), &info, NULL, &texture));

	center = D3DXVECTOR3(info.Width / 2, info.Height / 2, 0.f);
}


Basket::~Basket()
{
	ReleaseCOM(texture);
}

void Basket::Update()
{
	position -= D3DXVECTOR3(100, 0, 0) * gD3DApp->GetTimer()->GetDeltaTime();

	if (position.x <= maxPosition.x)
	{
		std::cout << position << std::endl;
		position += D3DXVECTOR3(100, 0, 0) * gD3DApp->GetTimer()->GetDeltaTime();
	}
}

void Basket::Draw(ID3DXSprite * spriteBatch)
{
	HR(spriteBatch->Draw(texture, 0, &center, &position, D3DCOLOR_XRGB(255, 255, 255)));
	HR(spriteBatch->Flush());
}
