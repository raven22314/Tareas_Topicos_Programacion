
#pragma once

#include <iostream>
#include <stack> // necesario para recorridos iterativos
using namespace std;
// Ever Ledesma Anklom - Binary Search Tree corregido 
#include <cmath> // Required for std::log
//recursos utilizados:https://www.geeksforgeeks.org/dsa/binary-search-tree-data-structure/
//https://www.geeksforgeeks.org/dsa/binary-search-tree-set-1-search-and-insertion/
//https://www.geeksforgeeks.org/dsa/binary-search-tree-traversal-inorder-preorder-post-order/


double log_base_n(double x, double base);


int MinimaAlturaDeArbol(int numeroDeNodos, int maximoDeHijosPorNodo);

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
			// this se refiere a exactamente el objeto que está mandando a llamar la función. 
			this->data = data;
		}

		T data;
		// el padre de este nodo dentro del árbol. 
		// En otras palabras, this == parent.leftChild || this == parent.rightChild
		TreeNode<T>* parent;

		// vector<TreeNode*> children; // si quisiéramos que tuviera la posibilidad de tener más de dos hijos cada nodo.
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
			// si sí es nullptr, quiere decir que value es el primer valor en entrar, y por tanto se va a 
			// convertir en el nodo root.
			root = new TreeNode<T>(value);
			count++;
			return; // nos salimos de la función.
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
				// si sí es nullptr, entonces ahora value va a ser ese hijo.
				InsertarNode(currentNode, false, value);
				return;
			}
			else
			{
				// aquí hacemos la recursión
				return AddRecursive(value, currentNode->rightChild);
			}
		}
		else if (value < currentNode->data) // TODO: aquí hay una trampa que veremos pronto.
		{
			// entonces nos vamos a su izquierda.
			// checamos si ese hijo de la izquierda es nullptr.
			if (currentNode->leftChild == nullptr)
			{
				// si sí es nullptr, entonces ahora value va a ser ese hijo.
				InsertarNode(currentNode, true, value);
				return;
			}
			else
			{
				// aquí hacemos la recursión
				return AddRecursive(value, currentNode->leftChild);
			}
		}

	}

	void Add(T value)
	{
		// primero checamos si root es nullptr. 
		if (root == nullptr)
		{
			// si sí es nullptr, quiere decir que value es el primer valor en entrar, y por tanto se va a 
			// convertir en el nodo root.
			root = new TreeNode<T>(value);
			count++;
			return; // nos salimos de la función.
		}

		TreeNode<T>* currentNode = root;

		// necesitamos un ciclo que dure hasta que lleguemos a un nodo nullptr
		while (currentNode != nullptr) // mientras que nuestro nodo actual siga siendo válido, continua el ciclo.
		{
			// el ciclo consiste en el proceso de navegar a través de hijos izquierdos y derechos

			// si value es mayor que el data de currentNode
			if (value > currentNode->data)
			{
				// entonces nos vamos a su derecha
				// checamos si ese hijo de la derecha es nullptr.
				if (currentNode->rightChild == nullptr)
				{
					// si sí es nullptr, entonces ahora value va a ser ese hijo.
					InsertarNode(currentNode, false, value);
					return;
				}
				else
				{
					currentNode = currentNode->rightChild;
				}
			}
			else if (value < currentNode->data) // TODO: aquí hay una trampa que veremos pronto.
			{
				// entonces nos vamos a su izquierda.
				// checamos si ese hijo de la izquierda es nullptr.
				if (currentNode->leftChild == nullptr)
				{
					// si sí es nullptr, entonces ahora value va a ser ese hijo.
					InsertarNode(currentNode, true, value);
					return;
				}
				else
				{
					currentNode = currentNode->leftChild;
				}
			}
		}




	}

	void InOrderWithRecursive()
	{
		InOrderRecursive(root);
	}


	int MinimaAltura()
	{
		// le dice que tiene N nodos, y que es un árbol de base 2 (porque es binario en este caso).
		return MinimaAlturaDeArbol(count, 2);
	}



	// Es el nodo raíz desde el cual el árbol es capaz de llegar a cualquier otro nodo en el árbol.
	TreeNode<T>* root;

	// cuántos nodos en total tiene el árbol.
	int count;

	// cuántos niveles de profundidad tiene el árbol.
	// int depth;

	// Retornamos true si existe (implementación iterativa: SEARCH)
	bool Search(T value)
	{
		// Implementación iterativa de búsqueda 
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
			cout << "no existe el valor value en este árbol." << endl;
			return;
		}

		// si sí existe, entonces checamos cuál de los 3 casos es.
		// caso 1: el nodo no tiene hijos
		if (nodeToDelete->leftChild == nullptr &&
			nodeToDelete->rightChild == nullptr)
		{
			// entonces no tiene hijos

			// haces que el puntero a hijo de su padre que apunta a este nodo sea null
			// checamos si nodeToDelete es hijo izquierdo o derecho de su papá.
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
			// haces que dicho hijo tome el lugar de X en el árbol 

			// en pocas palabras: Nieto se conecta al abuelo, y el abuelo al nieto, y luego se borra el papá.
			// nodeToDelete le dice a su papá que ahora que ahora él debe apuntar a su nieto.
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
			// haces que dicho hijo tome el lugar de X en el árbol 

			// en pocas palabras: Nieto se conecta al abuelo, y el abuelo al nieto, y luego se borra el papá.
			// nodeToDelete le dice a su papá que ahora que ahora él debe apuntar a su nieto.
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

		// aquí ya sabemos que tiene los dos hijos porque si no no habría llegado a esta línea de código.
		// entonces es el caso 3:

		// encontramos al sucesor de nodeToDelete
		TreeNode<T>* successorNode = Successor(nodeToDelete);  // NOTA, nunca podría ser nulo, porque nodeToDelete tiene sus dos hijos
		// a donde nodeToDelete apuntaba con la izquierda, ahora el sucesor apunta con su izquierda y viceversa.
		successorNode->leftChild = nodeToDelete->leftChild;
		nodeToDelete->leftChild->parent = successorNode;

		// el hijo derecho del sucesor ahora es hijo del papá del sucesor y viceversa.
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
		// Esto evita un error de segmentación si el sucesor no tiene hijo derecho.
		if (successorNode->rightChild != nullptr)
			successorNode->rightChild->parent = successorNode->parent;

		// a donde apuntaba nodeToDelete con la derecha, ahora el sucesor va a apuntar con su derecha y viceversa.
		successorNode->rightChild = nodeToDelete->rightChild;
		nodeToDelete->rightChild->parent = successorNode;

		// nos falta que el sucesor sepa quién es su papá, y viceversa
		successorNode->parent = nodeToDelete->parent;
		// aquí SÍ necesitamos saber si nodeToDelete es su hijo derecho o izquierdo
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


private:
	TreeNode<T>* TreeMaximum()
	{
		// empezamos en la raíz y le pedimos el máximo desde ahí.
		return Maximum(root);
	}

	// Nos da el máximo a partir de node como raíz.
	TreeNode<T>* Maximum(TreeNode<T>* node)
	{
		// empezamos en node y 
		TreeNode<T>* maximum = node;
		// nos vamos todo a la derecha hasta que el hijo derecha sea nullptr.
		while (maximum->rightChild != nullptr)
			maximum = maximum->rightChild;

		return maximum;
	}


	// el mínimo valor T en todo el árbol.
	TreeNode<T>* TreeMinimum()
	{
		// empezamos en la raíz y le pedimos el mínimo desde ahí
		return Minimum(root);
	}

	// Nos da el mínimo a partir de node como raíz.
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
		// empezamos en la raíz y hacemos recursión.
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
			return Minimum(node->rightChild); // Minimum se debe mandar a llamar desde la derecha del node que se recibió como parámetro.

		// si no, entonces 
		// tomamos el padre de node, y lo guardamos en una variable
		TreeNode<T>* ancestor = node->parent;
		// Mientras que no llegue a null y siga siendo hijo derecho de alguien, entonces se seguirá
		// subiendo en los parents.
		while (ancestor != nullptr && node == ancestor->rightChild)
		{
			// node se vuelve su papá
			node = ancestor;
			// y el papá se vuelve su papá
			ancestor = node->parent;
		}
		return ancestor;
	}

	// lo mismo que Successor, pero invertimos Right por Left, y Minimum por maximum.
	TreeNode<T>* Predecessor(TreeNode<T>* node)
	{
		if (node->leftChild != nullptr)
			return Maximum(node->leftChild); // Maximum se debe mandar a llamar desde la izquierda del node que se recibió como parámetro.

		// si no, entonces 
		// tomamos el padre de node, y lo guardamos en una variable
		TreeNode<T>* ancestor = node->parent;
		// Mientras que no llegue a null y siga siendo hijo izquierdo de alguien, entonces se seguirá
		// subiendo en los parents.
		while (ancestor != nullptr && node == ancestor->leftChild)
		{
			// node se vuelve su papá
			node = ancestor;
			// y el papá se vuelve su papá
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
		// si el valor que estás buscando (value) es menor que el de este nodo, vete al hijo izquierdo
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

	// Funciones auxiliares que no estan publicas.
	// Estas helpers permiten realizar operaciones internas cuando se requiera.

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

};

/*
 SOLO ERA PARA MOTIVOS DE PROBAR QUE SUCCESSOR FUNCIONARA, SÍ PARECE FUNCIONAR.
	T SuccessorValue(T value)
	{
		// primero buscamos el nodo que tiene ese valor.
		TreeNode<T>* node = SearchRecursive(root, value);

		if (node == nullptr)
		{
			throw runtime_error("no se encontró value en este árbol para hacer Sucessor");
			return {};
		}

		TreeNode<T>* result = Successor(node);
		if (result == nullptr)
		{
			throw runtime_error("no se encontró un successor para value en este árbol");
			return {};
		}
		return result->data;
	}

*/


#ifdef BST_UNIT_TEST
#include <cassert>
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
	bst.PostOrderIterative_InternalPrint();

	cout << "Pruebas completadas." << endl;
	return 0;
}
#endif

