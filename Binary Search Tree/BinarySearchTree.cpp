#include "BinarySearchTree.h"

#include "BinarySearchTree.h"

Node::Node(string key, int value) {
	this->key = key;
	this->value = value;
	this->left = nullptr;
	this->right = nullptr;
}

BinarySearchTree::BinarySearchTree() {
	root = nullptr;
}

BinarySearchTree::~BinarySearchTree() {
	clear(root);
}

void BinarySearchTree::set(string key, int value) {
	root = setHelper(root, key, value);
}

int BinarySearchTree::find(string key) {
	Node* node = findHelper(root, key);
	if (node != nullptr) {
		return node->value;
	}
	else {
		return -1; 
}

void BinarySearchTree::print() {
	printHelper(root);
	cout << endl;
}

Node* BinarySearchTree::min() {
	return minHelper(root);
}

Node* BinarySearchTree::max() {
	return maxHelper(root);
}

void BinarySearchTree::save_file(string filename) {
	ofstream outfile(filename);
	saveHelper(root, outfile);
	outfile.close();
}

bool BinarySearchTree::delete_key(string key) {
	Node* deleted_node = deleteHelper(root, key);
	return (deleted_node != nullptr);
}



void BinarySearchTree::clear(Node* node) {
	if (node != nullptr) {
		clear(node->left);
		clear(node->right);
		delete node;
	}
}

Node* BinarySearchTree::setHelper(Node* node, string key, int value) {
	if (node == nullptr) {
		return new Node(key, value);
	}
	else if (key < node->key) {
		node->left = setHelper(node->left, key, value);
	}
	else if (key > node->key) {
		node->right = setHelper(node->right, key, value);
	}
	else {
		node->value = value;
	}
	return node;
}

Node* BinarySearchTree::findHelper(Node* node, string key) {
	if (node == nullptr || node->key == key) {
		return node;
	}
	else if (key < node->key) {
		return findHelper(node->left, key);



}
 else {
	 return findHelper(node->right, key);
}
}

void BinarySearchTree::printHelper(Node* node) {
	if (node != nullptr) {
		printHelper(node->left);
		cout << "(" << node->key << ", " << node->value << ") ";
		printHelper(node->right);
	}
}

Node* BinarySearchTree::minHelper(Node* node) {
	if (node == nullptr) {
		return nullptr;
	}
	else if (node->left == nullptr) {
		return node;
	}
	else {
		return minHelper(node->left);
	}
}

Node* BinarySearchTree::maxHelper(Node* node) {
	if (node == nullptr) {
		return nullptr;
	}
	else if (node->right == nullptr) {
		return node;
	}
	else {
		return maxHelper(node->right);
	}
}

void BinarySearchTree::saveHelper(Node* node, ofstream& outfile) {
	if (node != nullptr) {
		saveHelper(node->left, outfile);
		outfile << node->key << " " << node->value << endl;
		saveHelper(node->right, outfile);
	}
}

Node* BinarySearchTree::deleteHelper(Node* node, string key) {
	if (node == nullptr) {
		return node;
	}
	else if (key < node->key) {
		node->left = deleteHelper(node->left, key);
	}
	else if (key > node->key) {
		node->right = deleteHelper(node->right, key);
	}
	else {
		if (node->left == nullptr) {
			Node* temp = node->right;
			delete node;
			return temp;
		}
		else if (node->right == nullptr) {
			Node* temp = node->left;
			delete node;
			return temp;
		}
		else {
			Node* temp = getSuccessor(node->right);
			node->key = temp->key;
			node->value = temp->value;
			node->right = deleteHelper(node->right, temp->key);
		}
	}
	return node;
}

Node* BinarySearchTree::getSuccessor(Node* node) {
	while (node->left != nullptr) {
		node = node->left;
	}
	return node;
}