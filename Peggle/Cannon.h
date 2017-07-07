#pragma once
#include "Balle.h"
class Cannon
	: public Balle
{
public:
	Cannon();
	~Cannon();

	void Update();
	void Draw(ID3DXSprite* spriteBatch);

private:
	IDirect3DTexture9* texture;
	D3DXIMAGE_INFO info;
	D3DXVECTOR3 center;
	D3DXVECTOR3 position;
	D3DXVECTOR3 rotEuler;
	D3DXVECTOR3 rotMaxLeft;
	D3DXVECTOR3 rotMaxRight;
	D3DXMATRIX rotMatrix;
	D3DXMATRIX trans;

	float rot = .245f;

	Balle ball;
	D3DXIMAGE_INFO ballinf;
};

