//tarea Herencia Ever Ledesma Anklom 
#include <iostream>     
#include <cmath>       
#include <string>       
using namespace std;
//Recursos utilizados 
//codigos del profe
//consultas en internet
//https://stackoverflow.com/questions/1727881/how-to-use-the-pi-constant-in-c

// Definir la constante PI 
#ifndef M_PI
#define M_PI 3.1415
#endif

// Clase base abstracta para figuras geométricas
class Figura {
public:
    // Constructor: inicializa el nombre de la figura
    Figura(string name) : nombre(name) {
        cout << "Constructor de Figura: " << nombre << endl;
    }

    // Destructor virtual: permite eliminar correctamente objetos derivados
    virtual ~Figura() {
        cout << "Destructor de Figura: " << nombre << endl;
    }

    // Métodos abstractos que deben ser implementados por clases hijas
    virtual float CalcularArea() const = 0;      // Calcula el área de la figura
    virtual float CalcularPerimetro() const = 0; // Calcula el perímetro

    // Obtiene el nombre de la figura (solo lectura)
    const string& ObtenerNombreDeFigura() const {
        return nombre;
    }

protected:
    string nombre; // Nombre de la figura (accesible por clases derivadas)
};

// Clase para círculos (hereda de Figura)
class Circulo : public Figura {
public:
    // Constructor: recibe el radio e inicializa la base
    Circulo(float r) : Figura("Circulo"), radio(r) {
        cout << "Constructor de Circulo" << endl;
    }

    // Destructor
    ~Circulo() override {
        cout << "Destructor de Circulo" << endl;
    }

    // Calcula el área: π * radio²
    float CalcularArea() const override {
        return M_PI * radio * radio;
    }

    // Calcula la circunferencia: 2 * π * radio
    float CalcularPerimetro() const override {
        return 2 * M_PI * radio;
    }

private:
    float radio; // Radio del círculo
};

// Clase para cuadrados (hereda de Figura)
class Cuadrado : public Figura {
public:
    // Constructor: recibe el lado e inicializa la base
    Cuadrado(float lado) : Figura("Cuadrado"), lado(lado) {
        cout << "Constructor de Cuadrado" << endl;
    }

    // Destructor
    ~Cuadrado() override {
        cout << "Destructor de Cuadrado" << endl;
    }

    // Área = lado * lado
    float CalcularArea() const override {
        return lado * lado;
    }

    // Perímetro = 4 * lado
    float CalcularPerimetro() const override {
        return 4 * lado;
    }

protected:
    float lado; // Longitud del lado (protegido para herencia)
};

// Clase para figuras regulares de N lados (ej: pentágono, hexágono)
class FiguraNLados : public Figura {
public:
    // Constructor: recibe número de lados y longitud de cada lado
    FiguraNLados(int nLados, float longitud)
        : Figura("Figura de " + to_string(nLados) + " lados"), n(nLados), lado(longitud) {
        cout << "Constructor de FiguraNLados" << endl;
    }

    // Destructor
    ~FiguraNLados() override {
        cout << "Destructor de FiguraNLados" << endl;
    }

    // Fórmula del área para polígonos regulares: (n * lado * apotema)/2
    float CalcularArea() const override {
        // Apotema = distancia del centro al punto medio de un lado
        float apotema = lado / (2 * tan(M_PI / n));
        return (n * lado * apotema) / 2;
    }

    // Perímetro = número de lados * longitud del lado
    float CalcularPerimetro() const override {
        return n * lado;
    }

private:
    int n;       // Cantidad de lados
    float lado;  // Longitud de cada lado
};

// Clase para cubos (hereda de Cuadrado)
class Cubo : public Cuadrado {
public:
    // Constructor especial: inicializa como Cuadrado pero cambia el nombre
    Cubo(float lado) : Cuadrado(lado) {
        // Corrección clave: Cambiamos el nombre después de inicializar
        nombre = "Cubo";
        cout << "Constructor de Cubo" << endl;
    }

    // Destructor
    ~Cubo() override {
        cout << "Destructor de Cubo" << endl;
    }

    // Área superficial = 6 * lado² (6 caras cuadradas)
    float CalcularArea() const override {
        return 6 * lado * lado;
    }

    // "Perímetro" total = 12 aristas * longitud
    float CalcularPerimetro() const override {
        return 12 * lado;
    }

    // Volumen = lado³
    float Volumen() const {
        return lado * lado * lado;
    }

    // Superficie (sinónimo de área para el cubo)
    float Surface() const {
        return CalcularArea();
    }
};

// Clase para líneas compuestas por segmentos
class Linea : public Figura {
public:
    // Constructor: recibe arreglo de segmentos y su cantidad
    Linea(float* segmentos, int cantidad) : Figura("Linea") {
        cout << "Constructor de Linea" << endl;
        n = cantidad;
        // Reserva memoria dinámica para copiar los segmentos
        this->segmentos = new float[n];
        for (int i = 0; i < n; ++i) {
            this->segmentos[i] = segmentos[i];
        }
    }

    // Destructor: libera la memoria dinámica
    ~Linea() override {
        cout << "Destructor de Linea" << endl;
        delete[] segmentos;
    }

    // Área = 0 (una línea no tiene área)
    float CalcularArea() const override {
        return 0;
    }

    // Longitud total = suma de todos los segmentos
    float CalcularPerimetro() const override {
        float total = 0;
        for (int i = 0; i < n; ++i) {
            total += segmentos[i];
        }
        return total;
    }

private:
    float* segmentos; // Arreglo dinámico de segmentos
    int n;            // Cantidad de segmentos
};

// Función principal de prueba
int main() {
    // Prueba del círculo
    Circulo c(5);
    cout << c.ObtenerNombreDeFigura() << " -> Área: " << c.CalcularArea()
        << ", Perímetro: " << c.CalcularPerimetro() << endl;

    // Prueba del cuadrado
    Cuadrado q(4);
    cout << q.ObtenerNombreDeFigura() << " -> Área: " << q.CalcularArea()
        << ", Perímetro: " << q.CalcularPerimetro() << endl;

    // Prueba del hexágono regular (6 lados)
    FiguraNLados f(6, 3);
    cout << f.ObtenerNombreDeFigura() << " -> Área: " << f.CalcularArea()
        << ", Perímetro: " << f.CalcularPerimetro() << endl;

    // Prueba del cubo
    Cubo cubo(3);
    cout << cubo.ObtenerNombreDeFigura() << " -> Área: " << cubo.CalcularArea()
        << ", Perímetro: " << cubo.CalcularPerimetro()
        << ", Volumen: " << cubo.Volumen()
        << ", Superficie: " << cubo.Surface() << endl;

    // Prueba de línea con segmentos usando puntero a Figura
    float segmentos[] = { 2.5, 1.5, 3.0 };
    Figura* myLine = new Linea(segmentos, 3);
    cout << myLine->ObtenerNombreDeFigura() << " -> Área: " << myLine->CalcularArea()
        << ", Perímetro: " << myLine->CalcularPerimetro() << endl;

    // Importante: liberar memoria de objetos creados con new
    delete myLine;

    return 0;
}