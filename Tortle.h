#pragma once
#include<iostream>
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include<iostream>
#include<vector>
#include<algorithm>

using namespace sf;
using namespace std;

class Tortle
{
private:
	Sprite sprite;
	Texture texture;
	int speed=3;
	float angle;
public:
	Tortle();
	Sprite getSprite() { return sprite; }
	Vector2f getPosition() { return sprite.getPosition(); }
	float getSpeed() { return speed; }
	float getAngle() { return angle; }
	void wait();
	void setPosition(float x, float y) { sprite.setPosition(x, y); }
	void setSpeed(int s) { speed = s; }
	void Avancer(int);
	void Reculer(int);
	void Gauche(int x) { sprite.rotate((-x)); angle += 1; }
	void Droite(int x) { sprite.rotate(x); angle -= 1; }

};

#pragma once
