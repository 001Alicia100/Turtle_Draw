#pragma once
#include<iostream>
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace sf;
using namespace std;

class Historique
{
private:
	string name;
public:
	Historique() {};
	void Sauver(vector<Text>);
	vector<Text> Ouvrir();
};
