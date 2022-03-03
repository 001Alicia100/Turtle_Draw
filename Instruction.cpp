#include "Instruction.h"

string Instruction::checkError(void)
{
	string errors;
	bool err = false;
	if (!texts.size())
	{
		errors += "Aucune instruction entrée";
		err = true;
	}

	for (int i = 0; i < texts.size(); i++)
	{
		string s = texts[i].getString();
		size_t pos = 0;
		string token;
		// Boucle pour connaitre chaque mot entre les espaces.
		if (pos = s.find(" ") == string::npos)
		{
			if (s=="fin" or s == "origine" or s == "" or s =="nettoie" or s =="leveCrayon" or s == "poseCrayon")
			{

			}
			else
			{

				errors += s + " n'est pas une \ncommande valide seule.\n";
				err = true;
			}
		}
		else
		{
			pos = s.find(" ");
			token = s.substr(0, pos);
			s.erase(0, pos + 1);
			if (token == "avancer")
			{
				if (s.find_first_not_of("0123456789")==string::npos)
				{
				}
				else
				{
					errors += "Ligne ";
					errors += to_string(i + 1);
					errors += " :\navancer doit être suivi d'un flottant.\n";
					err = true;

				}
			}
			else if (token == "reculer")
			{
				if (s.find_first_not_of("0123456789") == string::npos)
				{
				}
				else
				{
					errors += "Ligne ";
					errors += to_string(i + 1);
					errors += " :\nreculer doit être suivi d'un flottant.\n";
					err = true;

				}
			}
			else if (token == "gauche")
			{
				if (s.find_first_not_of("0123456789") == string::npos)
				{
				}
				else
				{
					errors += "Ligne ";
					errors += to_string(i + 1);
					errors += " :\ngauche doit être suivi d'un flottant.\n";
					err = true;

				}
			}
			else if (token == "droite")
			{
				if (s.find_first_not_of("0123456789") == string::npos)
				{
				}
				else
				{
					errors += "Ligne ";
					errors += to_string(i + 1);
					errors += " :\ndroite doit être suivi d'un flottant.\n";
					err = true;

				}
			}
			else if (token == "repete")
			{
				if (s.find_first_not_of("0123456789") == string::npos)
				{
				}
				else
				{
					errors += "Ligne ";
					errors += to_string(i + 1);
					errors += " :\nrepete doit être suivi d'un flottant.\n";
					err = true;

				}
			}
			else
			{
				errors += token + " n'est pas une \ncommande valide.\n";
				err = true;
			}
		}
	}
	if (!err) return "Code OK!\n";
	else return errors;
}

vector<int> Instruction::translate(void)
{
	vector<int> commands;
	for (int i = 0; i < texts.size(); i++)
	{
		string s = texts[i].getString();
		size_t pos = 0;
		string token;
		// Boucle pour connaitre chaque mot entre les espaces.
		if (pos = s.find(" ") == string::npos)
		{
			if (s == "origine")
			{
				commands.push_back(7);
			}
			else if (s == "nettoie")
			{
				commands.push_back(8);
			}

			else if (s == "leveCrayon")
			{
				commands.push_back(5);

			}
			else if (s == "poseCrayon")
			{
				commands.push_back(6);

			}
			else if (s == "fin")
				commands.push_back(10);
			
		}
		else
		{
			pos = s.find(" ");
			token = s.substr(0, pos);
			s.erase(0, pos + 1);

			if (token == "avancer")
			{
				commands.push_back(1);
				commands.push_back(atoi(s.c_str()));
			}
			else if (token == "reculer")
			{
				commands.push_back(2);
				commands.push_back(atoi(s.c_str()));

			}
			else if (token == "gauche")
			{
				commands.push_back(3);
				commands.push_back(atoi(s.c_str()));

			}
			else if (token == "droite")
			{
				commands.push_back(4);
				commands.push_back(atoi(s.c_str()));

			}
			else if (token == "repete")
			{
				commands.push_back(9);
				commands.push_back(atoi(s.c_str()));

			}

		}
	}
	return commands;
}


