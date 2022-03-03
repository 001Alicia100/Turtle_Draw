#pragma once
#include<iostream>
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include"Tortle.h"
#include<iostream>
#include<vector>
#include <algorithm>

using namespace sf;
using namespace std;

class Instruction
{
private:
	vector<Text> texts;
public:
	Instruction(vector<Text> t, RenderWindow w) { texts = t; }
	Instruction() {}
	void setText(vector<Text> t) { texts = t; }
	string checkError(void);
	vector<int> translate(void);
};

