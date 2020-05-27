#include "Entity.h"

Help_Component Component::components = Help_Component{};

Entity::Entity(const char* path) 
{
	evolution = new Evolution(2); //create by scale
	components.structComponents[0] = evolution;
	
	appearance = new Appearance(path, true);
	components.structComponents[1] = appearance;

	keybourd = new Keyboard;
	components.structComponents[2] = keybourd;

	collider = new Collider(path);
	components.structComponents[3] = collider;
}

pair<int, int > Entity::getPositionEvolution()
{
	pair<int, int > pos = evolution->getPosition();
	return pos;
}

void Entity::setPositionEvolution(pair<int, int> pos)
{
	evolution->setPosition(pos);
}

SDL_Rect Entity::getCollider()
{
	return collider->getCollider();
}

void Entity::init()
{
	for (int i = 0; i < numberOFComponents; i++)
	{
		components.structComponents[i]->init();
	}
	
}

void Entity::update()
{
	for (int i = 0; i < numberOFComponents ; i++)
	{
		components.structComponents[i]->update();
	}
}

void Entity::draw()
{
	for (int i = 0; i < numberOFComponents; i++)
	{
		components.structComponents[i]->draw();
	}
}
