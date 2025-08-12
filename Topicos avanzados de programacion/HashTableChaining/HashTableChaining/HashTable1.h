#pragma once
#include <iostream>
#include <forward_list> 
#include <string>
using namespace std;

int main()
{
	// Creamos un HashSet de tama�o 5
	HashSet<int> miSet(5);

	// Agregamos algunos elementos
	miSet.Add(10);
	miSet.Add(20);
	miSet.Add(15);
	miSet.Add(20); // este es repetido, deber�a mostrar mensaje
	miSet.Add(25);
	miSet.Add(15); // repetido

	// Mostramos el contenido del HashSet
	cout << "\nContenido del HashSet:\n";
	miSet.Print();

	// Probamos b�squeda
	cout << "\n�Contiene el 20? " << (miSet.Contains(20) ? "S�" : "No") << endl;
	cout << "�Contiene el 99? " << (miSet.Contains(99) ? "S�" : "No") << endl;

	// Probamos eliminar
	cout << "\nEliminando el 20...\n";
	miSet.Remove(20);
	miSet.Print();

	return 0;
}

