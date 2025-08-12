#pragma once

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
    };
