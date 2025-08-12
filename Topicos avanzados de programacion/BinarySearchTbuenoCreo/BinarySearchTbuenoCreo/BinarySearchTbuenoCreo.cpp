#pragma once
#include "BinarySearchTree.h"
#include <iostream>
#include <stack> // necesario para recorridos iterativos
#include <cmath> // Required for std::log
using namespace std;
// Ever Ledesma Anklom - Binary Search Tree corregido 
//recursos utilizados:https://www.geeksforgeeks.org/dsa/binary-search-tree-data-structure/
//https://www.geeksforgeeks.org/dsa/binary-search-tree-set-1-search-and-insertion/
//https://www.geeksforgeeks.org/dsa/binary-search-tree-traversal-inorder-preorder-post-order/

// Funciones inline para evitar m�ltiples definiciones
inline double log_base_n(double x, double base)
{
    return std::log(x) / std::log(base);
}

inline int MinimaAlturaDeArbol(int numeroDeNodos, int maximoDeHijosPorNodo)
{
    int maximoDeHijosMenos1PorNumeroDeNodosMasUno = ((maximoDeHijosPorNodo - 1) * numeroDeNodos + 1);
    // Conversi�n segura con static_cast para evitar p�rdida de datos
    int altura = static_cast<int>(ceil(log_base_n(maximoDeHijosMenos1PorNumeroDeNodosMasUno, maximoDeHijosPorNodo))) - 1;
    return altura;
}

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

public:
    BinarySearchTree()
    {
        root = nullptr;
        count = 0;
    }

    void AddWithAddRecursive(T value)
    {
        // primero checamos si root es nullptr. 
        if (root == nullptr)
        {
            // si s� es nullptr, quiere decir que value es el primer valor en entrar, y por tanto se va a 
            // convertir en el nodo root.
            root = new TreeNode<T>(value);
            count++;
            return; // nos salimos de la funci�n.
        }

        TreeNode<T>* currentNode = root;

        AddRecursive(value, currentNode);
    }

    void InsertarNode(TreeNode<T>* currentNode, bool isLeftChild, T value)
    {
        TreeNode<T>* newNode = new TreeNode<T>(value);
        newNode->parent = currentNode;
        if (isLeftChild)
            currentNode->leftChild = newNode;
        else
            currentNode->rightChild = newNode;
        count++;

    }

    void AddRecursive(T value, TreeNode<T>* currentNode)
    {

        // si value es mayor que el data de currentNode
        if (value > currentNode->data)
        {
            // entonces nos vamos a su derecha
            // checamos si ese hijo de la derecha es nullptr.
            if (currentNode->rightChild == nullptr)
            {
                // si s� es nullptr, entonces ahora value va a ser ese hijo.
                InsertarNode(currentNode, false, value);
                return;
            }
            else
            {
                // aqu� hacemos la recursi�n
                return AddRecursive(value, currentNode->rightChild);
            }
        }
        else if (value < currentNode->data) // TODO: aqu� hay una trampa que veremos pronto.
        {
            // entonces nos vamos a su izquierda.
            // checamos si ese hijo de la izquierda es nullptr.
            if (currentNode->leftChild == nullptr)
            {
                // si s� es nullptr, entonces ahora value va a ser ese hijo.
                InsertarNode(currentNode, true, value);
                return;
            }
            else
            {
                // aqu� hacemos la recursi�n
                return AddRecursive(value, currentNode->leftChild);
            }
        }

    }

    void Add(T value)
    {
        // primero checamos si root es nullptr. 
        if (root == nullptr)
        {
            // si s� es nullptr, quiere decir que value es el primer valor en entrar, y por tanto se va a 
            // convertir en el nodo root.
            root = new TreeNode<T>(value);
            count++;
            return; // nos salimos de la funci�n.
        }

        TreeNode<T>* currentNode = root;

        // necesitamos un ciclo que dure hasta que lleguemos a un nodo nullptr
        while (currentNode != nullptr) // mientras que nuestro nodo actual siga siendo v�lido, continua el ciclo.
        {
            // el ciclo consiste en el proceso de navegar a trav�s de hijos izquierdos y derechos

            // si value es mayor que el data de currentNode
            if (value > currentNode->data)
            {
                // entonces nos vamos a su derecha
                // checamos si ese hijo de la derecha es nullptr.
                if (currentNode->rightChild == nullptr)
                {
                    // si s� es nullptr, entonces ahora value va a ser ese hijo.
                    InsertarNode(currentNode, false, value);
                    return;
                }
                else
                {
                    currentNode = currentNode->rightChild;
                }
            }
            else if (value < currentNode->data) // TODO: aqu� hay una trampa que veremos pronto.
            {
                // entonces nos vamos a su izquierda.
                // checamos si ese hijo de la izquierda es nullptr.
                if (currentNode->leftChild == nullptr)
                {
                    // si s� es nullptr, entonces ahora value va a ser ese hijo.
                    InsertarNode(currentNode, true, value);
                    return;
                }
                else
                {
                    currentNode = currentNode->leftChild;
                }
            }
            else
            {
				return; // si value es igual a currentNode->data, entonces no hacemos nada
            }
        }

    }

    void InOrderWithRecursive()
    {
        InOrderRecursive(root);
    }

    int MinimaAltura()
    {
        // le dice que tiene N nodos, y que es un �rbol de base 2 (porque es binario en este caso).
        return MinimaAlturaDeArbol(count, 2);
    }

    // Es el nodo ra�z desde el cual el �rbol es capaz de llegar a cualquier otro nodo en el �rbol.
    TreeNode<T>* root;

    // cu�ntos nodos en total tiene el �rbol.
    int count;

    // cu�ntos niveles de profundidad tiene el �rbol.
    // int depth;

    // Retornamos true si existe (implementaci�n iterativa: SEARCH)
    bool Search(T value)
    {
        // Implementaci�n iterativa de b�squeda 
        TreeNode<T>* currentNode = root;
        while (currentNode != nullptr)
        {
            if (currentNode->data == value)
                return true;
            if (value < currentNode->data)
                currentNode = currentNode->leftChild;
            else
                currentNode = currentNode->rightChild;
        }
        return false;
    }

    void Delete(T value)
    {
        // Corroboramos que existe un nodo con el value dado.
        TreeNode<T>* nodeToDelete = SearchRecursive(root, value);

        if (nodeToDelete == nullptr)
        {
            cout << "no existe el valor value en este �rbol." << endl;
            return;
        }

        // si s� existe, entonces checamos cu�l de los 3 casos es.
        // caso 1: el nodo no tiene hijos
        if (nodeToDelete->leftChild == nullptr &&
            nodeToDelete->rightChild == nullptr)
        {
            // entonces no tiene hijos

            // haces que el puntero a hijo de su padre que apunta a este nodo sea null
            // checamos si nodeToDelete es hijo izquierdo o derecho de su pap�.
            if (nodeToDelete->parent->leftChild == nodeToDelete) // soy tu hijo izquierdo?
            {
                nodeToDelete->parent->leftChild = nullptr;
            }
            else
            {
                // si no, entonces somos el hijo derecho
                nodeToDelete->parent->rightChild = nullptr;
            }

            // y luego borras este nodo
            count--;
            delete nodeToDelete;
            return;
        }
        // caso 2: tiene un solo hijo.
        if (nodeToDelete->leftChild == nullptr && nodeToDelete->rightChild != nullptr)
        {
            // tiene hijo derecho pero no izquierdo
            // haces que dicho hijo tome el lugar de X en el �rbol 

            // en pocas palabras: Nieto se conecta al abuelo, y el abuelo al nieto, y luego se borra el pap�.
            // nodeToDelete le dice a su pap� que ahora que ahora �l debe apuntar a su nieto.
            // necesitamos saber si somos hijo izquierdo o derecho del abuelo, para poder reasignar el puntero.
            if (nodeToDelete->parent->leftChild == nodeToDelete) // soy tu hijo izquierdo?
            {
                nodeToDelete->parent->leftChild = nodeToDelete->rightChild;
            }
            else
            {
                // si no, entonces somos el hijo derecho
                nodeToDelete->parent->rightChild = nodeToDelete->rightChild;
            }

            // y el nieto, ahora su parent va a ser su abuelo.
            nodeToDelete->rightChild->parent = nodeToDelete->parent;
            delete nodeToDelete;
            count--;
            return;
        }
        else if (nodeToDelete->leftChild != nullptr && nodeToDelete->rightChild == nullptr)
        {
            // tiene hijo izquierdo pero no derecho.
            // haces que dicho hijo tome el lugar de X en el �rbol 

            // en pocas palabras: Nieto se conecta al abuelo, y el abuelo al nieto, y luego se borra el pap�.
            // nodeToDelete le dice a su pap� que ahora que ahora �l debe apuntar a su nieto.
            // necesitamos saber si somos hijo izquierdo o derecho del abuelo, para poder reasignar el puntero.
            if (nodeToDelete->parent->leftChild == nodeToDelete) // soy tu hijo izquierdo?
            {
                nodeToDelete->parent->leftChild = nodeToDelete->leftChild;
            }
            else
            {
                // si no, entonces somos el hijo derecho
                nodeToDelete->parent->rightChild = nodeToDelete->leftChild;
            }

            // y el nieto, ahora su parent va a ser su abuelo.
            nodeToDelete->leftChild->parent = nodeToDelete->parent;
            // y luego borras a X
            delete nodeToDelete;
            count--;
            return;
        }

        // aqu� ya sabemos que tiene los dos hijos porque si no no habr�a llegado a esta l�nea de c�digo.
        // entonces es el caso 3:

        // encontramos al sucesor de nodeToDelete
        TreeNode<T>* successorNode = Successor(nodeToDelete);  // NOTA, nunca podr�a ser nulo, porque nodeToDelete tiene sus dos hijos
        // a donde nodeToDelete apuntaba con la izquierda, ahora el sucesor apunta con su izquierda y viceversa.
        successorNode->leftChild = nodeToDelete->leftChild;
        nodeToDelete->leftChild->parent = successorNode;

        // el hijo derecho del sucesor ahora es hijo del pap� del sucesor y viceversa.
        // pero necesitamos saber si successorNode es hijo izquierdo o derecho del abuelo.
        if (successorNode->parent->leftChild == successorNode) // soy tu hijo izquierdo?
        {
            successorNode->parent->leftChild = successorNode->rightChild;
        }
        else
        {
            // si no, entonces somos el hijo derecho
            successorNode->parent->rightChild = successorNode->rightChild;
        }
        // conectamos el hijo derecho del sucesor con su abuelo.
        // coreccion: validamos que successorNode->rightChild no sea nullptr antes de acceder a su campo 'parent'.
        // Esto evita un error de segmentaci�n si el sucesor no tiene hijo derecho.
        if (successorNode->rightChild != nullptr)
            successorNode->rightChild->parent = successorNode->parent;

        // a donde apuntaba nodeToDelete con la derecha, ahora el sucesor va a apuntar con su derecha y viceversa.
        successorNode->rightChild = nodeToDelete->rightChild;
        nodeToDelete->rightChild->parent = successorNode;

        // nos falta que el sucesor sepa qui�n es su pap�, y viceversa
        successorNode->parent = nodeToDelete->parent;
        // aqu� S� necesitamos saber si nodeToDelete es su hijo derecho o izquierdo
        if (nodeToDelete->parent->leftChild == nodeToDelete) // soy tu hijo izquierdo?
        {
            nodeToDelete->parent->leftChild = successorNode;
        }
        else
        {
            // si no, entonces somos el hijo derecho
            nodeToDelete->parent->rightChild = successorNode;
        }

        count--;
        // y borramos el nodo.
        delete nodeToDelete;
    }

public:
    void PostOrderIterative()
    {
        PostOrderIterative_InternalPrint();
    }

private:
    // Iterative post-order traversal helper that returns values in post-order via stack
    void PostOrderIterative_InternalPrint()
    {
        if (root == nullptr) return;

        stack<TreeNode<T>*> s1, s2;
        s1.push(root);
        while (!s1.empty())
        {
            TreeNode<T>* n = s1.top(); s1.pop();
            s2.push(n);
            if (n->leftChild) s1.push(n->leftChild);
            if (n->rightChild) s1.push(n->rightChild);
        }
        while (!s2.empty())
        {
            cout << s2.top()->data << " ";
            s2.pop();
        }
        cout << endl;
    }

private:
    TreeNode<T>* TreeMaximum()
    {
        // empezamos en la ra�z y le pedimos el m�ximo desde ah�.
        return Maximum(root);
    }

    // Nos da el m�ximo a partir de node como ra�z.
    TreeNode<T>* Maximum(TreeNode<T>* node)
    {
        // empezamos en node y 
        TreeNode<T>* maximum = node;
        // nos vamos todo a la derecha hasta que el hijo derecha sea nullptr.
        while (maximum->rightChild != nullptr)
            maximum = maximum->rightChild;

        return maximum;
    }

    // el m�nimo valor T en todo el �rbol.
    TreeNode<T>* TreeMinimum()
    {
        // empezamos en la ra�z y le pedimos el m�nimo desde ah�
        return Minimum(root);
    }

    // Nos da el m�nimo a partir de node como ra�z.
    TreeNode<T>* Minimum(TreeNode<T>* node)
    {
        // empezamos en node y 
        TreeNode<T>* minimum = node;
        // nos vamos todo a la izquierda hasta que el hijo izquierdo sea nullptr.
        while (minimum->leftChild != nullptr)
            minimum = minimum->leftChild;

        return minimum;
    }

    TreeNode<T>* MinimumWithRecursive()
    {
        // empezamos en la ra�z y hacemos recursi�n.
        return MinimumRecursive(root);
    }

    TreeNode<T>* MinimumRecursive(TreeNode<T>* currentNode)
    {
        if (currentNode->leftChild == nullptr)
            return currentNode;
        // else
        return MinimumRecursive(currentNode->leftChild);
    }

    TreeNode<T>* Successor(TreeNode<T>* node)
    {
        if (node->rightChild != nullptr)
            return Minimum(node->rightChild); // Minimum se debe mandar a llamar desde la derecha del node que se recibi� como par�metro.

        // si no, entonces 
        // tomamos el padre de node, y lo guardamos en una variable
        TreeNode<T>* ancestor = node->parent;
        // Mientras que no llegue a null y siga siendo hijo derecho de alguien, entonces se seguir�
        // subiendo en los parents.
        while (ancestor != nullptr && node == ancestor->rightChild)
        {
            // node se vuelve su pap�
            node = ancestor;
            // y el pap� se vuelve su pap�
            ancestor = node->parent;
        }
        return ancestor;
    }

    // lo mismo que Successor, pero invertimos Right por Left, y Minimum por maximum.
    TreeNode<T>* Predecessor(TreeNode<T>* node)
    {
        if (node->leftChild != nullptr)
            return Maximum(node->leftChild); // Maximum se debe mandar a llamar desde la izquierda del node que se recibi� como par�metro.

        // si no, entonces 
        // tomamos el padre de node, y lo guardamos en una variable
        TreeNode<T>* ancestor = node->parent;
        // Mientras que no llegue a null y siga siendo hijo izquierdo de alguien, entonces se seguir�
        // subiendo en los parents.
        while (ancestor != nullptr && node == ancestor->leftChild)
        {
            // node se vuelve su pap�
            node = ancestor;
            // y el pap� se vuelve su pap�
            ancestor = node->parent;
        }
        return ancestor;
    }

    TreeNode<T>* SearchRecursive(TreeNode<T>* currentNode, T value)
    {
        if (currentNode == nullptr)
            return nullptr;
        if (currentNode->data == value)
            return currentNode;
        // si el valor que est�s buscando (value) es menor que el de este nodo, vete al hijo izquierdo
        if (value < currentNode->data)
        {
            return SearchRecursive(currentNode->leftChild, value);
        }

        // else
        return SearchRecursive(currentNode->rightChild, value);
    }

    void InOrderRecursive(TreeNode<T>* node)
    {
        if (node != nullptr)
        {
            // Mandamos recursivamente a izquierda
            InOrderRecursive(node->leftChild);
            // Luego se visita (en este caso, se imprime su valor)
            cout << node->data << endl;
            // Mandamos recursivamente a derecha
            InOrderRecursive(node->rightChild);
        }
    }

    void PreOrderRecursive(TreeNode<T>* node)
    {
        if (node != nullptr)
        {
            // Luego se visita (en este caso, se imprime su valor)
            cout << node->data << endl;
            // Mandamos recursivamente a izquierda
            PreOrderRecursive(node->leftChild);
            // Mandamos recursivamente a derecha
            PreOrderRecursive(node->rightChild);
        }
    }

    void PostOrderRecursive(TreeNode<T>* node)
    {
        if (node != nullptr)
        {
            // Mandamos recursivamente a izquierda
            PostOrderRecursive(node->leftChild);
            // Mandamos recursivamente a derecha
            PostOrderRecursive(node->rightChild);
            // Luego se visita (en este caso, se imprime su valor)
            cout << node->data << endl;
        }
    }

};


