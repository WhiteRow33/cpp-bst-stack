#include <iostream>
#include "StringStack.h"
using namespace std;

StringStack::StringStack() {
	top = nullptr;
}

StringStack::~StringStack() {
	clear();
	top = nullptr;
}

void StringStack::push(const string& value) {
	StackNode* newNode = new StackNode(value);

	if (isEmpty()) {
		top = newNode;
	}
	else {
		newNode->next = top;
		top = newNode;
	}
}

bool StringStack::isEmpty() const {
	if (top == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

string StringStack::pop() {
	StackNode* newTop;
	string message;

	if (isEmpty()) {
		message = "Stack is empty!!!";
	}
	else {
		message = (top->data);
		newTop = top->next;
		delete top;
		top = newTop;
	}

	return message;
}

void StringStack::printStack() const {
	if (isEmpty()) {
		cout << "" << endl;
	}
	else {
		StackNode* current = top;

		while (current != nullptr) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
}

void StringStack::clear() {
	while (top != nullptr) {
		StackNode* temp = top;
		top = top->next;
		delete temp;
		temp = nullptr;
	}

	top = nullptr;
}

StringStack& StringStack::operator=(const StringStack& other) {
    if (this != &other) {
		this->clear();

		StackNode* current = other.top;
		StringStack tempStack;

		while (current != nullptr) {
			tempStack.push(current->data);
			current = current->next;
		}

		current = tempStack.top;
		while (current != nullptr) {
			this->push(current->data);
			current = current->next;
		}
		return *this;
    }
    return *this; 
}