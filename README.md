# cpp-bst-stack

A C++ project that combines Binary Search Tree (BST) and Stack data structures. Each BST node maintains its own stack of strings, enabling hierarchical data storage where each key (node ID) can hold multiple values in LIFO (stack) order.

## Overview

This project showcases:
- A binary search tree where each node contains a stack of strings
- Custom insertion and popping using operator overloading (`<<` and `>>`)
- In-order traversal with formatted output
- Deep copy functionality using assignment operator (`=`)

It's designed for educational use in data structures, object-oriented programming, and operator overloading in C++.

## Features

- Insert string values into stacks at specific BST node IDs
- Pop values from stacks at any node
- Handles empty stacks and missing nodes with informative messages
- In-order traversal that displays each node's ID and stack contents
- Full deep copy of the BST with stack contents preserved
