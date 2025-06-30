//Ever Ledesma Anklom 
#include <iostream>
using namespace std;
//Recursos Utilizados 
//https://cplusplus.com/reference/
//Recursos vistos en clase y asi mismo codigos del profesor



#define CONTAR_COPIAS 

// clase nodo que guarda un dato y un apuntador al siguiente nodo
template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T value) {
        data = value;
        next = nullptr;
    }
};

// clase linkedlist que maneja la lista ligada simple
template <typename T>
class LinkedList {
private:
    Node<T>* first;
    int count;

public:
    LinkedList() {
        first = nullptr;
        count = 0;
    }

    // libera todos los nodos existentes en la lista
    void clear() {
        while (first != nullptr) {
            Node<T>* temp = first;
            first = first->next;
            delete temp;
        }
        count = 0;
    }

    // Este método se puede usar cuando se quiere limpiar manualmente
    // También lo usamos al final del programa para no dejar memoria colgada

    void push_front(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = first;
        first = newNode;
        count++;
    }

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

    void Print() {
        Node<T>* current = first;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    int getCount() {
        return count;
    }
};

int main() {
    LinkedList<int> lista;

    lista.push_front(10);
    lista.push_front(20);
    lista.push_front(30);

    cout << "contenido de la lista: ";
    lista.Print();

    lista.pop_front();

    cout << "después de pop_front: ";
    lista.Print();

#if defined(CONTAR_COPIAS)
    // mostramos cuántas copias se hicieron si el conteo está activado
    // cout << "copias realizadas en resize: " << arr.GetCopyCounter() << endl;
#endif

    // Liberamos memoria al final del programa
    lista.clear();

    return 0;
}
