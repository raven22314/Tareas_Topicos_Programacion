#include <iostream>
using namespace std;
//Ever Ledesma Anklom
//recursos utilizados , los vistos en clase
//codigo que compartio el profesor
//https://www.w3schools.com/cpp/cpp_structs.asp
//https://refactoring.guru/es/design-patterns/builder/cpp/example

// definimos una estructura llamada rect
struct rect {
	// coordenadas donde empieza el rectC!ngulo
	float x;
	float y;

	// alto y ancho del rectC!ngulo
	float alto;
	float ancho;

	// constructor por defecto, pone todo en 0
	rect() {
		x = 0;
		y = 0;
		alto = 0;
		ancho = 0;
	}

	// constructor que recibe todos los valores
	rect(float x_, float y_, float alto_, float ancho_) {
		x = x_;
		y = y_;
		alto = alto_;
		ancho = ancho_;
	}

	// constructor que recibe solo alto y ancho, y pone x y y en 0
	rect(float alto_, float ancho_) {
		x = 0;
		y = 0;
		alto = alto_;
		ancho = ancho_;
	}
};

// esta funcion recibe un rectangulo por referencia y saca sus coordenadas finales
bool ImprimirRect(const rect& r, float& finx, float& finy) {
	// si algun valor es menor a 0, regresa false
	if (r.x < 0 || r.y < 0 || r.alto < 0 || r.ancho < 0) {
		return false;
	}

	// imprimimos donde empieza
	cout << "coordenada inicial x: " << r.x << endl;
	cout << "coordenada inicial y: " << r.y << endl;

	// calculamos donde termina
	finx = r.x + r.ancho;
	finy = r.y + r.alto;

	// imprimimos donde termina
	cout << "coordenada final x: " << finx << endl;
	cout << "coordenada final y: " << finy << endl;

	return true;
}

// funcion que revisa si dos rectangulos se traslapan
bool checkoverlap(const rect& a, const rect& b) {
	// si uno esta completamente a la derecha o izquierda del otro
	if (a.x + a.ancho <= b.x || b.x + b.ancho <= a.x) {
		return false;
	}

	// si uno esta completamente arriba o abajo del otro
	if (a.y + a.alto <= b.y || b.y + b.alto <= a.y) {
		return false;
	}

	// si no se cumple lo anterior, entonces no se traslapan
	return true;
}

int main() {
	// creamos algunos rectangulos como los que pide que pongamos  del ejemplo
	rect r1(0, 0, 5, 5);
	rect r2(6, 6, 5, 5);
	rect r3(2, 2, 2, 2);
	rect r4(1, 1, 7, 2);

	// mostramos informacion del primer rectangulo
	float fx, fy;
	if (!ImprimirRect(r1, fx, fy)) {
		cout << "uno o mC!s valores son negativos" << endl;
	}

	// revisamos si se traslapan
	cout << "r1 y r2 se traslapan? " << (checkoverlap(r1, r2) ? "sC-" : "no") << endl;
	cout << "r1 y r3 se traslapan? " << (checkoverlap(r1, r3) ? "sC-" : "no") << endl;
	cout << "r1 y r4 se traslapan? " << (checkoverlap(r1, r4) ? "sC-" : "no") << endl;

	return 0;
}
