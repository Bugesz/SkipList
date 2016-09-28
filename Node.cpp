#include "Node.h"
#include <cstdlib>

Node::Node(int data) : _data(data), _level(-1)
{
	do
	{
		++_level;
		_next.push_back(NULL);
	} while (rand()%10 <= 5);
}

Node::~Node()
{
	_next.clear();
}

int Node::getData()
{
	return _data;
}

int Node::getLevel()
{
	return _level;
}

Node * Node::getNext(int level)
{
	if (level < 0 || level >= _next.size())
	{
		return NULL;
	}

	return _next[level];
}

void Node::setNext(int level, Node* obj)
{
	_next[level] = obj;
}

void Node::incLevel()
{
	++_level;
	_next.push_back(NULL);
}

void Node::incLevel(Node * obj)
{
	++_level;
	_next.push_back(obj);
}


// Comparsion operators
bool Node::operator==(const Node & obj)
{
	return _data == obj._data;
}

bool Node::operator==(const int data)
{
	return _data == data;
}

bool Node::operator>(const Node & obj)
{
	return _data > obj._data;
}

bool Node::operator>(const int data)
{
	return _data > data;
}

bool Node::operator<(const Node & obj)
{
	return _data < obj._data;
}

bool Node::operator<(const int data)
{
	return _data < data;
}

bool Node::operator>=(const Node & obj)
{
	return _data >= obj._data;
}

bool Node::operator>=(const int data)
{
	return _data >= data;
}

bool Node::operator<=(const Node & obj)
{
	return _data <= obj._data;
}

bool Node::operator<=(const int data)
{
	return _data <= data;
}
