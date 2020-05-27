#pragma once

#include "SDL.h"

#include "Collider.h"

class Collider;

class Collision
{
public:
	static bool AABB(const SDL_Rect& RectA, const SDL_Rect& RectB);
	static bool AABB(const Collider& colA, const Collider& colB);
};