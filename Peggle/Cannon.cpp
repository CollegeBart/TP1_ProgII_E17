#include "stdafx.h"
#include "Cannon.h"

Cannon::Cannon()
	: center(.0f, .0f, .0f)
	, position(.0f, -330.0f, 0.f)
	, rotEuler(.0f, .0f, D3DX_PI/2)
{
	HR(D3DXCreateTextureFromFileEx(gD3DDevice, L"shooter.png", 0, 0, 1, 0,
		D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_FILTER_NONE, D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 255, 255), &info, NULL, &texture));

	//HR(D3DXCreateTextureFromFileEx(gD3DDevice, L"ball.png", 0,0,1,0,
	//	D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_FILTER_NONE, D3DX_DEFAULT,
	//	D3DCOLOR_XRGB(255, 255, 255), &ballinf, NULL, &texture));

	center = D3DXVECTOR3(info.Width/2, 0.f, 0.f);
}


Cannon::~Cannon()
{
	ReleaseCOM(texture);
}

void Cannon::Update()
{
	if (gD3DApp->GetInput()->KeyDown(DIK_LEFT))
	{
		if (rot <= .8)
		{
			rot += 1 * gD3DApp->GetTimer()->GetDeltaTime();
		}
	}

	if (gD3DApp->GetInput()->KeyDown(DIK_RIGHT))
	{
		if (rot >= -.8)
		{
			rot -= 1 * gD3DApp->GetTimer()->GetDeltaTime();
		}
	}
		
	D3DXMatrixRotationZ(&rotMatrix, rot);
}

void Cannon::Draw(ID3DXSprite * spriteBatch)
{
	D3DXMatrixTranslation(&trans, position.x, position.y, position.z);

	HR(spriteBatch->SetTransform(&(rotMatrix*trans)));

	HR(spriteBatch->Draw(texture, 0, &center, 0, D3DCOLOR_XRGB(255, 255, 255)));
	
	D3DXMATRIX ident;
	D3DXMatrixIdentity(&ident);
	HR(spriteBatch->SetTransform(&ident));
	
	HR(spriteBatch->Flush());
}

D3DXVECTOR2 Cannon::GetDir()
{
	D3DXVECTOR2 v;
	v.x = cosf(rot + D3DX_PI/2 );
	v.y = sinf(rot + D3DX_PI / 2);
	return v;
}
