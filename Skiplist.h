#pragma once
#include "Node.h"
#include <vector>
#include <stack>

class Skiplist {
	
	Node* _head;

	Node* _search(const int data, std::stack<Node*> *s = NULL);

public:

	Skiplist();

	~Skiplist();

	bool search(const int data);

	Node* insert(const int data);

	Node* remove(const int data);

	void print();

};