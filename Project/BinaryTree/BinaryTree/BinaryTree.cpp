// BinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Bst.h"

int main()
{
	BST<int> tree;
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
	tree.printPreOrder();
	tree.printPostOrder();


	BST<double> doubleBST;
	doubleBST.insert(23.5);
	

	return 0;
}