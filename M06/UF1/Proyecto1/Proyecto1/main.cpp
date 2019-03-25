#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

std::string* textures;

std::string levelTitle;

std::string* levelMapColumns;
std::string* levelMapRows;

//void LoadBackground(std::ifstream& file, )
void LoadTextures(std::ifstream& file, int num)
{
	std::string word;

	textures = new std::string[num + 1];
	textures[0] = "none";

	int counter = 1;
	while (counter < num + 1)
	{
		std::getline(file, word, ';');
		std::getline(file, word, ';');
		textures[counter] = word;
		std::cout << word << '\n';
		std::getline(file, word, '\n');

		counter++;
	}

	/*for (int i = 0; i <= numTextures; i++)
	{
		std::getline(*file, numBuffer, ';');
		textures[i] = std::stoi(numBuffer);
		std::getline(*file, textures[i], ';');
		std::cout << "Numero " << indTexture[i] << " " << textures[i] << '\n';
		std::getline(*file, numBuffer, '\n');
	}*/
}

void LoadLevels(std::ifstream& file, int num)
{
	std::string sz;
	std::string word;
	int columns;
	int rows;

	levelMapColumns = new std::string[num +1];
	levelMapRows = new std::string[num +1];

	int counter = 1;
	while (counter < num + 1)
	{
		std::getline(file, word, ';');
		if (word.compare("LEVEL") == 0)
		{
			std::getline(file, word, ';');
			std::getline(file, word, ';');
			levelTitle = word;
			std::getline(file, word, ';');
			levelMapColumns[counter] = word;
			columns = std::stoi(word);
			std::getline(file, word, ';');
			levelMapRows[counter] = word;
			rows = std::stoi(word);
			std::cout << levelMapColumns[counter] << " " << levelMapRows[counter] << '\n';
			std::getline(file, word, '\n');

		}
		else if (word.compare("BACKGROUND") == 0)
		{
			std::getline(file, word, ';');
			std::getline(file, word, '\n');
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					std::getline(file, word, ';');
					//PROCESAR BACKGROUND
				}
				std::getline(file, word, '\n');
			}
		}
		else if (word.compare("COLLISION") == 0)
		{
			std::getline(file, word, ';');
			std::getline(file, word, '\n');
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					std::getline(file, word, ';');
					//PROCESAR COLLISION
				}
				std::getline(file, word, '\n');
			}
		}
		else if (word.compare("FOREGROUND") == 0)
		{
			std::getline(file, word, ';');
			std::getline(file, word, '\n');
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					std::getline(file, word, ';');
					//PROCESAR FOREGROUND
				}
				std::getline(file, word, '\n');
			}
			counter++;
		}
	}
}
int main(int argc, char* argv[])
{
	std::ifstream game_conf("../Proyecto1/game.csv");

	if (!game_conf.is_open())
	{
		std::cout << "ERROR: Error al abrir el archivo" << '\n';
		return 1;
	}

	std::string word;
	std::string title;
	int indicesNum = 0;

	while (game_conf.good())
	{
		std::getline(game_conf, word, ';');

		if (word.compare("TEXTURES") == 0)
		{
			std::getline(game_conf, word, ';');
			indicesNum = std::stoi(word);
			std::getline(game_conf, word, '\n');
			LoadTextures(game_conf, indicesNum);
		}
		else if (word.compare("TITLE") == 0)
		{
			std::getline(game_conf, title, ';');
			std::getline(game_conf, word, '\n');

			std::cout << title << std::endl;
		}
		else if (word.compare("LEVELS") == 0)
		{
			std::getline(game_conf, word, ';');
			indicesNum = std::stoi(word);
			std::getline(game_conf, word, '\n');
			LoadLevels(game_conf, indicesNum);
		}
	}

	game_conf.close();
}
