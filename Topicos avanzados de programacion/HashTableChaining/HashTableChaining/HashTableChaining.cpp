#pragma once
#include "HashSet.h"
#include <iostream>
#include <string>
using namespace std;

void HashTableChainingExample()
{
    // crear hash table 
    HashTableChaining<int> hashTable(10);

    // anadir elementos ala hashtable
    hashTable.Add(15);
    hashTable.Add(25);
    hashTable.Add(35);

    // imprimir hash table
    cout << "HashTableChaining contents:" << endl;
    hashTable.Print();

    // checar si existe
    cout << "Contiene 25: " << (hashTable.Contains(25) ? "Si" : "No") << endl;

	// remover un elemento
    hashTable.Remove(25);
    cout << "despues de remover:" << endl;
    hashTable.Print();

	// crear hash setc con instancia
    HashSet<int> hashSet(10);

	// anadir elementos al hash set
    hashSet.Add(15);
    hashSet.Add(25);
	hashSet.Add(15); // duplicado, no se agregará

	// imimir hash set
    cout << "HashSet contiene:" << endl;
    hashSet.Print();
}

int main()
{
    // Creamos un HashSet de tamaño 5
    HashSet<int> miSet(5);

    // Agregamos algunos elementos
    miSet.Add(10);
    miSet.Add(20);
    miSet.Add(15);
    miSet.Add(20); // este es repetido, debería mostrar mensaje
    miSet.Add(25);
    miSet.Add(15); // repetido

    // Mostramos el contenido del HashSet
    cout << "\nContenido del HashSet:\n";
    miSet.Print();

    // Probamos búsqueda
    cout << "\n¿Contiene el 20? " << (miSet.Contains(20) ? "Sí" : "No") << endl;
    cout << "¿Contiene el 99? " << (miSet.Contains(99) ? "Sí" : "No") << endl;

    // Probamos eliminar
    cout << "\nEliminando el 20...\n";
    miSet.Remove(20);
    miSet.Print();

    return 0;
}