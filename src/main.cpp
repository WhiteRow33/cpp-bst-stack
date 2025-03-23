#include <iostream>
#include <string>
#include "BSTStringStack.h"
#include "StringStack.h"

int main() {
    // Initialize a BSTStringStack: a BST where each node holds a stack of strings
    BSTStringStack bstStringStack;

    int nodesChecked;

    // Insert (id, value) pairs into the BST
    // If the node doesn't exist, it's created
    // The string is pushed onto the corresponding node's stack
    // The operator<< returns the number of nodes visited during the operation
    nodesChecked = bstStringStack << std::make_pair(7, "CS204");
    std::cout << "Nodes checked during insertion: " << nodesChecked << std::endl;

    nodesChecked = bstStringStack << std::make_pair(10, "world");
    std::cout << "Nodes checked during insertion: " << nodesChecked << std::endl;

    nodesChecked = bstStringStack << std::make_pair(15, "example");
    std::cout << "Nodes checked during insertion: " << nodesChecked << std::endl;

    nodesChecked = bstStringStack << std::make_pair(8, "is good");
    std::cout << "Nodes checked during insertion: " << nodesChecked << std::endl;

    nodesChecked = bstStringStack << std::make_pair(7, "to");
    std::cout << "Nodes checked during insertion: " << nodesChecked << std::endl;

    nodesChecked = bstStringStack << std::make_pair(10, "hello");
    std::cout << "Nodes checked during insertion: " << nodesChecked << std::endl;

    nodesChecked = bstStringStack << std::make_pair(8, "stack");
    std::cout << "Nodes checked during insertion: " << nodesChecked << std::endl;

    nodesChecked = bstStringStack << std::make_pair(18, "algorithm");
    std::cout << "Nodes checked during insertion: " << nodesChecked << std::endl;

    nodesChecked = bstStringStack << std::make_pair(1, "binary");
    std::cout << "Nodes checked during insertion: " << nodesChecked << std::endl;

    nodesChecked = bstStringStack << std::make_pair(7, "welcome");
    std::cout << "Nodes checked during insertion: " << nodesChecked << std::endl;

    // Display the contents of the BST (in-order traversal)
    std::cout << "\nBST in-order traversal (top of each stack appears first):" << std::endl;
    bstStringStack.printInOrder();

    // --- Pop operations using operator>> ---
    // Pops the top value from the stack at node with id=10, three times
    std::cout << "\nPopping stack with id 10 three times:" << std::endl;
    std::pair<int, std::string> Q10(10, "");
    for (int i = 0; i < 3; ++i) {
        nodesChecked = bstStringStack >> Q10;
        std::cout << "Popped value: " << Q10.second << std::endl;
        std::cout << "Nodes checked during popping: " << nodesChecked << std::endl;
    }

    // Attempt to pop from a node that does not exist (id = -1)
    std::cout << "\nPopping stack with id -1 (non-existent node):" << std::endl;
    std::pair<int, std::string> QM1(-1, "");
    nodesChecked = bstStringStack >> QM1;
    std::cout << "Popped value: " << QM1.second << std::endl;
    std::cout << "Nodes checked during popping: " << nodesChecked << std::endl;

    // --- Copy and test with a second BST ---
    BSTStringStack bstStringStack2;
    bstStringStack2 = bstStringStack;  // Copy the entire tree

    std::cout << "\nBST2 in-order traversal (copy of original):" << std::endl;
    bstStringStack2.printInOrder();

    // Pop once from node id=10 in the copied tree
    std::cout << "Popping stack with id 10 from BST2:" << std::endl;
    nodesChecked = bstStringStack2 >> Q10;
    std::cout << "Popped value: " << Q10.second << std::endl;
    std::cout << "Nodes checked during popping: " << nodesChecked << std::endl;

    // Pop multiple times from node id=7 in BST2
    std::cout << "\nPopping stack with id 7 four times from BST2:" << std::endl;
    std::pair<int, std::string> Q7(7, "");
    for (int i = 0; i < 4; ++i) {
        nodesChecked = bstStringStack2 >> Q7;
        std::cout << "Popped value: " << Q7.second << std::endl;
        std::cout << "Nodes checked during popping: " << nodesChecked << std::endl;
    }

    // Final display of both BSTs
    std::cout << "\nFinal state of original BST:" << std::endl;
    bstStringStack.printInOrder();

    std::cout << "Final state of BST2 (copied version):" << std::endl;
    bstStringStack2.printInOrder();

    return 0;
}
