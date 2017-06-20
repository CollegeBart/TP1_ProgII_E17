#pragma once
class Basket
{
public:
	Basket();
	~Basket();

	void Update();
	void Draw(ID3DXSprite* spriteBatch);

private:
	// Sprite
	IDirect3DTexture9* texture;
	D3DXIMAGE_INFO info;
	D3DXVECTOR3 position;
	D3DXVECTOR3 center;
	D3DXVECTOR3 maxPosition;

};
