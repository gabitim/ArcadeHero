#pragma once

#include <iostream>


#include "Component.h"

using namespace std;


class Evolution : public Component
{
public:
	pair <int, int> position;
	pair <int, int> velocity;

	int height = 32;
	int width = 32;
	int scale = 2;

	float speed = 3; //multiplied with velocity

	Evolution()
	{
		position.first = 0;
		position.second = 0;
	}

	Evolution(float x, float y)
	{
		position.first = x;
		position.second = y;
	}

	Evolution(int scale)
	{
		position.first = 800;
		position.second = 700;
		this->scale = scale;
	}

	Evolution(float x, float y, int h, int w, int scale)
	{
		position.first = x;
		position.second = y;
		height = h;
		width = w;
		this->scale = scale;
	}

	void init() override
	{
		velocity.first = 0;
		velocity.second = 0;
	}

	void update() override
	{
		position.first += velocity.first * speed;
		position.second += velocity.second * speed;
		cout << position.first << " " << position.second << endl; // printing the Y, X position

	}

	pair<int, int > getPosition()
	{
		return position;
	}

	void setPosition(pair<int, int> pos)
	{
		position = pos;
	}
};