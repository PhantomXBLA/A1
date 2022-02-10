#pragma once

#include "SceneNode.h"

class Entity : public SceneNode
{
public:
	void setVelocity(DirectX::XMFLOAT2 velocity);
	void setVelocity(float vx, float vy);

	DirectX::XMFLOAT2 getVelocity() const;

	void accelerate(DirectX::XMFLOAT2 velocity);
	void accelerate(float vx, float vy);
	


	DirectX::XMFLOAT2 mVelocity;
	DirectX::XMVECTOR spawnPos = {5,0,0,0};

	float spawnX, spawnY;
	UINT objCBIndex;



private:
	virtual void updateCurrent(GameTimer gt);

private:



};

