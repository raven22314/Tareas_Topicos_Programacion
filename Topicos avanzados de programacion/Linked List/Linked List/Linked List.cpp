//Ever Ledesma Anklom 
#include <iostream>
using namespace std;
//Recursos Utilizados 
//https://cplusplus.com/reference/
//Recursos vistos en clase y asi mismo codigos del profesor
//Leer y leer lo que me pedia corregir el profe xd
//Realmente el rpofesor leera esto?
//duermanme como a los perritos 

// Clase DynamicArray con conteo de las copias 
template <typename T>
class DynamicArray {
private:
    T* data;            // Almacena los elementos
    int size;           // Elementos actuales
    int capacity;       // Espacio total disponible

#if CONTAR_COPIAS != 0

    int copyCounter;    
#endif

public:
    DynamicArray() {
        capacity = 2;
        size = 0;
        data = new T[capacity];

#if CONTAR_COPIAS != 0

        copyCounter = 0;  // Inicializa solo si está activado
#endif
    }

    // Destructor
    ~DynamicArray() {
        delete[] data;
    }

    // Devuelve tamaño actual
    int GetSize() {
        return size;
    }

    // Devuelve contador de copias 
    int GetCopyCounter() {
#if CONTAR_COPIAS != 0

        return copyCounter;
#else
        return -1;
#endif
    }

    // Agrega elemento al final
    void Append(T value) {
        if (size == capacity) {
            int newCapacity = capacity * 2;
            T* newData = new T[newCapacity];

            // Copia elementos incrementando contador si está activado
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
#if CONTAR_COPIAS != 0

                copyCounter++;
#endif
            }

            delete[] data;
            data = newData;
            capacity = newCapacity;
        }

        data[size] = value;
        size++;
    }

    // Imprime elementos
    void Print() {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

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

// Clase lista ligada
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

    void push_front(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = first;
        first = newNode;
        count++;
    }

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

    void Print() {
        Node<T>* current = first;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void clear() {
        while (first != nullptr) {
            pop_front();
        }
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
    
    cout << "Contenido de la lista: ";
    lista.Print();
    
    lista.pop_front();
    cout << "Después de pop_front: ";
    lista.Print();
    
    lista.clear();


    return 0;
}
