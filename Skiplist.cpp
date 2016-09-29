#include "Skiplist.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>

Node* Skiplist::_search(const int data, std::stack<Node*>* s)
{
	Node *tmp = _head;
	int level = _head->getLevel();
	

	if (s != NULL)
	{
		while (!s->empty()) 
		{
			s->pop();
		}
	}

	while (level >= 0)
	{
		while(tmp->getNext(level) && *(tmp->getNext(level)) <= data)
		{

			if (*(tmp->getNext(level)) == data) 
			{
				return tmp->getNext(level);
			}
			else
			{
				if (s != NULL)
				{
					s->push(tmp);
				}

				tmp = tmp->getNext(level);
			}
		}
		--level;
	}

	if (s)
	{
		s->push(tmp);
	}

	return tmp;
}

Skiplist::Skiplist()
{
	srand(time(NULL));
	_head = new Node(NULL);
}

Skiplist::~Skiplist()
{
	Node *tmp;

	while (_head != NULL) {
		tmp = _head;
		_head = _head->getNext();

		delete tmp;
	}
}

bool Skiplist::search(const int data)
{
	return *(_search(data)) == data;
}

Node* Skiplist::insert(const int data)
{
	std::stack<Node*> *visited = new std::stack<Node*>;

	if (*(_search(data, visited)) == data) {
		printf("%d is already in the list --> List not changed!\n", data);
		return _head;
	}
	
	
	Node *node = new Node(data);
	Node *tmp;

	int level = 0;
	

	while (!visited->empty())
	{
		tmp = visited->top();
		visited->pop();
		if (tmp == _head)
		{
			while (level <= std::min(node->getLevel(), _head->getLevel())) {
				node->setNext(level, _head->getNext(level));
				_head->setNext(level, node);
				++level;
			}
			while (_head->getLevel() < node->getLevel())
			{
				_head->incLevel(node);
			}
		}
		else
		{
			while (level <= std::min(node->getLevel(), tmp->getLevel())) {
				node->setNext(level, tmp->getNext(level));
				tmp->setNext(level, node);
				++level;
			}
		}
	}
	

	return _head;
}

void Skiplist::print()
{
	Node *tmp;
	int z = _head->getLevel();

	for (int i = z; i >= 0; i-- )
	{
		tmp = _head;
		while (tmp)
		{
			if (tmp->getLevel() >= i) {
				if (tmp != _head) {
					printf("%d\t", tmp->getData());
				}
				else {
					printf("H\t", tmp->getData());
				}
			}
			else
			{
				printf("-\t", tmp->getData());
			}
			tmp = tmp->getNext();
		}
		printf("\n");
	}

}
