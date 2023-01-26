#include <iostream>
#include "Bst.h"

int main()
{
	int treeValues[] = { 25, 15, 50, 10, 22, 35, 70, 4, 12, 18, 24, 31, 44, 66, 90 };

	BST<int> tree;
	for (int i = 0; i < 15; i++)
		tree.insert(treeValues[i]);

	tree.printInOrder();
	tree.printPostOrder();
	tree.printPreOrder();
	tree.remove(19);
	tree.remove(35);

	std::cout << "Minimum " << tree.findMinimum() << std::endl;
	std::cout << "Maximum " << tree.findMaximum() << std::endl;
	auto c = (tree.find(35)) ? "35 found" : "35 not found";
	std::cout << c << std::endl;

	BST<int> tree2(tree);
	tree.printInOrder();
	tree2.printInOrder();
	BST<int> tree3(std::move(tree2));
	tree.printInOrder();
	//tree2.printInOrder(); // <------- Warning: Use of a moved from object : ''tree2'' (lifetime.1)
	tree3.printInOrder();
	tree.erase();
	tree.printInOrder();

	return 0;
}
