#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Node {
public:
    string key;
    int value;
    Node* left;
    Node* right;

    Node(string key, int value);
};

class BinarySearchTree {
public:
    BinarySearchTree();
    ~BinarySearchTree();

    void set(string key, int value);
    int find(string key);
    void print();
    Node* min();
    Node* max();
    void save_file(string filename);
    bool delete_key(string key);

private:
    Node* root;

    void clear(Node* node);
    Node* setHelper(Node* node, string key, int value);
    Node* findHelper(Node* node, string key);
    void printHelper(Node* node);
    Node* minHelper(Node* node);
    Node* maxHelper(Node* node);
    void saveHelper(Node* node, ofstream& outfile);
    Node* deleteHelper(Node* node, string key);
    Node* getSuccessor(Node* node);
};

#endif
