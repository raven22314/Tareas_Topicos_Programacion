//Ever Ledesma Anklom 
#include <iostream>
using namespace std;
//Recursos Utilizados 
//https://cplusplus.com/reference/
//Recursos vistos en clase y asi mismo codigos del profesor

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
};

// clase linkedlist que maneja la lista ligada simple
template <typename T>
class LinkedList {
private:
    Node<T>* first;   // apunta al primer nodo de la lista
    int count;        // cuenta cuántos elementos hay en la lista

public:
    LinkedList() {
        first = nullptr; // empieza vacía
        count = 0;
    }

    // 2) agrega un nodo al principio de la lista
    void push_front(T value) {
        Node<T>* newNode = new Node<T>(value); // crea nuevo nodo con el valor
        newNode->next = first; // conecta el nuevo nodo al inicio de la lista
        first = newNode; // ahora el nuevo nodo es el primero de la lista
        count++; // aumentamos el contador
    }

    // 2) quita el nodo del principio de la lista
    void pop_front() {
        if (first == nullptr) {
            cout << "la lista ya está vacía, no se puede hacer pop_front" << endl;
            return;
        }
        Node<T>* temp = first; // guardamos el primer nodo en una variable temporal
        first = first->next; // movemos el primer nodo al siguiente
        delete temp; // liberamos la memoria del nodo que quitamos
        count--; // reducimos el contador
    }

    
    void Print() {
        Node<T>* current = first; // empezamos desde el principio
        while (current != nullptr) {
            cout << current->data << " "; // imprimimos el valor del nodo
            current = current->next; // pasamos al siguiente nodo
        }
        cout << endl; 
    }

    

    int getCount() {
        return count; // regresa cuántos nodos hay en la lista
    }
};

// ejemplo de uso de la clase linkedlist
int main() {
    LinkedList<int> lista;

    lista.push_front(10); // mete 10 al inicio
    lista.push_front(20); // ahora 20 está antes que 10
    lista.push_front(30); // ahora 30 está antes que 20

    cout << "contenido de la lista: ";
    lista.Print(); // imprime la lista

    lista.pop_front(); // quita el primer nodo 30

    cout << "después de pop_front: ";
    lista.Print();

    return 0;
}
