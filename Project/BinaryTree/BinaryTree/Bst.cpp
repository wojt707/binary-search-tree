#include <iostream>
#include "Bst.h"

template<typename T>
BST<T>::Node::Node(T _data) {
	data = _data;
	leftChild = nullptr;
	rightChild = nullptr;
}

template<typename T>
std::unique_ptr<typename BST<T>::Node> BST<T>::createNode(T _data)
{
	std::unique_ptr<Node> node = std::make_unique<Node>(_data);
	std::cout << "Node " << node->data << " succesfuly created" << std::endl;
	return node;
}

template<typename T>
std::unique_ptr<typename BST<T>::Node> BST<T>::copyHelper(const std::unique_ptr<Node>& other)
{
	if (!other)
	{
		return nullptr;
	}
	else
	{
		std::unique_ptr<Node> newNode = std::make_unique<Node>(other->data);
		std::cout << "Copied node " << newNode->data << std::endl;
		newNode->leftChild = copyHelper(other->leftChild);
		newNode->rightChild = copyHelper(other->rightChild);
		return newNode;
	}
}

template<typename T>
bool BST<T>::isNotEmpty()
{
	return (root) ? true : false;
}

template<typename T>
void BST<T>::insertNode(T _data, std::unique_ptr<Node>& currentNode)
{
	if (!currentNode)
	{
		currentNode = createNode(_data);
	}
	else if (_data < currentNode->data)
	{
		std::cout << "Going to left child" << std::endl;
		insertNode(_data, currentNode->leftChild);
	}
	else if (_data > currentNode->data)
	{
		std::cout << "Going to right child" << std::endl;
		insertNode(_data, currentNode->rightChild);
	}
	else
	{
		std::cout << "The node " << _data << " has already been added to the tree" << std::endl;
	}

}

template<typename T>
T BST<T>::findMin(std::unique_ptr<Node>& currentNode)
{
	if (!currentNode)
	{
		std::cout << "Error: BST is empty";
		std::exit(1);
	}
	if (currentNode->leftChild)
		findMin(currentNode->leftChild);
	else
		return currentNode->data;
}

template<typename T>
T BST<T>::findMax(std::unique_ptr<Node>& currentNode)
{
	if (!currentNode)
	{
		std::cout << "Error: BST<T> is empty";
		std::exit(1);
	}
	if (currentNode->rightChild)
		findMax(currentNode->rightChild);
	else
		return currentNode->data;
}

template<typename T>
bool BST<T>::findPrivate(std::unique_ptr<Node>& currentNode, T _data)
{
	if (!currentNode) {
		std::cout << "Node " << _data << " not found" << std::endl;
		return false;

	}
	if (_data < currentNode->data)
		return findPrivate(currentNode->leftChild, _data);

	else if (_data > currentNode->data)
		return findPrivate(currentNode->rightChild, _data);

	else {
		std::cout << "Node " << _data << " succesfully found" << std::endl;
		return true;
	}


}

template<typename T>
void BST<T>::deletePrivate(std::unique_ptr<Node>& currentNode, T _data)
{
	if (_data < currentNode->data)
		deletePrivate(currentNode->leftChild, _data);

	else if (_data > currentNode->data)
		deletePrivate(currentNode->rightChild, _data);

	else {
		if (!currentNode->leftChild && !currentNode->rightChild)
			currentNode.reset();

		else if (!currentNode->leftChild)
			currentNode = std::move(currentNode->rightChild);

		else if (!currentNode->rightChild)
			currentNode = std::move(currentNode->leftChild);

		else
		{
			T successor = findMin(currentNode->rightChild);
			currentNode->data = successor;
			deletePrivate(currentNode->rightChild, successor);
		}
	}
}

template<typename T>
void BST<T>::erasePrivate(std::unique_ptr<Node>& currentNode)
{
	if (currentNode)
	{
		erasePrivate(currentNode->leftChild);
		erasePrivate(currentNode->rightChild);
		currentNode.reset();
	}
}

template<typename T>
void BST<T>::inOrder(const std::unique_ptr<Node>& currentNode)
{
	if (currentNode)
	{
		inOrder(currentNode->leftChild);
		std::cout << currentNode->data << ' ';
		inOrder(currentNode->rightChild);
	}
}

template<typename T>
void BST<T>::preOrder(const std::unique_ptr<Node>& currentNode)
{
	if (currentNode)
	{
		std::cout << currentNode->data << ' ';
		preOrder(currentNode->leftChild);
		preOrder(currentNode->rightChild);
	}
}

template<typename T>
void BST<T>::postOrder(const std::unique_ptr<Node>& currentNode)
{
	if (currentNode)
	{
		postOrder(currentNode->leftChild);
		postOrder(currentNode->rightChild);
		std::cout << currentNode->data << ' ';
	}
}

template<typename T>
BST<T>::BST()
{
	this->root = nullptr;
	std::cout << "Created Binary search tree" << std::endl;
}

template<typename T>
BST<T>::BST(const BST<T>& other)
{
	this->root = copyHelper(other.root);

	std::cout << "Copied BST" << std::endl;
}

template<typename T>
BST<T>::BST(BST<T>&& other)
{
	this->root = std::move(other.root);

	std::cout << "Moved BST" << std::endl;

}

template<typename T>
BST<T>::~BST()
{
	std::cout << "Deleted Binary search tree" << std::endl;
}

template<typename T>
void BST<T>::insert(T _data)
{
	std::cout << "Trying to insert node " << _data << std::endl;
	insertNode(_data, root);
	//printInOrder();
}

template<typename T>
T BST<T>::findMinimum()
{
	return findMin(root);
}

template<typename T>
T BST<T>::findMaximum()
{
	return findMax(root);
}

template<typename T>
bool BST<T>::findNode(T _data)
{
	if (isNotEmpty())
		return findPrivate(root, _data);
	else {
		std::cout << "Tree is empty" << std::endl;
		return false;
	}
}

template<typename T>
void BST<T>::deleteNode(T _data)
{
	if (findNode(_data))
	{
		deletePrivate(root, _data);
		std::cout << "Node " << _data << " succesfully deleted" << std::endl;
	}
	else
	{
		std::cout << _data << " is not in the tree so it cannot be deleted" << std::endl;
	}
}

template<typename T>
void BST<T>::erase()
{
	erasePrivate(root);
	std::cout << "Succesfully erased whole tree" << std::endl;
}

template<typename T>
void BST<T>::printInOrder()
{
	if (isNotEmpty())
	{
		std::cout << "In-order traversal: ";
		inOrder(root);
		std::cout << std::endl;

	}
	else {
		std::cout << "Tree is empty" << std::endl;
	}
}

template<typename T>
void BST<T>::printPreOrder()
{
	if (isNotEmpty())
	{
		std::cout << "Pre-order traversal: ";
		preOrder(root);
		std::cout << std::endl;

	}
	else {
		std::cout << "Tree is empty" << std::endl;
	}
}

template<typename T>
void BST<T>::printPostOrder()
{
	if (isNotEmpty())
	{
		std::cout << "Post-order traversal: ";
		postOrder(root);
		std::cout << std::endl;

	}
	else {
		std::cout << "Tree is empty" << std::endl;
	}
}

template class BST<int>;
template class BST<float>;
template class BST<double>;
template class BST<std::string>;
template class BST<char>;
template class BST<bool>;