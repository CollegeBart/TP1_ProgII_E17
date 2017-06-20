#include "stdafx.h"
#include "Balle.h"

#include "D3DApp.h"

Balle::Balle()
	: center(.0f, .0f, .0f)
	, position(.0f, .0f, .0f)
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
	position += D3DXVECTOR3(.0f, 100.f, 0.f) * gD3DApp->GetTimer()->GetDeltaTime();
}

void Balle::Draw(ID3DXSprite* spriteBatch)
{
	HR(spriteBatch->Draw(texture, 0, &center, &position, D3DCOLOR_XRGB(255, 255, 255)));
	HR(spriteBatch->Flush());
}