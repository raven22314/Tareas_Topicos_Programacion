//Ever Ledesma Anklom 
#pragma once

#include <iostream>
using namespace std;

//Recursos utilizados 
//Codigo sentinellinked list del profe 
//https://www.w3schools.com/cpp/cpp_queues.asp

// Definimos una clase plantilla SentinelLinkedList 
template <typename T>
class SentinelLinkedList {
private:
    // Clase interna para los nodos de la lista
    template <typename T>
    class Node {
    public:
        Node() {
            prev = nullptr;
            next = nullptr;
        }

        Node(T value) {
            data = value;
            prev = nullptr;
            next = nullptr;
        }

        T data;             
        Node<T>* next;      
        Node<T>* prev;      
    };

    Node<T>* NIL; 
    int count;    
    int operationCounter;

public:
    
    SentinelLinkedList() {
        count = 0;
        NIL = new Node<T>();   
        NIL->next = NIL;       
        NIL->prev = NIL;       
        operationCounter = 0;
    }

    // Destructor: libera todos los nodos usados
    ~SentinelLinkedList() {
        Clear();
        delete NIL;
    }

    // Devuelve cuántos elementos hay en la lista
    int GetCount() { return count; };

   
    Node<T>* Find(T value) {
        Node<T>* currentNode = NIL->next;
        while (currentNode != NIL) {
            if (currentNode->data == value) {
                return currentNode;
            }
            currentNode = currentNode->next;
        }
        return nullptr; 
    }

    
    Node<T>* FindV2(T value) {
        Node<T>* currentNode = NIL->next;
        while (currentNode != NIL) {
            if (currentNode->data == value)
                return currentNode;
            currentNode = currentNode->next;
        }
        return nullptr;
    }

    
    Node<T>* Successor(Node<T>* node) {
        return node->next;
    }

    
    Node<T>* Predecessor(Node<T>* node) {
        return node->prev;
    }

  
    void PushBack(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = NIL;
        NIL->prev->next = newNode;
        newNode->prev = NIL->prev;
        NIL->prev = newNode;
        count++; 
    }

    // Elimina el último nodo y devuelve su valor
    T PopBack() {
        if (count == 0) {
            cout << "Cuidado, estás haciendo pop back cuando ya no hay elementos en esta lista ligada";
            return T{};
        }

        Node<T>* penultimateNode = NIL->prev;
        T data = penultimateNode->data;

        NIL->prev = penultimateNode->prev;
        penultimateNode->prev->next = NIL;

        delete penultimateNode;
        count--;

        return data;
    }

    
    void Insert(T valueToInsert, Node<T>* previousNode) {
        Node<T>* newNode = new Node<T>(valueToInsert);
        newNode->next = previousNode->next;
        newNode->prev = previousNode;
        previousNode->next->prev = newNode;
        previousNode->next = newNode;
        count++;
    }

    
    void Remove(T valueToRemove) {
        Node<T>* currentNode = NIL->next;
        while (currentNode != NIL) {
            if (currentNode->data == valueToRemove) {
                currentNode->prev->next = currentNode->next;
                currentNode->next->prev = currentNode->prev;
                delete currentNode;
                count--;
                return;
            }
            else {
                currentNode = currentNode->next;
            }
        }
    }

    // Devuelve el valor del primer nodo 
    T Front() {
        if (count == 0) {
            cout << "Advertencia, lista vacía" << endl;
            return T{};
        }
        return NIL->next->data;
    }

    // Elimina el primer nodo de la lista y devuelve su valor
    T Pop_Front() {
        if (count == 0) {
            cout << "Advertencia: Pop_Front en lista vacía" << endl;
            return T{};
        }

        Node<T>* firstNode = NIL->next;
        T data = firstNode->data;

        NIL->next = firstNode->next;
        firstNode->next->prev = NIL;

        delete firstNode;
        count--;
        return data;
    }

    // Elimina todos los nodos de la lista
    void Clear() {
        while (count > 0) {
            Pop_Front();
        }
    }
};

// Clase LQueue
template <typename T>
class LQueue {
private:
    SentinelLinkedList<T> data; // Lista que almacena los elementos

public:
    LQueue() = default; // Constructor por defecto

    // Devuelve el número de elementos en la cola
    int GetCount() {
        return data.GetCount();
    }

    // Agrega un elemento al final de la cola
    void Enqueue(T value) {
        data.PushBack(value);
    }

    

    // Devuelve el elemento al frente de la cola 
    T Front() {
        return data.Front();
    };
};

// Función principal de prueba
int main() {
    LQueue<int> miCola;

    // Insertamos elementos a la cola
    miCola.Enqueue(10);
    miCola.Enqueue(20);
    miCola.Enqueue(30);

    // Mostramos el primero
    cout << "Front: " << miCola.Front() << endl;

  //eliminado

    return 0;
}


