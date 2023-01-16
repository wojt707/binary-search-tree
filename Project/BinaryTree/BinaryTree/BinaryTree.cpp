// BinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Bst.h"

int main()
{
	BST tree;
	tree.printInOrder();
	std::cout << tree.findNode(1) << std::endl;
	tree.insert(10);
	std::cout << tree.findNode(1) << std::endl;
	std::cout << tree.findNode(10) << std::endl;
	tree.deleteNode(7);
	tree.deleteNode(10);
	tree.insert(3);
	std::cout << "Maximum value is:	" << tree.findMaximum() << std::endl;
	tree.insert(2);
	tree.insert(5);
	tree.insert(7);
	tree.insert(12);
	std::cout << "Maximum value is:	" << tree.findMaximum() << std::endl;
	tree.insert(-1);
	tree.insert(10);
	tree.insert(6);
	tree.deleteNode(0);
	tree.deleteNode(7);
	tree.deleteNode(0);
	tree.insert(12);
	tree.insert(19);
	tree.deleteNode(3);
	tree.deleteNode(12);
	
	
	/*
	int a;
	while (std::cin >> a)
	{
		std::cout << "Searching for " << a << ": " << tree.findNode(a) << std::endl;
	}*/
	 

	return 0;
}