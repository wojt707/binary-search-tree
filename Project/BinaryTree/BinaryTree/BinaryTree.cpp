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

	tree.insert(25);
	tree.insert(15);
	tree.insert(50);
	tree.insert(10);
	tree.insert(22);
	tree.insert(35);
	tree.insert(70);
	tree.insert(4);
	tree.insert(12);
	tree.insert(18);
	tree.insert(24);
	tree.insert(31);
	tree.insert(44);
	tree.insert(66);
	tree.insert(90);


	tree.printInOrder();
	secondTree.printInOrder();

	tree.deleteNode(22);

	tree.printInOrder();
	secondTree.printInOrder();

	secondTree.deleteNode(10);
	secondTree.insert(7);

	tree.printInOrder();
	secondTree.printInOrder();

	//BST<double> doubleBST;
	//doubleBST.insert(23.5);
	

	return 0;
}