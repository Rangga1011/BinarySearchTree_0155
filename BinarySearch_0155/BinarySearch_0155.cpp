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

		Node* parent = nullptr;
		Node* currentNode = nullptr;
		search(element, parent, currentNode); // locate the node which will be to parent of the node

		if (parent == nullptr) // if the parent is NULL (Tree is Empty)
		{
			ROOT = newNode;  // Make the new node root
			return; // exit

		}
		if (element < parent->info) // if the value in the data field of the new node is last than that
		{
			parent->leftchild = newNode; // make the left child of the parent point to the new node
		}
		else if (element > parent->info) // if the value in the data field in the new node is greater
		{
			parent->rightchild = newNode;  // make the right child of the parent point to the new node
		}
	}
};

