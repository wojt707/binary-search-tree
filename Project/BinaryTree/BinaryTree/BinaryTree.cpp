// BinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Bst.h"

int main()
{
	BST tree;
	tree.insert(10);
	tree.insert(13);
	std::cout << "Maximum value is:	" << tree.findMaximum() << std::endl;
	tree.insert(2);
	tree.insert(5);
	tree.insert(7);
	tree.insert(12);
	std::cout << "Maximum value is:	" << tree.findMaximum() << std::endl;
	tree.insert(-1);
	tree.insert(10);
	tree.insert(6);
	std::cout << std::endl;
	tree.printInOrder();
	int a;
	while (std::cin >> a)
	{
		std::cout << "Searching for " << a << ": " << tree.search(a) << std::endl;
	}
	 

	return 0;
}