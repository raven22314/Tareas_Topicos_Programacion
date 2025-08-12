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
	// un arreglo de N forwards lists, donde cada una corresponde a un índice de la hash table.
	forward_list<T>* data;
	unsigned int arraySize;
	// unsigned = SIN signo, es decir, no puede ser negativo.

	// size_t // es solamente un int de 64 bits unsigned (no-negativo).
	// originalmente, se supone que es el tamaño estándar de las variables (direcciones de memoria) que maneja en el sistema operativo.

public:

	HashTableChaining(unsigned int size)
	{
		// pedimos memoria para nuestras N listas.
		data = new forward_list<T>[size];
		arraySize = size;
		// ahora tenemos un arreglo de listas vacías

	}

	// necesitan una función hash, que es la que mapea desde una llave hacia un índice
	// es una función que toma un valor del tipo T y lo convierte en un entero
	int HashFunction(T key)
	{
		// en este ejemplo asumimos que T es un entero y usamos el operador módulo
		return key % arraySize;
	}

	// métodos de insertar, quitar, buscar e iterar.
	virtual void Add(T element)
	{
		int index = HashFunction(element);
		data[index].push_front(element); // esto de aquí es complejidad constante, no aumenta conforme más elementos haya.

		// arraySize = 10
		// element = 39
		// int index = HashFunction(element); nos da 9
		// data[index] = element; nos daría que data[9] = 39
	}

	// aquí, remove SÍ es lineal en el aspecto de que crece conforme crece la cantidad de elementos guardados,
	// pero no es directamente 'n', si no que es "n/arraySize" (en el caso promedio), lo cual la hace un poco mejor.
	void Remove(T element)
	{
		int index = HashFunction(element);// obtenemos el índice en el que debe estar el elemento
		forward_list<T>& listAtIndex = data[index];// referencia directa a la lista correspondiente para no copiarla

		for (auto i : listAtIndex) // esto es básicamente un foreach
		{
			if (i == element)
			{
				// quitamos este elemento y salimos de la función.
				listAtIndex.remove(i);
				return;
			}
		}
		// si no se encuentra el elemento, lanzamos una excepción

		throw runtime_error("no element " + to_string(element) + " in this hash table.");
	}

	// contains es la función de búsqueda.
	bool Contains(T element)
	{
		int index = HashFunction(element);		// si no se encuentra el elemento, lanzamos una excepción

		forward_list<T>& listAtIndex = data[index];// lista correspondiente al índice
		for (auto i : listAtIndex) // esto es básicamente un foreach
		{
			if (i == element)
			{
				// encontramos el elemento y salimos de la función.
				return true;
			}
		}
		return false; // retorna false porque si se llegó a esta línea es que nunca se entró al true de arriba.
	}

	void Print()
	{
		// vamos a iterar por cada uno de los índices
		for (int i = 0; i < arraySize; i++)
		{
			cout << "lista del índice: " << std::to_string(i) << ": ";
			// en cada índice hay una lista, entonces iteramos en toda la lista.
			for (auto j : data[i]) // recuerden, este for con auto nos itera la lista de inicio a fin.
				cout << j << ", ";

			cout << endl;

		}

	}
};

// Clase HashSet 
// Esta clase hereda de HashTableChaining para aprovechar todo su funcionamiento.
// La única diferencia es que vamos a sobrescribir el método Add para que no permita elementos repetidos.

template <typename T>
class HashSet : public HashTableChaining<T>
{
public:
	// constructor: recibe el tamaño de la tabla y lo envía al constructor de la clase base
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




