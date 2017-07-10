#pragma once
class Balle
{
public:
	Balle();
	~Balle();

	void Update();
	void Draw(ID3DXSprite* spriteBatch);

private:
	// Sprite
	IDirect3DTexture9* texture;
	D3DXIMAGE_INFO info;
	D3DXVECTOR3 position;
	D3DXVECTOR3 topPos;
	D3DXVECTOR3 botPos;
	D3DXVECTOR3 leftPos;
	D3DXVECTOR3 rightPos;
	D3DXVECTOR3 gravity;
	D3DXVECTOR3 prevPos;
	D3DXVECTOR3 center;
	int dirX, dirY;
	float velocity, acceleration;

};

