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

	void search(string element, Node*& parent, Node*& currentNode)
	{
		// this function searches the currentNode of the specified Node as well as the current Node is parent
		currentNode = ROOT;
		parent = nullptr;
		while ((currentNode != nullptr) && (currentNode->info != element))
		{
			parent = currentNode;
			if (element < currentNode->info)
				currentNode = currentNode->leftchild;
			else
				currentNode = currentNode->rightchild;
		}
	}

	void inorder(Node* ptr)
	{
		if (ROOT == nullptr)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != nullptr)
		{
			inorder(ptr->leftchild);
			cout << ptr->info << " ";
			inorder(ptr->rightchild);
		}

	}

	void preorder(Node* ptr)
	{
		if (ROOT == nullptr)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != nullptr)
		{
			cout << ptr->info << " ";
			preorder(ptr->leftchild);
			preorder(ptr->rightchild);
		}

	}

	void postorder(Node* ptr)
	{
		if (ROOT == nullptr)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != nullptr)
		{	
			postorder(ptr->leftchild);
			postorder(ptr->rightchild);
			cout << ptr->info << " ";
		}

	}
};

int main() {
	BinaryTree x;
	while (true)
	{
		cout << "\nMenu" << endl;
		cout << "1. Implement insert operation" << endl;
		cout << "2. Perform inorder traversal" << endl;
		cout << "3. Perform preorder traversal" << endl;
		cout << "4. Perform postoerder traversal" << endl;
		cout << "5. exit" << endl;
		cout << "\nEnter your choice 1-5 :";

		char ch;
		cin >> ch;
		cout << endl;

		switch (ch)
		{
		case '1' :
		{
			cout << "Enter a word: ";
			string word;
			cin >> word;
			x.insert(word);
			break;
		}
		case '2' :
		{
			x.inorder(x.ROOT);
			break;
		}
		case '3' :
		{
			x.preorder(x.ROOT);
			break;
		}
		case '4':
		{
			x.postorder(x.ROOT);
			break;
		}
		case '5':
		{
			return 0;
		}

		}	
	}
}



