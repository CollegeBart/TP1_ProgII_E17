#include "stdafx.h"
#include "Background.h"
#include "D3DApp.h"

Background::Background()
	: center(.0f, .0f, .0f)
	, position(0.0f, 0.0f, .0f)
{
	HR(D3DXCreateTextureFromFileEx(gD3DDevice, L"bg3.png", 0, 0, 1, 0,
		D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_FILTER_NONE, D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 255, 255), &info, NULL, &texture));

	center = D3DXVECTOR3(info.Width / 2, info.Height / 2, 0.f);

}


Background::~Background()
{
	ReleaseCOM(texture);
}

void Background::Draw(ID3DXSprite * spriteBatch)
{
	HR(spriteBatch->Draw(texture, 0, &center, &position, D3DCOLOR_XRGB(255, 255, 255)));
	HR(spriteBatch->Flush());
}

void Background::Update()
{
	gD3DApp->SetSize(1280, 780);
}
