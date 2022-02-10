#pragma once
#include "Game.h"
#include "Aircraft.h"
#include "FrameResource.h"

class World
{
public:
	void								update(GameTimer gt);
	void								drawOcean(Game* gameRef);
	void								buildScene(Game* gameRef);


private:
	void								loadTextures();


#pragma region step 3
	void								adaptPlayerPosition();
	void								adaptPlayerVelocity();
#pragma endregion


private:
	enum Layer
	{
		Background,
		Air,
		LayerCount
	};


private:

	SceneNode							mSceneGraph;
	std::array<SceneNode*, LayerCount>	mSceneLayers;

	//sf::FloatRect						mWorldBounds;
	Aircraft* mPlayerAircraft;
};
