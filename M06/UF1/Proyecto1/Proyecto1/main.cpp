#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

int main()
{
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

	while (ip.good())
	{
		std::getline(ip, nombre, ';');
		std::getline(ip, apellido, ';');
		std::getline(ip, edadString, ';');
		std::getline(ip, pesoString, '\n');

		std::string::size_type sz;  

		int edad = std::stoi(edadString, &sz);
		int peso = std::stoi(pesoString, &sz);

		std::cout << "Nombre: " << nombre << " " << apellido << '\n';
		std::cout << "Edad: " << edad << '\n';
		std::cout << "Peso: " << peso << '\n';
		std::cout << "====================" << '\n';
	}

	ip.close();
}
