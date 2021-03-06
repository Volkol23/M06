#include "pch.h"
#include "raylib.h"
#include <iostream>
#include <fstream>
#include <string>

std::string* textures;

struct level {
	std::string title;
	int number;
	int width;
	int height;
	int** background;
	std::string** collision;
	int** foreground;
};
//std::string levelTitle;

//std::string* levelMapColumns;
//std::string* levelMapRows;

level* levels;

//int ProcesData(level level, int ind, std::ifstream& conf)
//{
//	std::string word;
//
//	std::getline(conf, word, ';');
//	std::getline(conf, word, '\n');
//	for (int i = 0; i < levels[ind].height; i++)
//	{
//		for (int j = 0; j < levels[ind].width; j++)
//		{
//			std::getline(conf, word, ';');
//			levels[ind].background[i][j] = std::stoi(word);
//			//PROCESAR BACKGROUND
//			std::cout << levels[ind].background[i][j];
//		}
//		std::cout << '\n';
//		std::getline(conf, word, '\n');
//	}
//	return 0;
//}

int LoadTextures(std::ifstream& file, int num)
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
	};

	return 0;
	/*for (int i = 0; i <= numTextures; i++)
	{
		std::getline(*file, numBuffer, ';');
		textures[i] = std::stoi(numBuffer);
		std::getline(*file, textures[i], ';');
		std::cout << "Numero " << indTexture[i] << " " << textures[i] << '\n';
		std::getline(*file, numBuffer, '\n');
	}*/
	delete textures;
}

int LoadBackground(std::ifstream& file, int levelNum, int width, int height)
{
	std::string word;
	int value = -1;
	for (int i = 0; i < height; i++) // de arriba a abajo Intercambiar ancho por alto
	{
		for (int j = 0; j < width; j++) // de izquierda a derecha
		{
			std::getline(file, word, ';');
			value = std::stoi(word);
			levels[levelNum].background[i][j] = value;
			std::cout << value;
		}
		std::cout << '\n';
		std::getline(file, word, '\n');
	};
	return 0;
}

int LoadForeground(std::ifstream& file, int levelNum, int width, int height)
{
	std::string word;
	int value = -1;
	for (int i = 0; i < height; i++) // de arriba a abajo Intercambiar ancho por alto
	{
		for (int j = 0; j < width; j++) // de izquierda a derecha
		{
			std::getline(file, word, ';');
			value = std::stoi(word);
			levels[levelNum].foreground[i][j] = value;
			std::cout << value;
		}
		std::cout << '\n';
		std::getline(file, word, '\n');
	};
	return 0;
}

int LoadCollision(std::ifstream& file, int levelNum, int width, int height)
{
	std::string word;
	for (int i = 0; i < height; i++) // de arriba a abajo Intercambiar ancho por alto
	{
		for (int j = 0; j < width; j++) // de izquierda a derecha
		{
			std::getline(file, word, ';');
			levels[levelNum].collision[i][j] = word;
			std::cout << word;
		}
		std::cout << '\n';
		std::getline(file, word, '\n');
	};
	return 0;
}

int LoadLevels(std::ifstream& file, int num)
{
	std::string sz;
	std::string word;
	//int columns;
	//int rows;
	int numLevel;
	int width;
	int height;
	std::string title;

	levels = new level[num + 1];
	levels[0].title = "none";
	//levelMapColumns = new std::string[num +1];
	//levelMapRows = new std::string[num +1];


	//if (word.compare("LEVEL") == 0)
	//{
	for (int i = 1; i < num + 1; i++)
	{
		std::getline(file, word, ';');
		if (word.compare("LEVEL") != 0)
		{
			return 1;
		}
		std::getline(file, word, ';');
		numLevel = std::stoi(word);

		std::getline(file, word, ';');
		title = word;

		std::getline(file, word, ';');
		width = std::stoi(word);

		std::getline(file, word, ';');
		height = std::stoi(word);

		std::getline(file, word, '\n');

		levels[i].background = new int*[height];
		levels[i].collision = new std::string*[height];
		levels[i].foreground = new int*[height];
		for (int j = 0; j < height; j++)
		{
			levels[i].background[j] = new int[width];
			levels[i].collision[j] = new std::string[width];
			levels[i].foreground[j] = new int[width];
		}

		for (int k = 0; k < 3; k++)
		{
			std::getline(file, word, ';');
			std::string block = word;
			std::getline(file, word, '\n');

			std::cout << block << '\n';
			if (block.compare("BACKGROUND") == 0)
			{
				LoadBackground(file, i, width, height);
			}
			else if (block.compare("COLLISION") == 0)
			{
				LoadCollision(file, i, width, height);
			}
			else if (block.compare("FOREGROUND") == 0)
			{
				LoadForeground(file, i, width, height);
			}
		}
	};
	//}
	//else if (word.compare("BACKGROUND") == 0)
	//{
	//	std::getline(file, word, ';');
	//	std::getline(file, word, '\n');
	//	for (int i = 0; i < levels[counter].height; i++)
	//	{
	//		for (int j = 0; j < levels[counter].width; j++)
	//		{
	//			std::getline(file, word, ';');
	//			levels[counter].background[i][j] = std::stoi(word);
	//			//PROCESAR BACKGROUND
	//			std::cout << levels[counter].background[i][j];
	//		}
	//		std::cout << '\n';
	//		std::getline(file, word, '\n');
	//	}
	//	//ProcesData(levels[counter], counter, file);
	//}
	//else if (word.compare("COLLISION") == 0)
	//{
	//	std::getline(file, word, ';');
	//	std::getline(file, word, '\n');
	//	for (int i = 0; i < levels[counter].height; i++)
	//	{
	//		for (int j = 0; j < levels[counter].width; j++)
	//		{
	//			std::getline(file, word, ';');
	//			levels[counter].collision[i][j] = word;
	//			//PROCESAR BACKGROUND
	//			std::cout << levels[counter].collision[i][j];
	//		}
	//		std::cout << '\n';
	//		std::getline(file, word, '\n');
	//	}
	//}
	//else if (word.compare("FOREGROUND") == 0)
	//{
	//	std::getline(file, word, ';');
	//	std::getline(file, word, '\n');
	//	for (int i = 0; i < levels[counter].height; i++)
	//	{
	//		for (int j = 0; j < levels[counter].width; j++)
	//		{
	//			std::getline(file, word, ';');
	//			levels[counter].foreground[i][j] = std::stoi(word);
	//			//PROCESAR BACKGROUND
	//			std::cout << levels[counter].foreground[i][j];
	//		}
	//		std::cout << '\n';
	//		std::getline(file, word, '\n');
	//	}
	//	counter++;
	//}
	//else if
	//{
	//	return 1;
	//}

	return 0;
}
int main(int argc, char* argv[])
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;
	std::ifstream game_conf("../Proyecto1/game.csv");

	if (!game_conf.is_open())
	{
		std::cout << "ERROR: Error al abrir el archivo" << '\n';
		return 1;
	}

	std::string word;
	std::string title;
	int indicesNum = 0;

	InitWindow(screenWidth, screenHeight, "raylib [shapes] example - raylib color palette");

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
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
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);

		DrawText("Hola que tal la raylib?", 28, 42, 20, BLACK);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------
	game_conf.close();
	return 0;
}