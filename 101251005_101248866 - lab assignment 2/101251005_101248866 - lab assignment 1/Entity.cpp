#include "Entity.h"


void Entity::setVelocity(DirectX::XMFLOAT2 velocity)
{
	mVelocity = velocity;
}

void Entity::setVelocity(float vx, float vy)
{
	mVelocity.x = vx;
	mVelocity.y = vy;
}

DirectX::XMFLOAT2 Entity::getVelocity() const
{
	return mVelocity;
}

void Entity::updateCurrent(GameTimer gt)
{
	std::move(mVelocity.x * gt.DeltaTime());
	std::move(mVelocity.y * gt.DeltaTime());


	
}

void Entity::accelerate(DirectX::XMFLOAT2 velocity)
{
	mVelocity.x += velocity.x;
	mVelocity.y += velocity.y;
}

void Entity::accelerate(float vx, float vy)
{
	mVelocity.x += vx;
	mVelocity.y += vy;
}
