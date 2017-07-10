#include "stdafx.h"
#include "Balle.h"

#include "D3DApp.h"

Balle::Balle()
	: center(.0f, .0f, .0f)
	, position(.0f, -325.f, .0f)
	, topPos(.0f, -340.f, .0f)
	, botPos(.0f, 330.f, .0f)
	, leftPos(-610.f, 0.f, 0.f)
	, rightPos(610.f, 0.f, 0.f)
	, gravity(0.f, 9.8f, 0.0f)
	, dirX(1), dirY(1)
	, velocity(0.f)
	, acceleration(9.8f)
	, speed(200)
	, isVisible(false)
	
{
	HR(D3DXCreateTextureFromFileEx(gD3DDevice, L"ball.png", 0, 0, 1, 0,
		D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_FILTER_NONE, D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 255, 255), &info, NULL, &texture));

	//center = D3DXVECTOR3(info.Width / 2, info.Height / 2, 0.f);
}

Balle::~Balle()
{
	ReleaseCOM(texture);
}

void Balle::Update()
{
	//velocity += acceleration * gD3DApp->GetTimer()->GetDeltaTime();
	if (isVisible == true)
	{
		if (position.y <= topPos.y || position.y >= botPos.y)
		{
			dirY *= -1;
			//velocity *= -0.5f;
		}
		if (position.x <= leftPos.x || position.x >= rightPos.x)
		{
			dirX *= -1;
		}
	}

	prevPos = position;

	position += D3DXVECTOR3(dirX, dirY, 0) *  speed * gD3DApp->GetTimer()->GetDeltaTime();

	//position.y += velocity * gD3DApp->GetTimer()->GetDeltaTime();
}

void Balle::Draw(ID3DXSprite* spriteBatch)
{
	if (isVisible == true)
	{
		HR(spriteBatch->Draw(texture, 0, &center, &position, D3DCOLOR_XRGB(255, 255, 255)));
		HR(spriteBatch->Flush());
	}
}
