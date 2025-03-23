#include <iostream>
#include "BSTStringStack.h"
using namespace std;

BSTStringStack::BSTStringStack() {
	root = nullptr;
}

BSTStringStack::~BSTStringStack() {
	clear(root);
	root = nullptr;
}

// Helper function to insert a node into the BST and count nodes checked
int BSTStringStack::insert(BSTNode*& node, int id, const std::string& value) {
	int nodeChecked = 0;
	
	if (node == nullptr) {
		node = new BSTNode(id);
		node->stack.push(value);
		nodeChecked++;
	}

	else {
		if (id < node->id) {
			nodeChecked++;
			nodeChecked += insert(node->left, id, value);
		}
		else if (id > node->id) {
			nodeChecked++;
			nodeChecked += insert(node->right, id, value);
		}
		else {
			nodeChecked++;
			node->stack.push(value);
		}
	}

	return nodeChecked;
}

// Helper function to search for a node in the BST and count nodes checked
int BSTStringStack::search(BSTNode* node, int id, string& value) {
	int nodeChecked = 0;

	if (node == nullptr) {
		return nodeChecked;
	}
	else {
		nodeChecked++; 

		if (id < node->id) {
			nodeChecked += search(node->left, id, value);
		}
		else if (id > node->id) {
			nodeChecked += search(node->right, id, value);
		}
		else {
			if (node->stack.isEmpty()) {
				value = "Stack is empty!!!";
			}
			else {
				value = node->stack.pop();
			}
		}
	}

	return nodeChecked;
}

// Helper function for in-order traversal
void BSTStringStack::printInOrder(BSTNode* node) const {
	if (node == nullptr) {
		return;
	}
	printInOrder(node->left);
	cout << "ID: " << node->id << " | Stack: ";
	node->stack.printStack();
	printInOrder(node->right);
}

void BSTStringStack::printInOrder() const {
	printInOrder(root);
}


void BSTStringStack::clear(BSTNode* node) {
	if (node == nullptr) {
		return;
	}
	clear(node->left);
	clear(node->right);
	delete node;
}

int operator<<(BSTStringStack& bst, const pair<int, string>& p) {
	return bst.insert(bst.root, p.first, p.second);
}

int operator>>(BSTStringStack& bst, pair<int, string>& p) {
	string result;
	int nodesChecked = bst.search(bst.root, p.first, result);

	if (result.empty()) {
		p.second = "Node is not in BST!!!";
	}
	else if (result == "Stack is empty!!!") {
		p.second = "Stack is empty!!!";
	}
	else {
		p.second = result;
	}
	return nodesChecked;
}

BSTStringStack& BSTStringStack::operator=(const BSTStringStack& other) {
	if (this != &other) {
		clear(root);

		root = copyTree(other.root);

		return *this;
    }
	return *this;
}

BSTStringStack::BSTNode* BSTStringStack::copyTree(const BSTNode* root) {
	if (root == nullptr) {
		return nullptr;
	}

	BSTNode* newNode = new BSTNode(root->id);

	newNode->stack = root->stack;
	newNode->left = copyTree(root->left);
	newNode->right = copyTree(root->right);

	return newNode;
}