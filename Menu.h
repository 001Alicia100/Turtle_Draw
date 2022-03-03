#pragma once
#include<iostream>
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include "Instruction.h"
#include "Tortle.h"
#include"Historique.h"
#include<iostream>
#include<vector>
#include<algorithm>

using namespace sf;
using namespace std;

class Menu
{
private:
	Historique histo;
	Tortle tortue;
	Font font;
	RenderWindow window;
	Instruction instru;
	vector<Text> texts;
	vector<RectangleShape> lines, temp_lines;
	vector<int> commands, repeat;
	int mode = 1, textKey = 1;
	RectangleShape drawBox, writeBox, playBox, exampleBox;
	Sprite play, ex, verif, save, back;
	Texture verifbutton, exbutton, savebutton, backbutton, playbutton;
	bool etatCrayon = true;

public:
	Menu();

	bool Update();
	void Clear();
};

