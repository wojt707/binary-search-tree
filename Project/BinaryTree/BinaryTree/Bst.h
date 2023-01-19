/**
 * @file Bst.h
 * @author Wojciech Dolibóg
 * @brief Binary Search Tree class
 * @version 0.1
 * @date 2023-01-19
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#ifndef BST_H
#define BST_H

#include <memory>
 /**
  * @class BST
  * @brief Binary Search Tree
  */
template <typename T>
class BST
{
private:
	/**
	 * @struct Node
	 * @brief Single element in the Binary Search Tree
	 */
	struct Node
	{
		/**
		 * @brief Value of single node
		 */
		T data;
		/**
		 * @brief Pointer to left child
		 */
		std::unique_ptr<Node> leftChild;
		/**
		 * @brief Pointer to right child
		 */
		std::unique_ptr<Node> rightChild;
		/**
		 * @brief Constructor of the new node
		 * @param _data Value to initialize the node
		 */
		Node(T _data);
	};

	/**
	 * @brief Pointer to root of the Binary Search Tree
	 */
	std::unique_ptr<Node> root;
	/**
	 * @brief Helps recursively to copy the other binary search tree
	 * @param other Reference to the node from other binary search tree from which we copy the data
	 * @return Pointer to new created node
	 */
	std::unique_ptr<Node> copyHelper(const std::unique_ptr<Node>& other);
	/**
	 * @brief Checks if binary search tree has any nodes
	 * @return True if has at least one node, false if binary search tree is empty
	 */
	bool isNotEmpty();
	/**
	 * @brief Helps recursively to insert data to binary search tree
	 * @param currentNode Reference to the current node
	 * @param _data Value that is inserted
	 */
	void insertHelper(std::unique_ptr<Node>& currentNode, T _data);
	/**
	 * @brief Helps recursively to find minimum value in the binary search tree
	 * @param currentNode Reference to the current node
	 * @return Minimum value
	 */
	T findMinHelper(std::unique_ptr<Node>& currentNode);
	/**
	 * @brief Helps recursively to find maximum value in the binary search tree
	 * @param currentNode Reference to the current node
	 * @return Maximum value
	 */
	T findMaxHelper(std::unique_ptr<Node>& currentNode);
	/**
	 * @brief Helps recursively to check if the node is in the binary search tree
	 * @param currentNode Reference to the current node
	 * @return True if the node is found, false otherwise
	 */
	bool findHelper(std::unique_ptr<Node>& currentNode, T _data);
	/**
	 * @brief Helps recursively to remove the node from binary search tree
	 * @param currentNode Reference to the current node
	 * @param _data Value that is removed
	 */
	void removeHelper(std::unique_ptr<Node>& currentNode, T _data);
	/**
	 * @brief Helps recursively to erase whole binary search tree
	 * @param currentNode Reference to the current node
	 */
	void eraseHelper(std::unique_ptr<Node>& currentNode);
	/**
	 * @brief Helps recursively to print binary search tree in in-order traversal
	 * @param currentNode Reference to the current node
	 */
	void inOrder(const std::unique_ptr<Node>& currentNode);
	/**
	 * @brief Helps recursively to print binary search tree in pre-order traversal
	 * @param currentNode Reference to the current node
	 */
	void preOrder(const std::unique_ptr<Node>& currentNode);
	/**
	 * @brief Helps recursively to print binary search tree in post-order traversal
	 * @param currentNode Reference to the current node
	 */
	void postOrder(const std::unique_ptr<Node>& currentNode);

public:
	/**
	 * @brief Constructor of the binary search tree
	 */
	BST();
	/**
	 * @brief Copy constructor of the binary search tree
	 * @param other Binary search tree from which we copy the data
	 */
	BST(const BST<T>& other);
	/**
	 * @brief Move constructor of the binary search tree
	 * @param other Binary search tree from which we move the data
	 */
	BST(BST<T>&& other);
	/**
	 * @brief Destructor of the binary search tree
	 */
	~BST();
	/**
	 * @brief Inserts new node to the binary search tree
	 * @param _data Value to initialize the node
	 */
	void insert(T _data);
	/**
	 * @brief Finds minimum value in the binary search tree
	 * @return Minimum value
	 */
	T findMinimum();
	/**
	 * @brief Finds maximum value in the binary search tree
	 * @return Maximum value
	 */
	T findMaximum();
	/**
	 * @brief Checks if the node is in the binary search tree
	 * @param _data Value that is checked
	 * @return True if the node is found, false otherwise
	 */
	bool find(T _data);
	/**
	 * @brief Removes the node from the binary search tree
	 * @param _data Value that is removed
	 */
	void remove(T _data);
	/**
	 * @brief Erases whole binary search tree, sets root pointer to nullptr
	 */
	void erase();
	/**
	 * @brief Prints values of the binary search tree in in-order traversal
	 */
	void printInOrder();
	/**
	 * @brief Prints values of the binary search tree in pre-order traversal
	 */
	void printPreOrder();
	/**
	 * @brief Prints values of the binary search tree in post-order traversal
	 */
	void printPostOrder();
};

#endif
