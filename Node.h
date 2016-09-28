#pragma once
#include <vector>

class Node {
	int _level;
	int _data;
	
	std::vector<Node*> _next;
		
public:

	// Constructor
	Node(int data);

	// Destructor
	~Node();

	// Getters
	int getData();
	int getLevel();
	
	Node *getNext(int level = 0);

	// Setters
	void setNext(int level, Node* obj);

	void incLevel();
	void incLevel(Node* obj);

	// Comparsion operators
	bool operator ==(const Node& obj);
	bool operator ==(const int data);

	bool operator  >(const Node& obj);
	bool operator  >(const int data);

	bool operator  <(const Node& obj);
	bool operator  <(const int data);

	bool operator >=(const Node& obj);
	bool operator >=(const int data);

	bool operator <=(const Node& obj);
	bool operator <=(const int data);

};