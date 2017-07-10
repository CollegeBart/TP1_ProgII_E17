#pragma once
class Balle
{
public:
	Balle();
	~Balle();

	void Update();
	void Draw(ID3DXSprite* spriteBatch);

	bool GetVisible() {
		return isVisible;
	}

	void SetVisible(bool isVisible) { this->isVisible = isVisible; }

	D3DXIMAGE_INFO info;
	D3DXVECTOR3 position;
private:
	// Sprite
	bool isVisible;
	IDirect3DTexture9* texture;
	D3DXVECTOR3 topPos;
	D3DXVECTOR3 botPos;
	D3DXVECTOR3 leftPos;
	D3DXVECTOR3 rightPos;
	D3DXVECTOR3 gravity;
	D3DXVECTOR3 prevPos;
	D3DXVECTOR3 center;
	int dirX, dirY, speed;
	float velocity, acceleration;

};

