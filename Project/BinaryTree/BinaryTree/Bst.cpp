/**
 * @file Bst.cpp
 * @author Wojciech Dolibóg
 * @brief Binary Search Tree implementation
 * @version 0.1
 * @date 2023-01-19
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include "Bst.h"

template<typename T>
BST<T>::Node::Node(T _data) {
	data = _data;
	leftChild = nullptr;
	rightChild = nullptr;
}

template<typename T>
std::unique_ptr<typename BST<T>::Node> BST<T>::copyHelper(const std::unique_ptr<Node>& other)
{
	if (!other)
		return nullptr;
	else
	{
		std::unique_ptr<Node> newNode = std::make_unique<Node>(other->data);
		newNode->leftChild = copyHelper(other->leftChild);
		newNode->rightChild = copyHelper(other->rightChild);
		return newNode;
	}
}

template<typename T>
void BST<T>::insertHelper(std::unique_ptr<Node>& currentNode, T _data)
{
	if (!currentNode)
		currentNode = std::make_unique<Node>(_data);

	else if (_data < currentNode->data)
		insertHelper(currentNode->leftChild, _data);

	else if (_data > currentNode->data)
		insertHelper(currentNode->rightChild, _data);
}

template<typename T>
T BST<T>::findMinHelper(std::unique_ptr<Node>& currentNode)
{
	if (currentNode->leftChild)
		findMinHelper(currentNode->leftChild);
	else
		return currentNode->data;
}

template<typename T>
T BST<T>::findMaxHelper(std::unique_ptr<Node>& currentNode)
{
	if (currentNode->rightChild)
		findMaxHelper(currentNode->rightChild);
	else
		return currentNode->data;
}

template<typename T>
bool BST<T>::findHelper(std::unique_ptr<Node>& currentNode, T _data)
{
	if (!currentNode)
		return false;

	if (_data < currentNode->data)
		return findHelper(currentNode->leftChild, _data);

	else if (_data > currentNode->data)
		return findHelper(currentNode->rightChild, _data);

	else
		return true;
}

template<typename T>
void BST<T>::removeHelper(std::unique_ptr<Node>& currentNode, T _data)
{
	if (_data < currentNode->data)
		removeHelper(currentNode->leftChild, _data);

	else if (_data > currentNode->data)
		removeHelper(currentNode->rightChild, _data);

	else {
		if (!currentNode->leftChild && !currentNode->rightChild)
			currentNode.reset();

		else if (!currentNode->leftChild)
			currentNode = std::move(currentNode->rightChild);

		else if (!currentNode->rightChild)
			currentNode = std::move(currentNode->leftChild);

		else
		{
			T successor = findMinHelper(currentNode->rightChild);
			currentNode->data = successor;
			removeHelper(currentNode->rightChild, successor);
		}
	}
}

template<typename T>
void BST<T>::eraseHelper(std::unique_ptr<Node>& currentNode)
{
	if (currentNode)
	{
		eraseHelper(currentNode->leftChild);
		eraseHelper(currentNode->rightChild);
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
}

template<typename T>
BST<T>::BST(const BST<T>& other)
{
	this->root = copyHelper(other.root);
}

template<typename T>
BST<T>::BST(BST<T>&& other)
{
	this->root = std::move(other.root);
}

template<typename T>
bool BST<T>::isNotEmpty()
{
	return (root) ? true : false;
}

template<typename T>
void BST<T>::insert(T _data)
{
	insertHelper(root, _data);
}

template<typename T>
T BST<T>::findMinimum()
{
	if (isNotEmpty())
		return findMinHelper(root);
	else
	{
		std::cout << "Error: BST is empty";
		std::exit(1);
	}
}

template<typename T>
T BST<T>::findMaximum()
{
	if (isNotEmpty())
		return findMaxHelper(root);
	else
	{
		std::cout << "Error: BST is empty";
		std::exit(1);
	}
}

template<typename T>
bool BST<T>::find(T _data)
{
	if (isNotEmpty())
		return findHelper(root, _data);
	else
		return false;
}

template<typename T>
void BST<T>::remove(T _data)
{
	if (find(_data))
		removeHelper(root, _data);
}

template<typename T>
void BST<T>::erase()
{
	eraseHelper(root);
}

template<typename T>
void BST<T>::printInOrder()
{
	if (isNotEmpty())
	{
		std::cout << "In-order traversal: " << std::endl;
		inOrder(root);
		std::cout << std::endl;
	}
	else
		std::cout << "Tree is empty" << std::endl;
}

template<typename T>
void BST<T>::printPreOrder()
{
	if (isNotEmpty())
	{
		std::cout << "Pre-order traversal: " << std::endl;
		preOrder(root);
		std::cout << std::endl;
	}
	else
		std::cout << "Tree is empty" << std::endl;
}

template<typename T>
void BST<T>::printPostOrder()
{
	if (isNotEmpty())
	{
		std::cout << "Post-order traversal: " << std::endl;
		postOrder(root);
		std::cout << std::endl;
	}
	else
		std::cout << "Tree is empty" << std::endl;
}

template class BST<int>;
template class BST<float>;
template class BST<double>;
template class BST<std::string>;
template class BST<char>;
template class BST<bool>;
