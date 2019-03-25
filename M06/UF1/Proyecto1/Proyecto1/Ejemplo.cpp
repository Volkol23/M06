#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[])
{
	//Parsear ficheros CSV

	std::ifstream ip("../Proyecto1/personas.csv");

	if (!ip.is_open())
	{
		std::cout << "ERROR: Error al abrir el archivo" << '\n';
		return 1;
	}

	std::string nombre;
	std::string apellido;
	std::string edadString;
	std::string pesoString;

	int edad;
	float peso;

	while (ip.good())
	{
		std::getline(ip, nombre, ';');
		std::getline(ip, apellido, ';');
		std::getline(ip, edadString, ';');
		std::getline(ip, pesoString, '\n');

		edad = std::stoi(edadString);
		peso = std::stof(pesoString);

		std::cout << "Nombre: " << nombre << " " << apellido << '\n';
		std::cout << "Edad: " << edad << '\n';
		std::cout << "Peso: " << peso << '\n';
		std::cout << "====================" << '\n';
	}

	ip.close();

	//Escribir ficheros CSv

	std::ofstream archivo;

	archivo.open("datos.csv");

	archivo << "a;b;c;\n";
	archivo << "d;e;f;\n";
	archivo << "1;2;3.456;\n";
	archivo.close();

	return 0;
}