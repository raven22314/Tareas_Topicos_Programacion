//Tarea Ever Ledesma Anklom 
#pragma once

#include <iostream>
using namespace std;
//Recrusos utilixados 
//https://www.geeksforgeeks.org/how-do-dynamic-arrays-work/
//Recursos compartidos por el profesor y asi mismo apuntes
//https://learn.microsoft.com/es-es/cpp/preprocessor/preprocessor-directives?view=msvc-170

//  este define activa o desactiva el conteo de copias
#define COUNT_DYNAMIC_ARRAY_COPIES 1

// clase sencilla de arreglo dinámico que crece cuando se llena
template <typename T>
class DynamicArray {
private:
    T* data;            // arreglo donde guardamos los elementos
    int size;           // cuántos elementos tiene actualmente
    int capacity;       // cuánto espacio hay disponible

#if COUNT_DYNAMIC_ARRAY_COPIES != 0
    int copyCounter;    // cuenta cuántas copias se han hecho en los resize
#endif

public:
    // constructor que inicializa con capacidad de 2 elementos
    DynamicArray() {
        capacity = 2;
        size = 0;
        data = new T[capacity];

#if COUNT_DYNAMIC_ARRAY_COPIES != 0
        copyCounter = 0;
#endif
    }

    // devuelve el número de elementos en el arreglo
    int GetSize() {
        return size;
    }

    // devuelve el valor de copyCounter si está activado
    int GetCopyCounter() {
#if COUNT_DYNAMIC_ARRAY_COPIES != 0
        return copyCounter;
#else
        return -1; // si está desactivado devolvemos -1 para indicar que no se está contando
#endif
    }

    // agrega un elemento al final del arreglo
    void Append(T value) {
        // si ya no cabe, hay que hacer resize
        if (size == capacity) {
            // duplicamos la capacidad
            int newCapacity = capacity * 2;
            T* newData = new T[newCapacity];

            // copiamos los elementos al nuevo arreglo
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];

#if COUNT_DYNAMIC_ARRAY_COPIES != 0
                copyCounter++; // cada que copiamos un valor, aumentamos el contador
#endif
            }

            // borramos el arreglo viejo y actualizamos puntero y capacidad
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }

        // agregamos el nuevo elemento
        data[size] = value;
        size++;
    }

    // imprime los elementos del arreglo
    void Print() {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

// ejemplo de uso de la clase con conteo de copias activado
int main() {
    DynamicArray<int> arr;

    // insertamos varios elementos para forzar que haya resize y se vean las copias
    for (int i = 1; i <= 10; i++) {
        arr.Append(i);
    }

    // imprimimos el arreglo
    cout << "contenido del arreglo: ";
    arr.Print();

    // mostramos cuántas copias se hicieron si el conteo está activado
    cout << "copias realizadas en resize: " << arr.GetCopyCounter() << endl;

    return 0;
}
