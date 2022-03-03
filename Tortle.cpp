#include "Tortle.h"
#pragma once

Tortle::Tortle()
{
	texture.loadFromFile("arrow.png");

	sprite.setTexture(texture);
	sprite.setPosition(355, 340);
	sprite.setOrigin(texture.getSize().x/1.5, texture.getSize().y/2);
	sprite.rotate(0);
	sprite.scale(0.3, 0.3);
}

void Tortle::wait()
{
	switch(speed)
	{
	case 1:
		sleep(milliseconds(10));
		break;
	case 2:
		sleep(milliseconds(5));
		break;
	default:
		break;
	}
}

void Tortle::Avancer(int f)
{
	float x = sprite.getPosition().x;
	float y = sprite.getPosition().y;

	x = f * cos(angle * 0.01745329251);
	y = -f * sin(angle * 0.01745329251);
	sprite.move(Vector2f(x, y));
}

void Tortle::Reculer(int f)
{
	Avancer(-f);
	
}
