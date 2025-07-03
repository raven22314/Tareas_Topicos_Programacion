//Ever Ledesma Anklom 
#include <iostream>
using namespace std;
//Recursos Utilizados 
//https://cplusplus.com/reference/
//Recursos vistos en clase y asi mismo codigos del profesor

// activar 1 o desactivar 0 
#define CONTAR_COPIAS 1

// clase nodo que guarda un dato y un apuntador al siguiente nodo
template <typename T>
class Node {
public:
    T data;           // aquí se guarda el valor
    Node<T>* next;    // aquí se guarda el apuntador al siguiente nodo

    Node(T value) {
        data = value;
        next = nullptr;
    }

    // constructor de copia para contar copias si se activa
    Node(const Node<T>& other) {
        data = other.data;
        next = nullptr;

#if CONTAR_COPIAS != 0
        copyCounter++;
#endif
    }

#if CONTAR_COPIAS != 0
    static int copyCounter; // contador de copias
#endif
};

#if CONTAR_COPIAS != 0
// definición del contador de copias fuera de la clase
template <typename T>
int Node<T>::copyCounter = 0;
#endif

// clase lista ligada simple
template <typename T>
class LinkedList {
private:
    Node<T>* first;   // apunta al primer nodo
    int count;        // cuenta cuántos elementos hay en la lista

public:
    LinkedList() {
        first = nullptr;
        count = 0;
    }

    // inserta un valor al inicio de la lista
    void push_front(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = first;
        first = newNode;
        count++;
    }

    // elimina el primer nodo de la lista
    void pop_front() {
        if (first == nullptr) {
            cout << "la lista ya está vacía, no se puede hacer pop_front" << endl;
            return;
        }
        Node<T>* temp = first;
        first = first->next;
        delete temp;
        count--;
    }

    // imprime la lista desde el inicio hasta el final
    void Print() {
        Node<T>* current = first;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // función que borra todos los nodos (libera memoria)
    void clear() {
        while (first != nullptr) {
            pop_front(); // elimina uno por uno
        }
    }

    // devuelve la cantidad de elementos
    int getCount() {
        return count;
    }

#if CONTAR_COPIAS != 0
    // devuelve el número de copias realizadas
    static int GetCopyCounter() {
        return Node<T>::copyCounter;
    }
#endif
};

// función principal para probar la lista
int main() {
    LinkedList<int> lista;

    lista.push_front(10); // mete 10
    lista.push_front(20); // mete 20 antes
    lista.push_front(30); // mete 30 antes de todo

    cout << "contenido de la lista: ";
    lista.Print(); // imprime: 30 20 10

    lista.pop_front(); // quita el primer nodo (30)

    cout << "después de pop_front: ";
    lista.Print(); // imprime: 20 10

    // 2.2: llamamos a clear() manualmente para liberar memoria y evitar memory leaks
    lista.clear();

#if CONTAR_COPIAS != 0
    cout << "copias realizadas: " << LinkedList<int>::GetCopyCounter() << endl;
#endif

    return 0;
}

