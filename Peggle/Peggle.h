#include "stdafx.h"
#include "D3DApp.h"

#include "Patrick.h"
#include "Balle.h"
#include "Background.h"
#include "Brick.h"
#include "Basket.h"
#include "Cannon.h"

class Peggle 
	: public D3DApp
{
public:
	Peggle();
	Peggle(HINSTANCE hInstance, int nCmdShow);
	~Peggle();

	void Update();
	void Draw();

private:
	ID3DXSprite* spriteBatch;

	// Objets
	Cannon canon;
	Patrick patrick;
	Balle balle;
	Background bg;
	Brick brk;
	Basket bask;

	// Camera
	D3DXMATRIX view;
	D3DXMATRIX ortho;
	D3DXVECTOR3 eyePos;
	D3DXVECTOR3 target;
	D3DXVECTOR3 up;
};
