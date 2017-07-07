#include "stdafx.h"
#include "Basket.h"
#include "D3DApp.h"


Basket::Basket()
	: center(.0f, .0f, .0f)
	, position(250.0f, 335.0f, .0f)
	, leftPosition(-250.0f, 335.0f, .0f)
	, rightPosition(250.0f, 335.0f, .0f)
	, speed(100.0f, 0.f, 0.f)
{
	HR(D3DXCreateTextureFromFileEx(gD3DDevice, L"basket.png", 0, 0, 1, 0,
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
	if (position.x < leftPosition.x || position.x > rightPosition.x )
	{
		speed.x *= -1;
	}
	position.x -= speed.x * gD3DApp->GetTimer()->GetDeltaTime();
}

void Basket::Draw(ID3DXSprite * spriteBatch)
{
	HR(spriteBatch->Draw(texture, 0, &center, &position, D3DCOLOR_XRGB(255, 255, 255)));
	HR(spriteBatch->Flush());
}
