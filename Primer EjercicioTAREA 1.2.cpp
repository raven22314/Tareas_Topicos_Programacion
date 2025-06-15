#include <iostream>
using namespace std;
//tarea Ever Ledesma Anklom 
//Recursos utilizados:https://www.w3schools.com/cpp/cpp_arrays.asp
//https://learn.microsoft.com/es-es/cpp/cpp/bool-cpp?view=msvc-170
// youtube.com



// esta función recibe un array de booleanos y su tamaño
// pone false en las posiciones pares y true en las impares
void ModificarBooleanos(bool arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            arr[i] = false; // si el índice es par, pone false
        } else {
            arr[i] = true;  // si el índice es impar, pone true
        }
    }
}

// esta es una función con el mismo nombre pero para arrays de enteros
// cambia cada número por su valor % 2 (0 si es par, 1 si es impar)
// usa punteros en lugar de corchetes para acceder al array
void ModificarBooleanos(int arr[], int size) {
    int* punteroAux = arr; // puntero auxiliar que empieza al inicio del array

    for (int i = 0; i < size; i++) {
        *punteroAux = *punteroAux % 2; // cambia el valor al residuo módulo 2
        cout << "dirección: " << punteroAux << " - valor: " << *punteroAux << endl; // imprime dirección y valor
        punteroAux++; // mueve el puntero a la siguiente posición
    }
}

int main() {
    // se crea un array de 5 booleanos
    bool MiArrayBool[5];

    // se llama a la función que modifica los valores del array de booleanos
    ModificarBooleanos(MiArrayBool, 5);

    // se imprimen los valores del array de booleanos
    cout << "array de booleanos:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "índice " << i << ": " << (MiArrayBool[i] ? "true" : "false") << endl;
    }

    // se crea un array de 10 enteros del 0 al 9
    int MiArrayEnteros[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // se llama a la función que modifica los enteros y muestra sus direcciones
    cout << "\narray de enteros después del %2 y direcciones de memoria:" << endl;
    ModificarBooleanos(MiArrayEnteros, 10);

    return 0; 
}
