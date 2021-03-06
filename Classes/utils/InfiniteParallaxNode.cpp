#include "InfiniteParallaxNode.h"

class PointObject : public Ref
{
public:
	inline void setRation(Point ratio) { _ratio = ratio; }
	inline void setOffset(Point offset) { _offset = offset; }
	inline void setChild(Node *var) { _child = var; }
	inline Point getOffset() const { return _offset; }
	inline Node* getChild() const { return _child; }
private:
	Point _ratio;
	Point _offset;
	Node* _child;
};

InfiniteParallaxNode* InfiniteParallaxNode::create()
{
	// Create an instance of InfiniteParallaxNode
	InfiniteParallaxNode* node = new InfiniteParallaxNode();
	if (node) {
		// Add it to autorelease pool
		node->autorelease();
		node->free();
	}
	else {
		// Otherwise delete
		delete node;
		node = 0;
	}
	return node;
}

void InfiniteParallaxNode::updatePosition()
{
	// Get visible size
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//auto origin = Director::getInstance()->getVisibleOrigin();
	int safeOffset = 0;
	// 1. For each child of an parallax node
	for (int i = 0; i < _children.size(); i++)
	{
		auto node = _children.at(i);
		// 2. We check whether it is out of the left side of the visible area
		if (convertToWorldSpace(node->getPosition()).x + node->getBoundingBox().size.width < safeOffset)
		//if (convertToWorldSpace(node->getPosition()).x < safeOffset)
		//	log("Width: %f", node->getBoundingBox().size.width);
			// 3. Find PointObject that corresponds to current node
			for (int i = 0; i < _parallaxArray->num; i++)
			{
				auto po = (PointObject*)_parallaxArray->arr[i];
				// If yes increase its current offset on the value of visible width
				if (po->getChild() == node)
					po->setOffset(po->getOffset() + Point(visibleSize.width+node->getBoundingBox().size.width, 0));

			}
	}
}

void InfiniteParallaxNode::up(Vec2 posHero)
{
	//if (state == FREE || state == DOWN) {
	//	if (vecy > 0) {
			auto SCREEN_SIZE = Director::getInstance()->getVisibleSize();
			//this->state = UP;
			/*auto call = CallFunc::create([&]() {
				this->free();
			});*/
			//auto target = Vec2(this->getPositionX(), this->getPositionY() + SCREEN_SIZE.height / 6);
			//this->runAction(Sequence::createWithTwoActions(EaseIn::create(MoveTo::create(0.2f, target), 2), call));
			//this->runAction(Sequence::createWithTwoActions(MoveTo::create(0.2f, target), call));
			this->setPositionY(posHero.y - SCREEN_SIZE.height / 6);
		//}
//	}
}

void InfiniteParallaxNode::down(Vec2 posHero)
{
//	if (state == FREE || state == DOWN) {
	//	if (vecy < 0) {
			auto SCREEN_SIZE = Director::getInstance()->getVisibleSize();
			//this->state = DOWN;
			/*auto call = CallFunc::create([&]() {
				this->free();
			});*/

			/*auto target = Vec2(this->getPositionX(),
				(this->getPositionY() - SCREEN_SIZE.height / 8) <= SCREEN_SIZE.height / 2 ? SCREEN_SIZE.height / 2 :
				(this->getPositionY() - SCREEN_SIZE.height / 8));*/
			//this->runAction(Sequence::createWithTwoActions(EaseOut::create(MoveTo::create(0.5f, target), 2), call));
			//this->runAction(Sequence::createWithTwoActions(MoveTo::create(0.2f, target), call));
			if(posHero.y + SCREEN_SIZE.height / 6 > SCREEN_SIZE.height/2)
			this->setPositionY(posHero.y+SCREEN_SIZE.height/6);
		//}
	//}
}

void InfiniteParallaxNode::free()
{
	this->state = FREE;
}
