//Tarea Ever LEdesma Anklom 
#include <iostream>
using namespace std;
//Recursos utilizados ;https://cplusplus.com/reference/vector/vector/
//Multiples mas incluidas las notas del profesor y algunas busquedas random por internet

// clase generica para crear un array dinamico
template <typename tipo>
class dynamic_array {
private:
    tipo* datos;       // apuntador al arreglo de datos
    int capacidad;     // capacidad total del arreglo
    int cantidad;      // cantidad de elementos actualmente en el arreglo

public:
    // constructor
    dynamic_array() {
        capacidad = 2;             // capacidad inicial pequeña
        cantidad = 0;              // no hay elementos al inicio
        datos = new tipo[capacidad]; // se reserva memoria
    }

    // destructor
    ~dynamic_array() {
        delete[] datos; // liberar la memoria cuando el objeto se destruye
    }

    // funcion para agregar un elemento al final
    void push_back(tipo valor) {
        if (cantidad == capacidad) {
            // si ya no hay espacio, duplicamos la capacidad
            int nueva_capacidad = capacidad * 2;
            tipo* nuevo_array = new tipo[nueva_capacidad];

            // copiamos los datos anteriores
            for (int i = 0; i < cantidad; i++) {
                nuevo_array[i] = datos[i];
            }

            // liberamos memoria vieja y apuntamos al nuevo arreglo
            delete[] datos;
            datos = nuevo_array;
            capacidad = nueva_capacidad;
        }

        // agregamos el nuevo elemento
        datos[cantidad] = valor;
        cantidad++;
    }

    // funcion para eliminar el ultimo elemento
    void pop_back() {
        if (cantidad > 0) {
            cantidad--; // simplemente reducimos la cantidad
        }
        // no reducimos capacidad por ahora
    }

    // funcion para reducir la capacidad al tamaño actual
    void shrink_to_fit() {
        if (capacidad != cantidad) {
            tipo* nuevo_array = new tipo[cantidad];

            for (int i = 0; i < cantidad; i++) {
                nuevo_array[i] = datos[i];
            }

            delete[] datos;
            datos = nuevo_array;
            capacidad = cantidad;
        }
    }

    // sobrecarga del operador [] para acceder como un array normal
    tipo& operator[](int indice) {
        // no hacemos comprobación de límites para mantenerlo simple
        return datos[indice];
    }

    // funcion para imprimir el arreglo (solo para pruebas)
    void imprimir() {
        for (int i = 0; i < cantidad; i++) {
            cout << datos[i] << " ";
        }
        cout << endl;
    }

    // funcion para obtener la cantidad actual
    int size() {
        return cantidad;
    }

    // funcion para obtener la capacidad actual
    int get_capacidad() {
        return capacidad;
    }
};

// funcion principal para probar la clase
int main() {
    dynamic_array<int> mi_array;

    mi_array.push_back(1984);
    mi_array.push_back(2024);
    mi_array.push_back(42);

    cout << "elemento en posicion 0: " << mi_array[0] << endl;

    cout << "elementos actuales: ";
    mi_array.imprimir();

    cout << "capacidad antes de shrink: " << mi_array.get_capacidad() << endl;

    mi_array.shrink_to_fit();

    cout << "capacidad despues de shrink: " << mi_array.get_capacidad() << endl;

    mi_array.pop_back();

    cout << "elementos despues de pop: ";
    mi_array.imprimir();

    return 0;
}
