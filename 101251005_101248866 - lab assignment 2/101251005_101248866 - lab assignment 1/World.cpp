#include "World.h"
#include "Aircraft.h"

//loadTextures();

void World::update(GameTimer gt)
{

#pragma region step 5

	adaptPlayerVelocity();

	// Regular update step, adapt position (correct if outside view)
	mSceneGraph.update(gt);
	adaptPlayerPosition();

#pragma endregion
}

void World::drawOcean(Game* gameRef)
{
	UINT objCBIndex = 0;


	auto wavesRitem = std::make_unique<RenderItem>();
	wavesRitem->World = MathHelper::Identity4x4();
	XMStoreFloat4x4(&wavesRitem->World, XMMatrixScaling(10.0f, 10.0f, 10.0f) * XMMatrixRotationX(XM_PI * -0.5f) * XMMatrixTranslation(0.0f, 0.0f, 800.0f));
	wavesRitem->ObjCBIndex = objCBIndex++;
	wavesRitem->Mat = gameRef->mMaterials["water"].get();
	wavesRitem->Geo = gameRef->mGeometries["waterGeo"].get();
	wavesRitem->PrimitiveType = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	wavesRitem->IndexCount = wavesRitem->Geo->DrawArgs["grid"].IndexCount;
	wavesRitem->StartIndexLocation = wavesRitem->Geo->DrawArgs["grid"].StartIndexLocation;
	wavesRitem->BaseVertexLocation = wavesRitem->Geo->DrawArgs["grid"].BaseVertexLocation;
	gameRef->mWavesRitem = wavesRitem.get(); //The randomness of waves/ this has been set to be almost non existent
	gameRef->mRitemLayer[(int)RenderLayer::Opaque].push_back(wavesRitem.get());

	gameRef->mAllRitems.push_back(std::move(wavesRitem));
}

void World::loadTextures()
{

}

void World::buildScene(Game* gameRef)
{
	// Initialize the different layers
	for (std::size_t i = 0; i < LayerCount; ++i)
	{
		SceneNode::Ptr layer(new SceneNode());
		mSceneLayers[i] = layer.get();

		mSceneGraph.attachChild(std::move(layer));
	}

	
	drawOcean(gameRef);

	std::unique_ptr<Aircraft> playerAircraft(new Aircraft(Aircraft::Eagle));
	mPlayerAircraft = playerAircraft.get();
	mPlayerAircraft->spawnX = 0;
	mPlayerAircraft->spawnY = -13;
	mPlayerAircraft->objCBIndex = 1;
	

	std::unique_ptr<Aircraft> raptorOne(new Aircraft(Aircraft::Raptor));
	raptorOne->spawnX = 6;
	raptorOne->spawnY = -15;
	raptorOne->objCBIndex = 2;


	std::unique_ptr<Aircraft> raptorTwo(new Aircraft(Aircraft::Raptor));
	raptorTwo->spawnX = -6;
	raptorTwo->spawnY = -15;
	raptorTwo->objCBIndex = 3;

	playerAircraft->drawCurrent(gameRef);
	raptorOne->drawCurrent(gameRef);
	raptorTwo->drawCurrent(gameRef);

	mSceneLayers[Air]->attachChild(std::move(playerAircraft));
	mPlayerAircraft->attachChild(std::move(raptorOne));
	mPlayerAircraft->attachChild(std::move(raptorTwo));
}

#pragma region step 4

void World::adaptPlayerPosition()
{

}

void World::adaptPlayerVelocity()
{

}

#pragma endregion