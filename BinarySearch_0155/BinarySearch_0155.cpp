#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
	string info;
	Node* leftchild;
	Node* rightchild;

	// Constructor for the node class

	Node(string i, Node* l, Node* r)
	{
		info = i;
		leftchild = l;
		rightchild = r;
}

};

class BinaryTree
{
public:
	Node* ROOT;

	BinaryTree()
	{
		ROOT = nullptr; // instalizing Root Null
	}

	void insert(string element) // insert a node in binary search tree
	{
		Node* newNode = new Node(element, nullptr, nullptr); //Allcote memory for the new node
		newNode->info = element;  // Assign value to the data field the new Node
		newNode->leftchild = nullptr; // Make the left child of the new node point to null
		newNode->rightchild = nullptr; // Make the right child of the new node point to null

	}
};

