#pragma once
class Brick
{
public:
	Brick();
	~Brick();

	void Draw(ID3DXSprite* spriteBatch);
	void SetPosition(D3DXVECTOR3 pos);
private:
	// Sprite
	IDirect3DTexture9* texture;
	D3DXIMAGE_INFO info;
	D3DXVECTOR3 position;
	D3DXVECTOR3 center;
};

