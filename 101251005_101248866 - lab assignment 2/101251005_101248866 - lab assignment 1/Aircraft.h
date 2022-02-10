#pragma once
#include "Entity.h"


class Aircraft : public Entity
{
public:
	enum Type
	{
		Eagle,
		Raptor,
	};

public:

	Aircraft(Type type);
	RenderItem* AircraftRI = nullptr;
	virtual void drawCurrent(Game* gameRef);
	

private:
	





private:
	Type				mType;
	std::string			materialName;
};

