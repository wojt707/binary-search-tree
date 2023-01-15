#include <iostream>
#include "Bst.h"

std::unique_ptr<BST::Node> BST::createNode(int _data)
{
	std::unique_ptr<Node> node = std::make_unique<Node>();
	node->data = _data;
	node->leftChild = nullptr;
	node->rightChild = nullptr;
	std::cout << "Node " << node->data << " succesfuly created" << std::endl;
	return node;
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
		std::cout << "The data " << _data << " has already been added to the tree" << std::endl;
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
}

void BST::printInOrder()
{
	print(root);
	std::cout << std::endl;
}
