#include "Menu.h"
#pragma once

#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include"Historique.h"
#include"Instruction.h"
#include"Tortle.h"

#include<fstream>
#include<iostream>
#include<vector>
using namespace sf;
using namespace std;

Menu::Menu() {
	texts = histo.Ouvrir();
	window.create(VideoMode(1080, 680), "Turtle", Style::Default);
	
	verifbutton.loadFromFile("verif.png");
	verif.setTexture(verifbutton);
	verif.setPosition(685, 15);
	verif.setScale(0.9, 0.9);

	playbutton.loadFromFile("lancer.png");
	play.setTexture(playbutton);
	play.setPosition(685, 15);
	play.setScale(0.9, 0.9);

	exbutton.loadFromFile("exemple.png");
	ex.setTexture(exbutton);
	ex.setPosition(880, 15);
	ex.setScale(0.9, 0.9);

	savebutton.loadFromFile("save.png");
	save.setTexture(savebutton);
	save.setPosition(880, 15);
	save.setScale(0.6, 0.9);

	backbutton.loadFromFile("retour.png");
	back.setTexture(backbutton);
	back.setPosition(880, 15);
	back.setScale(0.9, 0.9);

	// init rect
	drawBox.setSize(Vector2f(650, 650));
	drawBox.setPosition(15, 15);
	writeBox.setSize(Vector2f(385, 550));
	writeBox.setPosition(680, 115);
}

bool Menu::Update()
{
	bool enCours = false;
	int re, remaining, task, key = 0;
	int mode = 1;
	string input;
	Clock clock;
	string errors;

	// init text
	font.loadFromFile("fonts/Montserrat-Medium.otf");
	Text text("", font);
	text.setFillColor(Color::Black);
	text.setPosition(683, 115);
	text.setCharacterSize(20);

	for (int i = 0; i < texts.size(); i++)
		textKey++ ;
	

	Text errorsText("", font);
	errorsText.setFillColor(Color::Black);
	errorsText.setPosition(683, 115);
	errorsText.setCharacterSize(20);
	// init sprite
	

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;


			case Event::TextEntered:
				if (isprint(event.text.unicode))
				{
					input += event.text.unicode;
					text.setString(input);
				}
				break;
			case Event::KeyPressed:
				if (event.key.code == sf::Keyboard::BackSpace) {
					if (!input.empty())
						input.pop_back();
					else
					{
						if (texts.size())
						{
							

							if (textKey > 25)
							{
								text.move(0, 20);
								for (int i = 0; i < texts.size(); i++)
								{
									texts[i].move(0, 20);
								}
								input = texts[textKey-- -2].getString();
								texts.pop_back();
								text.move(0,-20);
							}
							else
							{
								input = texts[textKey-- -2].getString();
								texts.pop_back();
								text.move(0, -20);
							}
						}
						
					}
				}

				if (event.key.code == sf::Keyboard::Return) {
					
					text.setString(input);
					texts.push_back(text);
					textKey++;
					text.move(0, 20);
					input = "";

					if (textKey >= 26)
					{
						text.move(0, -20);
						for (int i = 0; i < texts.size(); i++)
						{
							texts[i].move(0, -20);
						}
					}
				}
				break;
			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
			FloatRect boundsPlay = play.getGlobalBounds();
			FloatRect boundsEx = ex.getGlobalBounds();
			if (boundsPlay.contains(mouse) and mode == 1)
			{
				if (input != "")
				{
					text.setString(input);
					texts.push_back(text);
					text.setPosition(683, 115 + textKey++ * 20);
				}
				instru.setText(texts);


				errors = instru.checkError();
				errorsText.setString(errors);

				if (errors == "Code OK!\n")
				{
					mode = 2;
				}
				else
				{
					mode = 4;
				}
				sleep(milliseconds(300));
			}
			else if (boundsPlay.contains(mouse) and mode == 2)
			{
				mode = 3;
				commands = instru.translate();
			}
			else if (boundsEx.contains(mouse) and mode == 1)
			{
				text.setString("reculer 20");
				texts.push_back(text);
				text.setPosition(683, 115 + textKey++ * 20);
				text.setString("repete 20");
				texts.push_back(text);
				text.setPosition(683, 115 + textKey++ * 20);
				text.setString("avancer 200");
				texts.push_back(text);
				text.setPosition(683, 115 + textKey++ * 20);
				text.setString("repete 40");
				texts.push_back(text);
				text.setPosition(683, 115 + textKey++ * 20);
				text.setString("droite 10");
				texts.push_back(text);
				text.setPosition(683, 115 + textKey++ * 20);
				text.setString("avancer 4");
				texts.push_back(text);
				text.setPosition(683, 115 + textKey++ * 20);
				text.setString("fin");
				texts.push_back(text);
				text.setPosition(683, 115 + textKey++ * 20);
				text.setString("avancer 200");
				texts.push_back(text);
				text.setPosition(683, 115 + textKey++ * 20);
				text.setString("droite 90");
				texts.push_back(text);
				text.setPosition(683, 115 + textKey++ * 20);
				text.setString("fin");
				texts.push_back(text);
				text.setPosition(683, 115 + textKey++ * 20);
				sleep(milliseconds(500));

			}
			else if (boundsEx.contains(mouse) and mode == 4)
			{
				Clear();
				sleep(milliseconds(300));
				return false;
			}
			else if (boundsEx.contains(mouse) and (mode == 2 || mode == 3))
			{
				histo.Sauver(texts);
				mode = 3;
			}
		}

		static sf::Time text_effect_time;
		static bool show_cursor;

		text_effect_time += clock.restart();

		if (text_effect_time >= sf::seconds(0.5f))
		{

			show_cursor = !show_cursor;
			text_effect_time = sf::Time::Zero;
		}

		text.setString(input + (show_cursor ? '_' : ' '));






		//Draw
		window.clear();

		//Draw everything
		window.draw(drawBox);

		window.draw(writeBox);
		switch (mode)
		{
		case 1:
			for (int i = 0; i < texts.size(); i++)
			{
				window.draw(texts[i]);
			}
			window.draw(text);
			window.draw(verif);
			window.draw(ex);
			break;
		case 2:

			window.draw(play);
			window.draw(save);
			window.draw(errorsText);
			break;
		case 4:
			window.draw(back);
			window.draw(errorsText);

			break;
		case 3:
			window.draw(play);
			window.draw(save);
			window.draw(errorsText);
			if (!enCours and key < commands.size())
			{
				if(commands[key]<5)
				{
					remaining = commands[key + 1];
					re = remaining;
					task = commands[key];
					enCours = true;
					key = key + 2;
				}
				else if (commands[key] == 9)
				{
					repeat.push_back(commands[key + 1]);
					repeat.push_back(key + 2);
					key = key + 2;
				}
				else if (commands[key] == 10)
				{
					if (repeat[repeat.size() - 2] > 0)
					{
						repeat[repeat.size() - 2]--;
						key = repeat[repeat.size() - 1];
					}
					else
					{
						repeat.pop_back();
						repeat.pop_back();
						key++;
					}
				}
				else
				{
					task = commands[key];
					enCours = true;
					key++;
				}
			}
			else if (enCours)
			{
				switch (task)
				{
				case 1:
					if (remaining)
					{
						tortue.Avancer(1);
						remaining--;

						if (etatCrayon)
						{
							RectangleShape line(Vector2f(1, 3));
							line.setPosition(tortue.getPosition());
							line.setFillColor(Color::Black);
							line.rotate(180 - tortue.getAngle());
							temp_lines.push_back(line);
						}
					}
					else
					{
						if (etatCrayon)
						{
							temp_lines.clear();
							RectangleShape line(Vector2f(re, 3));
							line.setPosition(tortue.getPosition());
							line.setFillColor(Color::Black);
							line.rotate(180 - tortue.getAngle());
							lines.push_back(line);
						}
						enCours = false;
					}
					break;
				case 2:
					if (remaining)
					{
						tortue.Reculer(1);
						remaining--;

						if (etatCrayon)
						{
							RectangleShape line(Vector2f(1, 3));
							line.setPosition(tortue.getPosition());
							line.setFillColor(Color::Black);
							line.rotate(-tortue.getAngle());
							temp_lines.push_back(line);
						}
					}
					else
					{
						if (etatCrayon)
						{
							temp_lines.clear();
							RectangleShape line(Vector2f(re, 3));
							line.setPosition(tortue.getPosition());
							line.setFillColor(Color::Black);
							line.rotate(-tortue.getAngle());
							lines.push_back(line);
						}
						enCours = false;
					}
					break;
				case 3:
					if (remaining)
					{
						tortue.Gauche(1);
						remaining--;
					}
					else enCours = false;
					break;
				case 4:
					if (remaining)
					{
						tortue.Droite(1);
						remaining--;
					}
					else enCours = false;
					break;
				case 5:
					etatCrayon = false;
					enCours = false;
					break;
				case 6:
					etatCrayon = true;
					enCours = false;
					break;
				case 7:
					tortue.setPosition(355, 340);
					enCours = false;
					break;
				case 8:
					lines.clear();
					enCours = false;
					break;
				case 9:
					break;

				}
				tortue.wait();
			}
		}
		for (int i = 0; i < lines.size(); i++)
		{
			window.draw(lines[i]);
		}
		for (int i = 0; i < temp_lines.size(); i++)
		{
			window.draw(temp_lines[i]);
		}

		window.draw(tortue.getSprite());
		window.display();
	}

}

void Menu::Clear()
{
	lines.clear();
	texts.clear();
	commands.clear();
	repeat.clear();
}