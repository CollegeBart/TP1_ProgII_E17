#pragma once
class Basket
{
public:
	Basket();
	~Basket();

	void Update();
	void Draw(ID3DXSprite* spriteBatch);
	D3DXVECTOR3 GetPos()
	{
		return position;
	}
	D3DXVECTOR3 GetCenter()
	{
		return center;
	}
private:
	// Sprite
	D3DXVECTOR3 position;
	D3DXVECTOR3 center;
	IDirect3DTexture9* texture;
	D3DXIMAGE_INFO info;
	D3DXVECTOR3 leftPosition;
	D3DXVECTOR3 rightPosition;
	D3DXVECTOR3 speed;
	D3DXVECTOR3 tempPos;
};

