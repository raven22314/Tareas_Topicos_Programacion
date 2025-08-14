#pragma once
#include "HashTable1.h" // Corrected file extension to .h
using namespace std;

// Clase HashSet 
// Esta clase hereda de HashTableChaining para aprovechar todo su funcionamiento.
// La única diferencia es que vamos a sobrescribir el método Add para que no permita elementos repetidos.

template <typename T>
class HashSet : public HashTableChaining<T>
{
public:
	// constructor: recibe el tamańo de la tabla y lo envía al constructor de la clase base
	HashSet(unsigned int size) : HashTableChaining<T>(size) {}

	// método Add sobrescrito para evitar elementos repetidos
	void Add(T element) override
	{
		// primero verificamos si el elemento ya existe
		if (!this->Contains(element)) // usamos Contains de la clase base
		{
			// si no existe, lo agregamos normalmente usando Add de la clase base
			HashTableChaining<T>::Add(element);
		}
		else
		{
			// si ya existe, mostramos un mensaje y no lo agregamos
			cout << "Elemento repetido: " << element << endl;
		}
	}
};