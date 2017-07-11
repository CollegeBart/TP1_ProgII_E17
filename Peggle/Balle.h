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
	void SetDir(D3DXVECTOR2* dir) 
	{ 
		dirX = dir->x; 
		dirY = dir->y; 
	}
	void SetPosition(D3DXVECTOR3 pos);
	D3DXVECTOR3 GetPos() 
	{ 
		return position;
	}

private:
	// Sprite
	D3DXVECTOR3 position;
	D3DXIMAGE_INFO info;
	bool isVisible;
	D3DXMATRIX rotball;
	IDirect3DTexture9* texture;
	D3DXVECTOR3 leftPos;
	D3DXVECTOR3 rightPos;
	D3DXVECTOR3 topPos;
	D3DXVECTOR3 botPos;
	D3DXVECTOR3 gravity;
	D3DXVECTOR3 prevPos;
	D3DXVECTOR3 center;
	float dirX, dirY, speed;
	float velocity, acceleration;

};

