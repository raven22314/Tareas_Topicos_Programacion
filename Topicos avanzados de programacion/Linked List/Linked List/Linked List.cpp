//Ever Ledesma Anklom 
#include <iostream>
using namespace std;
//Recursos Utilizados 
//https://cplusplus.com/reference/
//Recursos vistos en clase y asi mismo codigos del profesor

<<<<<<< HEAD
// activar 1 o desactivar 0 
#define CONTAR_COPIAS 1
=======


#define CONTAR_COPIAS 
>>>>>>> 64a5551c097ce55d17244573cf2a28475ac63520

// clase nodo que guarda un dato y un apuntador al siguiente nodo
template <typename T>
class Node {
public:
<<<<<<< HEAD
    T data;           
    Node<T>* next;    
=======
    T data;
    Node<T>* next;
>>>>>>> 64a5551c097ce55d17244573cf2a28475ac63520

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
<<<<<<< HEAD
    Node<T>* first;   
    int count;       
=======
    Node<T>* first;
    int count;
>>>>>>> 64a5551c097ce55d17244573cf2a28475ac63520

public:
    LinkedList() {
        first = nullptr;
        count = 0;
    }

<<<<<<< HEAD
    // inserta un valor al inicio de la lista
=======
    // libera todos los nodos existentes en la lista
    void clear() {
        while (first != nullptr) {
            Node<T>* temp = first;
            first = first->next;
            delete temp;
        }
        count = 0;
    }

    // Este mÃ©todo se puede usar cuando se quiere limpiar manualmente
    // TambiÃ©n lo usamos al final del programa para no dejar memoria colgada

>>>>>>> 64a5551c097ce55d17244573cf2a28475ac63520
    void push_front(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = first;
        first = newNode;
        count++;
    }

<<<<<<< HEAD
    // elimina el primer nodo de la lista
=======
>>>>>>> 64a5551c097ce55d17244573cf2a28475ac63520
    void pop_front() {
        if (first == nullptr) {
            cout << "la lista ya estÃ¡ vacÃ­a, no se puede hacer pop_front" << endl;
            return;
        }
        Node<T>* temp = first;
        first = first->next;
        delete temp;
        count--;
    }

<<<<<<< HEAD
    // imprime la lista desde el inicio hasta el final
=======
>>>>>>> 64a5551c097ce55d17244573cf2a28475ac63520
    void Print() {
        Node<T>* current = first;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

<<<<<<< HEAD
    // función que borra todos los nodos (libera memoria)
    void clear() {
        while (first != nullptr) {
            pop_front(); // elimina uno por uno
        }
    }

    // devuelve la cantidad de elementos
=======
>>>>>>> 64a5551c097ce55d17244573cf2a28475ac63520
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

<<<<<<< HEAD
// función principal para probar la lista
=======
>>>>>>> 64a5551c097ce55d17244573cf2a28475ac63520
int main() {
    LinkedList<int> lista;

    lista.push_front(10);
<<<<<<< HEAD
    lista.push_front(20); 
    lista.push_front(30); 

    cout << "contenido de la lista: ";
    lista.Print(); 

    lista.pop_front(); 

    cout << "después de pop_front: ";
    lista.Print(); 

    // 2.2: llamamos a clear() manualmente para liberar memoria y evitar memory leaks
    lista.clear();

#if CONTAR_COPIAS != 0
    cout << "copias realizadas: " << LinkedList<int>::GetCopyCounter() << endl;
#endif
=======
    lista.push_front(20);
    lista.push_front(30);

    cout << "contenido de la lista: ";
    lista.Print();
>>>>>>> 64a5551c097ce55d17244573cf2a28475ac63520

    lista.pop_front();

    cout << "despuÃ©s de pop_front: ";
    lista.Print();

#if defined(CONTAR_COPIAS)
    // mostramos cuÃ¡ntas copias se hicieron si el conteo estÃ¡ activado
    // cout << "copias realizadas en resize: " << arr.GetCopyCounter() << endl;
#endif

    // Liberamos memoria al final del programa
    lista.clear();

    return 0;
}


