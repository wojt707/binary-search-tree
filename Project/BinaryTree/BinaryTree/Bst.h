#pragma once

#ifndef BST_H
#define BST_H

#include <memory>

class BST {
private:
	struct Node
	{
		int data;
		std::unique_ptr<Node> leftChild;
		std::unique_ptr<Node> rightChild;
	};
	std::unique_ptr<Node> root;

	std::unique_ptr<Node> createNode(int _data);
	bool isNotEmpty();
	void insertNode(int _data, std::unique_ptr<Node>& currentNode);
	int findMin(std::unique_ptr<Node>& currentNode);
	int findMax(std::unique_ptr<Node>& currentNode);
	bool findPrivate(std::unique_ptr<Node>& currentNode, int _data);
	void deletePrivate(std::unique_ptr<Node>& currentNode, int _data);
	void erasePrivate(std::unique_ptr<Node>& currentNode);
	void print(std::unique_ptr<Node>& currentNode);


public:
	BST();
	~BST();
	void insert(int _data);
	int findMinimum();
	int findMaximum();
	bool findNode(int _data);
	void deleteNode(int _data);
	void erase();
	void printInOrder();
};

#endif 
