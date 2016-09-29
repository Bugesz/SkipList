#include <cstdlib>
#include "Node.h"

#pragma once

Node::Node(int data) : _data(data), _level(-1)
{
	do
	{
		_next[++_level] = NULL;
	} while (rand()%10 <= 5);
}

Node::~Node()
{
}


void Node::incLevel()
{
	_next[++_level] = NULL;
}

void Node::incLevel(Node * obj)
{
	_next[++_level] = obj;
}
