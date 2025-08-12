#pragma once
#include<HashTable1.h>
#include <iostream>
#include <forward_list> 
#include <string>
using namespace std;
//Ever Ledesma Anklom 

template <typename T>
class HashTableChaining
{
	// un lugar donde almacenar los datos
	// un arreglo de N forwards lists, donde cada una corresponde a un �ndice de la hash table.
	forward_list<T>* data;
	unsigned int arraySize;
	// unsigned = SIN signo, es decir, no puede ser negativo.

	// size_t // es solamente un int de 64 bits unsigned (no-negativo).
	// originalmente, se supone que es el tama�o est�ndar de las variables (direcciones de memoria) que maneja en el sistema operativo.

public:

	HashTableChaining(unsigned int size)
	{
		// pedimos memoria para nuestras N listas.
		data = new forward_list<T>[size];
		arraySize = size;
		// ahora tenemos un arreglo de listas vac�as

	}

	// necesitan una funci�n hash, que es la que mapea desde una llave hacia un �ndice
	// es una funci�n que toma un valor del tipo T y lo convierte en un entero
	int HashFunction(T key)
	{
		// en este ejemplo asumimos que T es un entero y usamos el operador m�dulo
		return key % arraySize;
	}

	// m�todos de insertar, quitar, buscar e iterar.
	virtual void Add(T element)
	{
		int index = HashFunction(element);
		data[index].push_front(element); // esto de aqu� es complejidad constante, no aumenta conforme m�s elementos haya.

		// arraySize = 10
		// element = 39
		// int index = HashFunction(element); nos da 9
		// data[index] = element; nos dar�a que data[9] = 39
	}

	// aqu�, remove S� es lineal en el aspecto de que crece conforme crece la cantidad de elementos guardados,
	// pero no es directamente 'n', si no que es "n/arraySize" (en el caso promedio), lo cual la hace un poco mejor.
	void Remove(T element)
	{
		int index = HashFunction(element);// obtenemos el �ndice en el que debe estar el elemento
		forward_list<T>& listAtIndex = data[index];// referencia directa a la lista correspondiente para no copiarla

		for (auto i : listAtIndex) // esto es b�sicamente un foreach
		{
			if (i == element)
			{
				// quitamos este elemento y salimos de la funci�n.
				listAtIndex.remove(i);
				return;
			}
		}
		// si no se encuentra el elemento, lanzamos una excepci�n

		throw runtime_error("no element " + to_string(element) + " in this hash table.");
	}

	// contains es la funci�n de b�squeda.
	bool Contains(T element)
	{
		int index = HashFunction(element);		// si no se encuentra el elemento, lanzamos una excepci�n

		forward_list<T>& listAtIndex = data[index];// lista correspondiente al �ndice
		for (auto i : listAtIndex) // esto es b�sicamente un foreach
		{
			if (i == element)
			{
				// encontramos el elemento y salimos de la funci�n.
				return true;
			}
		}
		return false; // retorna false porque si se lleg� a esta l�nea es que nunca se entr� al true de arriba.
	}

	void Print()
	{
		// vamos a iterar por cada uno de los �ndices
		for (int i = 0; i < arraySize; i++)
		{
			cout << "lista del �ndice: " << std::to_string(i) << ": ";
			// en cada �ndice hay una lista, entonces iteramos en toda la lista.
			for (auto j : data[i]) // recuerden, este for con auto nos itera la lista de inicio a fin.
				cout << j << ", ";

			cout << endl;

		}

	}
};

// Clase HashSet 
// Esta clase hereda de HashTableChaining para aprovechar todo su funcionamiento.
// La �nica diferencia es que vamos a sobrescribir el m�todo Add para que no permita elementos repetidos.

template <typename T>
class HashSet : public HashTableChaining<T>
{
public:
	// constructor: recibe el tama�o de la tabla y lo env�a al constructor de la clase base
	HashSet(unsigned int size) : HashTableChaining<T>(size) {}

	// m�todo Add sobrescrito para evitar elementos repetidos
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

void HashTableChainingExample()
{
    // Create a HashTableChaining instance with integer keys
    HashTableChaining<int> hashTable(10);

    // Add elements to the hash table
    hashTable.Add(15);
    hashTable.Add(25);
    hashTable.Add(35);

    // Print the hash table
    cout << "HashTableChaining contents:" << endl;
    hashTable.Print();

    // Check if an element exists
    cout << "Contains 25: " << (hashTable.Contains(25) ? "Yes" : "No") << endl;

    // Remove an element
    hashTable.Remove(25);
    cout << "After removing 25:" << endl;
    hashTable.Print();

    // Create a HashSet instance with integer keys
    HashSet<int> hashSet(10);

    // Add elements to the hash set
    hashSet.Add(15);
    hashSet.Add(25);
    hashSet.Add(15); // Duplicate element

    // Print the hash set
    cout << "HashSet contents:" << endl;
    hashSet.Print();
}




