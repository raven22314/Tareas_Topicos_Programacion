//Tarea Ever Ledesma Anklom Funcion template PrintArray
#include <iostream>
using namespace std;
//Recursos utilizados 
//https://www.geeksforgeeks.org/cpp/how-to-print-an-array-in-cpp/


// Función template para imprimir cualquier tipo de array
// Recibe el array, su tamaño e imprime cada elemento
template <typename T>
void PrintArray(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " "; // Imprime cada elemento seguido de espacio
    }

}

int main() {
    // Ejemplo con enteros
    int enteros[5] = { 10, 20, 30, 40, 50 };
    cout << "Array de enteros: ";
    PrintArray(enteros, 5); // Llamada a la función template

    // Ejemplo con decimales
    float decimales[3] = { 1.5f, 2.7f, 3.14f };
    cout << "Array de floats: ";
    PrintArray(decimales, 3);

    // Ejemplo con booleanos
    bool booleanos[4] = { true, false, true, false };
    cout << "Array de booleanos: ";
    PrintArray(booleanos, 4); // Se imprimirán como 1 y 0

    return 0;
}