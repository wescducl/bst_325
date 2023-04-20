#include <iostream>
#include <fstream>
#include "BinarySearchTree.h"

using namespace std;

int main() {
    BinarySearchTree bst;
    string filename;

    cout << "Enter the name of the file to read from: ";
    cin >> filename;

    ifstream infile(filename);

    if (!infile) {
        cerr << "Error: could not open file" << endl;
        return 1;
    }

    string key;
    int value;

    while (infile >> key >> value) {
        bst.set(key, value);
    }

    infile.close();

    char choice;

    do {
        cout << "Please choose an operation to perform:" << endl;
        cout << "1. Find" << endl;
        cout << "2. Insert" << endl;
        cout << "3. Delete" << endl;
        cout << "4. Print" << endl;
        cout << "5. Find minimum" << endl;
        cout << "6. Find maximum" << endl;
        cout << "7. Save to file" << endl;
        cout << "8. Exit" << endl;
        cin >> choice;

        switch (choice) {
        case '1': {
            string key;
            cout << "Enter a key to find: ";
            cin >> key;
            int result = bst.find(key);
            if (result != -1) {
                cout << "Value found: " << result << endl;
            }
            else {
                cout << "Value not found." << endl;
            }
            break;
        }
        case '2': {
            string key;
            int value;
            cout << "Enter a key and value to insert: ";
            cin >> key >> value;
            bst.set(key, value);
            cout << "Value inserted." << endl;
            break;
        }
        case '3': {
            string key;
            cout << "Enter a key to delete: ";
            cin >> key;
            bool success = bst.delete_key(key);
            if (success) {
                cout << "Value and key deleted." << endl;
            }
            else {
                cout << "Value and key not found." << endl;
            }
            break;
        }
        case '4': {
            bst.print();
            break;
        }
        case '5': {
            Node* min = bst.min();
            if (min != nullptr) {
                cout << "Minimum key: (" << min->key << ", " << min->value << ")" << endl;
            }
            else {
                cout << "The tree is empty." << endl;
            }
            break;
        }
        case '6': {
            Node* max_node = bst.max();
            if (max_node != nullptr) {
                cout << "Maximum key: (" << max_node->key << ", " << max_node->value << ")" << endl;
            }
            else {
                cout << "The tree is empty." << endl;
            }
            break;
        }
        case '7': {
            string filename;
            cout << "Enter the name of the file to save to: ";
            cin >> filename;
            bst.save_file(filename);
            cout << "Tree saved to file." << endl;
            break;
        }
        case '8': {
            cout << "Exiting program." << endl;
            break;
        }
        default: {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    } while (choice != '8');

    return 0;
}