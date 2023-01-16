#include <iostream>
#include "Bst.h"

std::unique_ptr<BST::Node> BST::createNode(int _data)
{
	std::unique_ptr<Node> node = std::make_unique<Node>();
	node->data = _data;
	node->leftChild = nullptr;
	node->rightChild = nullptr;
	std::cout << "Node " << node->data << " succesfuly inserted" << std::endl;
	return node;
}

bool BST::isNotEmpty()
{
	return (root) ? true: false;
}

void BST::insertNode(int _data, std::unique_ptr<Node>& currentNode)
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

int BST::findMin(std::unique_ptr<Node>& currentNode)
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

int BST::findMax(std::unique_ptr<Node>& currentNode)
{
	if (!currentNode)
	{
		std::cout << "Error: BST is empty";
		std::exit(1);
	}
	if (currentNode->rightChild)
		findMax(currentNode->rightChild);
	else
		return currentNode->data;
}

bool BST::findPrivate(std::unique_ptr<Node>& currentNode, int _data)
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

void BST::deletePrivate(std::unique_ptr<Node>& currentNode, int _data)
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
			int successor = findMin(currentNode->rightChild);
			currentNode->data = successor;
			deletePrivate(currentNode->rightChild, successor);
		}
	}
}

void BST::erasePrivate(std::unique_ptr<Node>& currentNode)
{
	if (currentNode)
	{
		erasePrivate(currentNode->leftChild);
		erasePrivate(currentNode->rightChild);
		currentNode.reset();
	}
}

void BST::print(std::unique_ptr<Node>& currentNode)
{
	if (currentNode)
	{
		print(currentNode->leftChild);
		std::cout << currentNode->data << ' ';
		print(currentNode->rightChild);
	}
}

BST::BST()
{
	this->root = nullptr;
	std::cout << "Created Binary search tree" << std::endl;
}

BST::~BST()
{
	std::cout << "Deleted Binary search tree" << std::endl;
}

void BST::insert(int _data)
{
	std::cout << "Trying to insert node " << _data << std::endl;
	insertNode(_data, root);
	printInOrder();
}

int BST::findMinimum()
{
	return findMin(root);
}

int BST::findMaximum()
{
	return findMax(root);
}

bool BST::findNode(int _data)
{
	if (isNotEmpty())
		return findPrivate(root, _data);
	else {
		std::cout << "Tree is empty" << std::endl;
		return false;
	}
}

void BST::deleteNode(int _data)
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
	printInOrder();
}

void BST::erase()
{
	erasePrivate(root);
	std::cout << "Succesfully erased whole tree" << std::endl;
}

void BST::printInOrder()
{
	if (isNotEmpty())
	{
		std::cout << "All nodes: ";
		print(root);
		std::cout << std::endl;

	}
	else {
		std::cout << "Tree is empty" << std::endl;
	}
}
