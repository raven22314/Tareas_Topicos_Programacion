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
    T data;          
    Node<T>* next;    

    Node(T value) {
        data = value;
        next = nullptr;
    }

   
};
// clase lista ligada simple


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

    ~LinkedList() {
        clear();
    }
    // clase lista ligada simple
    void push_front(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = first;
        first = newNode;
        count++;
    }
    // elimina el primer nodo de la lista
    void pop_front() {
        if (first == nullptr) {
            cout << "La lista ya está vacía, no se puede hacer pop_front" << endl;
            return;
        }
        Node<T>* temp = first;
        first = first->next;
        delete temp;
        count--;
    }
    
    // imprime la lista de inicio hasta al final 

    void Print() {
        Node<T>* current = first;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    // función que borra todos los nodos
    void clear() {
        while (first != nullptr) {
            pop_front();
        }
    }
    // devuelve la cantidad de elementos
    int getCount() {
        return count;
    }
};

//Funcion principal probar la lista

int main() {
    
    LinkedList<int> lista;
    
    lista.push_front(10);
    lista.push_front(20);
    lista.push_front(30);
    
    cout << "Contenido de la lista: ";
    lista.Print();
    
    lista.pop_front();
    cout << "Después de pop_front: ";
    lista.Print();
    
    lista.clear();
    return 0;
}
