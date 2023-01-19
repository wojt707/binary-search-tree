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

		Node(T _data);
	};
	std::unique_ptr<Node> root;

	std::unique_ptr<Node> copyHelper(const std::unique_ptr<Node>& other);
	bool isNotEmpty();
	void insertNode(T _data, std::unique_ptr<Node>& currentNode);

	T findMin(std::unique_ptr<Node>& currentNode);
	T findMax(std::unique_ptr<Node>& currentNode);
	bool findHelper(std::unique_ptr<Node>& currentNode, T _data);

	void deleteHelper(std::unique_ptr<Node>& currentNode, T _data);
	void eraseHelper(std::unique_ptr<Node>& currentNode);

	void inOrder(const std::unique_ptr<Node>& currentNode);
	void preOrder(const std::unique_ptr<Node>& currentNode);
	void postOrder(const std::unique_ptr<Node>& currentNode);


public:
	BST();
	BST(const BST<T>& other); // copy constructor
	BST(BST<T>&& other); // move constructor
	~BST();
	void insert(T _data);
	T findMinimum();
	T findMaximum();
	bool findNode(T _data);
	void deleteNode(T _data);
	void erase();
	void printInOrder();
	void printPreOrder();
	void printPostOrder();
};

#endif 
