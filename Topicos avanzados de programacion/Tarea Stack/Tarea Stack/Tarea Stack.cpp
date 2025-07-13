//Tarea de Ever Ledesma Anklom 
#pragma once

#include <iostream>
#include <forward_list> // Se usa una lista enlazada simple como estructura interna

using namespace std;
//recursos utilizados 
// codigos del profe 
// https://cplusplus.com/reference/forward_list/forward_list/
// https://www.geeksforgeeks.org/cpp/forward_listbegin-forward_listend-c-stl/

// Definimos una clase genérica LStack, que implementa una pila con lista enlazada
template <typename T>
class LStack
{
public:
    // Constructor: inicializa la pila con contador en cero
    LStack() : count(0) {}

    // Push: agrega un elemento a la cima de la pila
    void Push(T value)
    {
        data.push_front(value); // Inserta al inicio
        count++;                // Aumenta el contador
    }

    // Pop: elimina el elemento en la cima de la pila y lo retorna
    T Pop()
    {
        // Si la lista está vacía, no se puede eliminar
        if (data.begin() == data.end()) // antes era data.empty()
        {
            cout << "Advertencia, intentó sacar más elementos, esta LStack ya está vacía." << endl;
            return {}; // Devuelve un valor por defecto del tipo T
        }

        T value = data.front(); // Toma el primer elemento
        data.pop_front();       
        count--;               
        return value;           
    }

    // Peak: muestra el valor en la cima sin eliminarlo
    T Peak()
    {
        // Verifica si está vacía antes de acceder
        if (data.begin() == data.end()) // me daba problema con data.empty() 
        {
            cout << "Advertencia, esta LStack ya está vacía. No hay elemento para hacer Peak." << endl;
            return {};
        }

        return data.front(); // Retorna el valor en la cima
    }

    // nos dice ka cantidad que hay 
    int Count()
    {
        return count;
    }

private:
    forward_list<T> data; // Lista enlazada para almacenar los datos
    int count;            
};
int main()
{
    LStack<int> stack; // Creamos una pila de enterod

    stack.Push(10); 
    stack.Push(20); 
    stack.Push(30); 

    // Mostramos el elemento actual en la cima
    cout << "Elemento en la cima (Peak): " << stack.Peak() << endl; 
    cout << "Cantidad de elementos: " << stack.Count() << endl;     

    // Quitamos dos elementos
    cout << "Pop: " << stack.Pop() << endl;                         
    cout << "Pop: " << stack.Pop() << endl;                         

    // Verificamos el estado actual de la pila
    cout << "Elemento en la cima ahora: " << stack.Peak() << endl;  
    cout << "Cantidad de elementos: " << stack.Count() << endl;     

    stack.Pop(); 
    stack.Pop(); 

    return 0;
}
