#pragma once
class BstNode
{
public:
	BstNode();
	~BstNode();

private:
	int data;
	BstNode* leftChild;
	BstNode* rightChild;
};
