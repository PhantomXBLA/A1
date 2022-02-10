#include "Aircraft.h"
#include "Game.h"





Aircraft::Aircraft(Type type)
{
	switch (type)
	{
	case (Eagle):
		materialName = "eagle";
		break;
	case (Raptor):
		materialName = "raptor";
		break;
	}
}


void Aircraft::drawCurrent(Game* gameRef)
{


	auto planeRenderItem = std::make_unique<RenderItem>();
	
	planeRenderItem->World = MathHelper::Identity4x4();
	XMStoreFloat4x4(&planeRenderItem->World, XMMatrixScaling(3.0f, 0.000000001f, 3.0f) * XMMatrixRotationX(XM_PI * -0.5f) * XMMatrixTranslation(spawnX, spawnY, 0.0f)); //change size of object - change position of object
	planeRenderItem->ObjCBIndex = objCBIndex++;
	

	//Materials go here
	planeRenderItem->Mat = gameRef->mMaterials[materialName].get();
	planeRenderItem->Geo = gameRef->mGeometries["boxGeo"].get();
	planeRenderItem->PrimitiveType = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	planeRenderItem->IndexCount = planeRenderItem->Geo->DrawArgs["box"].IndexCount;
	planeRenderItem->StartIndexLocation = planeRenderItem->Geo->DrawArgs["box"].StartIndexLocation;
	planeRenderItem->BaseVertexLocation = planeRenderItem->Geo->DrawArgs["box"].BaseVertexLocation;

	AircraftRI = planeRenderItem.get();
	

	gameRef->mRitemLayer[(int)RenderLayer::Transparent].push_back(planeRenderItem.get());
	
	gameRef->mAllRitems.push_back(std::move(planeRenderItem));
	
}
