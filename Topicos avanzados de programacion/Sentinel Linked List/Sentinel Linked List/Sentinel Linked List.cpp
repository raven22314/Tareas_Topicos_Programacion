//Ever Ledesma Anklom 
#pragma once
#include <iostream>
using namespace std;
//recursos utilizados 
//Codigos proporcionado por le profe
//https://www.geeksforgeeks.org/dsa/doubly-linked-list-using-sentinel-nodes/
//https://www.quora.com/Can-we-use-push-and-pop-in-a-linked-list-if-yes-then-how


// Clase de lista ligada con nodos centinela
template <typename T>
class SentinelLinkedList
{
private:
	// Clase interna que representa cada nodo de la lista
	class Node
	{
	public:
		Node() // Constructor sin valor (por defecto)
		{
			prev = nullptr;
			next = nullptr;
		}

		Node(T value) // Constructor con dato
		{
			data = value;
			prev = nullptr;
			next = nullptr;
		}

		T data;       // Valor almacenado en el nodo
		Node* next;   // Puntero al siguiente nodo
		Node* prev;   // Puntero al nodo anterior
	};

private:
	Node* NIL;  // Nodo centinela (marca el inicio y fin de la lista)
	int count;  // N�mero de elementos en la lista

public:
	// Constructor: inicializa lista vac�a con nodo centinela
	SentinelLinkedList()
	{
		count = 0;
		NIL = new Node(); // Se crea nodo centinela sin datos
		NIL->next = NIL;
		NIL->prev = NIL;
	}

	int GetCount() { return count; } // Devuelve n�mero de elementos

	// Buscar un nodo con valor dado
	Node* Find(T value);
	Node* FindV2(T value);

	// Devuelve el nodo siguiente de uno dado
	Node* Successor(Node* node) { return node->next; }

	// Devuelve el nodo anterior de uno dado
	Node* Predecessor(Node* node) { return node->prev; }

	// Agrega un nuevo nodo al final
	void PushBack(T value);

	// Elimina el nodo del final y devuelve su valor
	T PopBack();

	// Inserta un nuevo nodo despu�s de uno existente
	void Insert(T valueToInsert, Node* previousNode);

	// Elimina el primer nodo que tenga el valor dado
	void Remove(T valueToRemove);

	// Devuelve el valor del primer nodo sin eliminarlo
	T Front();

	// Agrega un nuevo nodo al inicio de la lista
	void PushFront(T value);

	// Elimina el nodo del inicio y devuelve su valor
	T PopFront();

	// Imprime los elementos de la lista
	void Print();

	// Elimina todos los nodos de la lista
	void Clear();

	int operationCounter; // (No se utiliza, se puede ignorar)
};

// Elimina el primer nodo que contenga el valor dado
template<typename T>
void SentinelLinkedList<T>::Remove(T valueToRemove)
{
	Node* currentNode = NIL->next;
	while (currentNode != NIL)
	{
		if (currentNode->data == valueToRemove)
		{
			currentNode->prev->next = currentNode->next;
			currentNode->next->prev = currentNode->prev;
			delete currentNode;
			count--;
			return;
		}
		currentNode = currentNode->next;
	}
}

// Busca el primer nodo con el valor (versi�n 1)
template<typename T>
typename SentinelLinkedList<T>::Node* SentinelLinkedList<T>::Find(T value)
{
	Node* currentNode = NIL->next;
	while (currentNode != NIL)
	{
		if (currentNode->data == value)
			return currentNode;
		currentNode = currentNode->next;
	}
	return nullptr; // No se encontr�
}

// Igual que Find pero llamada distinta (versi�n 2)
template<typename T>
typename SentinelLinkedList<T>::Node* SentinelLinkedList<T>::FindV2(T value)
{
	Node* currentNode = NIL->next;
	while (currentNode != NIL)
	{
		if (currentNode->data == value)
			return currentNode;
		currentNode = currentNode->next;
	}
	return nullptr;
}

// Inserta un nodo nuevo despu�s de previousNode
template<typename T>
void SentinelLinkedList<T>::Insert(T valueToInsert, Node* previousNode)
{
	Node* newNode = new Node(valueToInsert);
	newNode->next = previousNode->next;
	newNode->prev = previousNode;
	previousNode->next->prev = newNode;
	previousNode->next = newNode;
	count++;
}

// Agrega nodo al final de la lista
template<typename T>
void SentinelLinkedList<T>::PushBack(T value)
{
	Node* newNode = new Node(value);
	newNode->next = NIL;
	newNode->prev = NIL->prev;
	NIL->prev->next = newNode;
	NIL->prev = newNode;
	count++;
}

// Elimina el nodo del final y devuelve su valor
template<typename T>
T SentinelLinkedList<T>::PopBack()
{
	if (count == 0)
	{
		cout << "Cuidado, est�s haciendo PopBack en una lista vac�a." << endl;
		return {};
	}

	Node* lastNode = NIL->prev;
	NIL->prev = lastNode->prev;
	lastNode->prev->next = NIL;

	T data = lastNode->data;
	delete lastNode;
	count--;
	return data;
}

// Devuelve el valor del primer nodo sin eliminarlo
template <typename T>
T SentinelLinkedList<T>::Front()
{
	if (count == 0)
	{
		cout << "Advertencia: intentas acceder al primer elemento de una lista vac�a." << endl;
		return {};
	}
	return NIL->next->data;
}

// Agrega un nodo al principio de la lista
template<typename T>
void SentinelLinkedList<T>::PushFront(T value)
{
	Node* newNode = new Node(value);
	newNode->next = NIL->next;
	newNode->prev = NIL;
	NIL->next->prev = newNode;
	NIL->next = newNode;
	count++;
}

// Elimina el nodo del inicio y devuelve su valor
template<typename T>
T SentinelLinkedList<T>::PopFront()
{
	if (count == 0)
	{
		cout << "Cuidado, est�s haciendo PopFront en una lista vac�a." << endl;
		return {};
	}

	Node* firstNode = NIL->next;
	NIL->next = firstNode->next;
	firstNode->next->prev = NIL;

	T data = firstNode->data;
	delete firstNode;
	count--;
	return data;
}

// Imprime todos los elementos de la lista
template<typename T>
void SentinelLinkedList<T>::Print()
{
	if (count == 0)
	{
		cout << "(lista vac�a)";
	}
	else
	{
		Node* current = NIL->next;
		while (current != NIL)
		{
			cout << current->data << " ";
			current = current->next;
		}
	}
	cout << endl;
}

// Elimina todos los nodos, dejando la lista vac�a
template<typename T>
void SentinelLinkedList<T>::Clear()
{
	while (count > 0)
	{
		PopFront();
	}
}

// ------------------------------
// Funci�n principal para probar la lista
// ------------------------------
int main() {
	SentinelLinkedList<int> lista;

	lista.PushFront(10);  // Lista: 10
	lista.PushFront(20);  // Lista: 20 10
	lista.PushFront(30);  // Lista: 30 20 10

	cout << "Contenido de la lista: ";
	lista.Print();        // Muestra: 30 20 10

	lista.PopFront();     // Elimina 30, lista queda: 20 10

	cout << "Despu�s de PopFront: ";
	lista.Print();        // Muestra: 20 10

	lista.Clear();        // Elimina todos los elementos

	return 0;
}
