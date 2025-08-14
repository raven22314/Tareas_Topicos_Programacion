#pragma once
#include "BinarySearchTree.h"
#include <iostream>
#include <stack> // necesario para recorridos iterativos
#include <cmath> // Required for std::log
#include "BinarySearchTree.h"
using namespace std;
// Ever Ledesma Anklom - Binary Search Tree corregido 
//recursos utilizados:https://www.geeksforgeeks.org/dsa/binary-search-tree-data-structure/
//https://www.geeksforgeeks.org/dsa/binary-search-tree-set-1-search-and-insertion/
//https://www.geeksforgeeks.org/dsa/binary-search-tree-traversal-inorder-preorder-post-order/


// Funciones inline para evitar múltiples definiciones
inline double log_base_n(double x, double base);

inline int MinimaAlturaDeArbol(int numeroDeNodos, int maximoDeHijosPorNodo);

int main()
{
    // Creamos un BST de enteros
    BinarySearchTree <int> bst;

    // Probamos inserciones (usando recursivo y no recursivo original)
    bst.AddWithAddRecursive(50);
    bst.AddWithAddRecursive(30);
    bst.AddWithAddRecursive(70);
    bst.AddWithAddRecursive(20);
    bst.AddWithAddRecursive(40);
    bst.AddWithAddRecursive(60);
    bst.AddWithAddRecursive(80);

    cout << "InOrder (recursivo):" << endl;
    bst.InOrderWithRecursive();

    // Prueba de Search (iterativa)
    cout << "Buscar 60: " << (bst.Search(60) ? "Encontrado" : "No encontrado") << endl;
    cout << "Buscar 100: " << (bst.Search(100) ? "Encontrado" : "No encontrado") << endl;

    // Prueba Post-order iterativo (usando helper interno)
    cout << "Post-order (iterativo):" << endl;
    bst.PostOrderIterative();
    cout << "Pruebas completadas, se borro el arbol antes de salir " << endl;

    // Eliminar todo el árbol antes de salir
    bst.EliminarArbol();

    return 0;

}
    

