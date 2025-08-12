#pragma once
#include"BinarySearchTbuenoCreo.cpp "
#include <iostream>
#include <stack> // necesario para recorridos iterativos
#include <cmath> // Required for std::log
using namespace std;



// Funciones inline para evitar múltiples definiciones
inline double log_base_n(double x, double base);

inline int MinimaAlturaDeArbol(int numeroDeNodos, int maximoDeHijosPorNodo);

template <typename T>
class BinarySearchTree
{
    template <typename T>
    class TreeNode
    {
    public:
        TreeNode()
        {
            parent = leftChild = rightChild = nullptr;
            data = {};
        }

        TreeNode(T data)
        {
            parent = leftChild = rightChild = nullptr;
            // this se refiere a exactamente el objeto que est� mandando a llamar la funci�n. 
            this->data = data;
        }

        T data;
        // el padre de este nodo dentro del �rbol. 
        // En otras palabras, this == parent.leftChild || this == parent.rightChild
        TreeNode<T>* parent;

        // vector<TreeNode*> children; // si quisi�ramos que tuviera la posibilidad de tener m�s de dos hijos cada nodo.
        TreeNode<T>* leftChild;
        TreeNode<T>* rightChild;
    }; 
    int main()
    {
        // Creamos un BST de enteros
        BinarySearchTree<int> bst;

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

        cout << "Pruebas completadas." << endl;
        return 0;
    }
    };
