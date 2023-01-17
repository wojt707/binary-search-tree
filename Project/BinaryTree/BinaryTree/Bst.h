#pragma once

#ifndef BST_H
#define BST_H

#include <memory>

template<typename T>
class BST {
private:
	struct Node
	{
		T data;
		std::unique_ptr<Node> leftChild;
		std::unique_ptr<Node> rightChild;
	};
	std::unique_ptr<Node> root;

	std::unique_ptr<Node> createNode(T _data);
	bool isNotEmpty();
	void insertNode(T _data, std::unique_ptr<Node>& currentNode);
	T findMin(std::unique_ptr<Node>& currentNode);
	T findMax(std::unique_ptr<Node>& currentNode);
	bool findPrivate(std::unique_ptr<Node>& currentNode, T _data);
	void deletePrivate(std::unique_ptr<Node>& currentNode, T _data);
	void erasePrivate(std::unique_ptr<Node>& currentNode);
	void print(std::unique_ptr<Node>& currentNode);


public:
	BST();
	~BST();
	void insert(T _data);
	T findMinimum();
	T findMaximum();
	bool findNode(T _data);
	void deleteNode(T _data);
	void erase();
	void printInOrder();
};

#endif 
