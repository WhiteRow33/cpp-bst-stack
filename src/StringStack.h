#pragma once

#include <string>
#include <iostream>

class StringStack {
private:
    struct StackNode {
        std::string data;
        StackNode* next;
        StackNode(std::string value, StackNode* nextNode = nullptr)
            : data(value), next(nextNode) {}
    };
    StackNode* top;

public:
    StringStack();
    ~StringStack();
    void push(const std::string& value);
    std::string pop();
    bool isEmpty() const;
    void printStack() const; 
    void clear();

    StringStack& operator=(const StringStack &other);
};