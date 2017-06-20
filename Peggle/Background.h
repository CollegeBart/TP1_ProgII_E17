#pragma once
class Background
{
public:
	Background();
	~Background();

	void Draw(ID3DXSprite* spriteBatch);
	void Update();

private:
	//Sprite
	IDirect3DTexture9* texture;
	D3DXIMAGE_INFO info;
	D3DXVECTOR3 position;
	D3DXVECTOR3 center;
	
};

