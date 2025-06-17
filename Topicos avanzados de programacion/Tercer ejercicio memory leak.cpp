#include <iostream>

using namespace std;
//Ever ledesma Anklom 

int main() {
    // Crear puntero a float y asignar nullptr
    float* punteroFlotante = nullptr;

    // Pedir memoria dinámica y asignar valor 7.77
    punteroFlotante = new float(7.77);
    

    // Declarar variable float con valor 6.66
    float variableFlotante = 6.66;

    // Cambiar puntero para que apunte a variableFlotante (esto causa memory leak)
    punteroFlotante = &variableFlotante;

    // Avisar sobre el memory leak 
    cout << "Cuidado, acabas de causar un memory leak!" << endl;

    // Explicación  de qué es un memory leak y cómo evitarlo
    cout << "Un memory leak ocurre cuando se pierde la referencia a la memoria "
            "dinámica asignada y nunca se libera. Para evitarlo, siempre usa 'delete' "
            "antes de cambiar la dirección de un puntero que apunta a memoria dinámica."
         << endl;

    // Pedir memoria dinámica otra vez y darle valor 1984
    punteroFlotante = new float(1984);
    

    // Crear otro puntero que apunta a la misma dirección que punteroFlotante
    float* nuevoPunteroFlotante = punteroFlotante;

    // Liberar memoria usando punteroFlotante y asignar nullptr para evitar punteros colgantes
    delete punteroFlotante;
    punteroFlotante = nullptr;

    // Comprobar si punteroFlotante es nullptr y avisar
    if (punteroFlotante == nullptr) {
        cout << "El punteroFlotante es igual a nullptr." << endl;
    }

    // Comprobar si punteroFlotante es NULL y avisar
    if (punteroFlotante == NULL) {
        cout << "El punteroFlotante es igual a NULL." << endl;
    }

    // Verificar si nuevoPunteroFlotante apunta a memoria liberada y avisar del peligro
    if (nuevoPunteroFlotante != nullptr && nuevoPunteroFlotante != NULL) {
        cout << "El nuevoPunteroFlotante no es nullptr ni NULL. Ten cuidado al usarlo "
                "porque la memoria a la que apunta ya fue liberada."
             << endl;
    }

    return 0;
}


