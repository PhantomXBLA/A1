#include "SceneNode.h"
#include "Game.h"
#include <algorithm>
#include <cassert>


SceneNode::SceneNode() : mChildren(), mParent(nullptr)
{

}

void SceneNode::attachChild(Ptr child)
{
	child->mParent = this;
	mChildren.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::detachChild(const SceneNode& node)
{
	auto found = std::find_if(mChildren.begin(), mChildren.end(), [&](Ptr& p) { return p.get() == &node; });
	assert(found != mChildren.end());

	Ptr result = std::move(*found);
	result->mParent = nullptr;
	mChildren.erase(found);
	return result;
}

void SceneNode::update(GameTimer gt)
{
	updateCurrent(gt);
	updateChildren(gt);
}

void SceneNode::updateCurrent(GameTimer& gt)
{

}

void SceneNode::draw(Game* gameRef)
{


	// Draw node and children with changed transform
	drawCurrent(gameRef);
	drawChildren(gameRef);
}

void SceneNode::drawCurrent(Game* gameRef) 
{

}

void SceneNode::drawChildren(Game* gameRef)
{
	for (const Ptr& child : mChildren)
		child->draw(gameRef);
}

void SceneNode::updateChildren(GameTimer& gt)
{
	for (Ptr& child : mChildren) 
	{
		child->update(gt);
	}
		
}



