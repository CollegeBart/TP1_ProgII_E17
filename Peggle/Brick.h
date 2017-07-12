#pragma once
class Brick
{
public:
	Brick();
	~Brick();

	bool CollidesWith(const Brick* bricks) const;
	void Draw(ID3DXSprite* spriteBatch);
	void SetPosition(D3DXVECTOR3 pos);
	
	float GetX() const { return m_topleft.x; }
	float GetY() const { return m_topleft.y; }
	float GetWidth() const { return m_size.x; }
	float GetHeight() const { return m_size.y; }
private:
	// Sprite
	IDirect3DTexture9* texture;
	D3DXIMAGE_INFO info;
	D3DXVECTOR3 position;
	D3DXVECTOR3 position1;
	D3DXVECTOR3 position2;
	D3DXVECTOR3 position3;
	D3DXVECTOR3 position4;
	D3DXVECTOR3 center;


	D3DXVECTOR2 m_topleft, m_size;

};

