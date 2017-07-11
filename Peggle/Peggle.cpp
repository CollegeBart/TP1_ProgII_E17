#include "stdafx.h"
#include "Peggle.h"

Peggle::Peggle()
{
}

Peggle::Peggle(HINSTANCE hInstance, int nCmdShow)
	: D3DApp(hInstance, nCmdShow)
	, eyePos(.0f, .0f, -10.f)
	, target(0.f, 0.f, 0.f)
	, up(0.f, -1.0f, 0.f)
	, offset(50)
	, startPos(-460, -100)
{
	HR(D3DXCreateSprite(gD3DDevice, &spriteBatch));

	D3DXMatrixLookAtRH(&view, &eyePos, &target, &up);
	D3DXMatrixOrthoRH(&ortho, 
		d3dPP.BackBufferWidth, d3dPP.BackBufferHeight, 0.01f, 1000.0f);

	// Fixed pipeline
	HR(gD3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE));
	HR(gD3DDevice->SetRenderState(D3DRS_LIGHTING, false));

	HR(gD3DDevice->SetTransform(D3DTS_VIEW, &view));
	HR(gD3DDevice->SetTransform(D3DTS_PROJECTION, &ortho));


	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			brk[i*5+j].SetPosition(D3DXVECTOR3(startPos.x + i * offset, startPos.y + j * offset, 0));
		}
	}

	
}

Peggle::~Peggle()
{
	ReleaseCOM(spriteBatch);
}

void Peggle::Update()
{
	if (gD3DApp->GetInput()->KeyPressed(DIK_SPACE))
	{
		//instanciate the ball
		balle.SetVisible(true);
		balle.SetPosition(canon.GetPos());
		balle.SetDir(&canon.GetDir());
	}

	if (balle.GetPos().x > bask.GetPos().x || balle.GetPos().x < bask.GetPos().x + bask.GetCenter().x * 2)
	{

	}

	balle.Update();
	bask.Update();
	canon.Update();
}

void Peggle::Draw()
{
	HR(gD3DDevice->Clear(0, 0, 
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 
		D3DCOLOR_XRGB(128, 128, 128), 1.0, 0));

	HR(gD3DDevice->BeginScene());
	HR(spriteBatch->Begin(	D3DXSPRITE_ALPHABLEND | 
		D3DXSPRITE_OBJECTSPACE | D3DXSPRITE_DONOTMODIFY_RENDERSTATE));

	bg.Draw(spriteBatch);
	balle.Draw(spriteBatch);
	for (int i = 0; i < 100; i++)
	{
		brk[i].Draw(spriteBatch);
	}
	bask.Draw(spriteBatch);
	canon.Draw(spriteBatch);

	HR(spriteBatch->End());
	HR(gD3DDevice->EndScene());

	HR(gD3DDevice->Present(0, 0, 0, 0));
}

