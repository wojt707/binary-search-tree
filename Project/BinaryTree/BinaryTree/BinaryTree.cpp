// BinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Bst.h"

int main()
{
	BST<int> tree;
	tree.insert(25);
	tree.insert(15);
	BST<int> secondTree = tree;
	tree.printInOrder();
	secondTree.printInOrder();
	BST<int> thirdTree(std::move(tree));
	//tree.printInOrder();
	secondTree.printInOrder();
	thirdTree.printInOrder();

	secondTree.insert(25);
	secondTree.insert(15);
	secondTree.insert(50);
	secondTree.insert(10);
	secondTree.insert(22);
	secondTree.insert(35);
	secondTree.insert(70);
	secondTree.insert(4);
	secondTree.insert(12);
	secondTree.insert(18);
	secondTree.insert(24);
	secondTree.insert(31);
	secondTree.insert(44);
	secondTree.insert(66);
	secondTree.insert(90);


	secondTree.printInOrder();
	thirdTree.printInOrder();

	//BST<double> doubleBST;
	//doubleBST.insert(23.5);


	return 0;
}
