#include "Historique.h"
#include <filesystem>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void Historique::Sauver(vector<Text> texts)
{
	cout << "Enregistrer sous quel nom ? ";
	string name;
	cin >> name;
	name += ".txt";
	ofstream file;
	file.open(name.c_str());
	for (unsigned int i = 0; i < texts.size(); i++)
	{
		file << (string)texts[i].getString() << endl;
	}
}

vector<Text> Historique::Ouvrir()
{
	vector<Text> texts;
	Text text;
	text.setPosition(683, 115);
	text.setFillColor(Color::Black);
	text.setCharacterSize(20);

	string name;

	cout << "Creer un nouveau programme ou ouvrir un deja existant ?\n";
	cout << "	1. Creer un nouveau.\n	2. Ouvrir un existant.\n";
	int i=0;
	while (i != 1 and i != 2)
	{
		cin >> i;
	}
	if (i == 2)
	{
		i = 1;
		std::string path("./");
		std::string ext(".txt");
		for (auto &p : experimental::filesystem::directory_iterator(path))
		{
			if (p.path().extension() == ext)
				std::cout << i++ << ". "<< p.path().stem().string() << '\n';
		}
		cout << "Lequel ouvrir ? ";
		cin >> i; int j = 1;
		for (auto &p : experimental::filesystem::directory_iterator(path))
		{
			if ((p.path().extension() == ext))
			{
				if (i == j)
				{
					name = p.path().stem().string();
					name += ".txt";
				}
				j++;
			}
		}
		ifstream file(name.c_str());
		string line;
		while (getline(file, line))
		{
			cout << line << endl;
			text.setString(line);
			text.move(0, 20);
			texts.push_back(text);
		}
	}
	return texts;
}
