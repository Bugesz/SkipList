#pragma once
#include "Node.h"
#include <vector>
#include <stack>

template <class T>
class Skiplist {
	
	Node<T>* _head;

	Node<T>* _search(const T data, std::stack<Node<T>*> *s = NULL);

public:

	Skiplist();

	~Skiplist();

	bool search(const T data);

	Node<T>* insert(const T data);

	Node<T>* remove(const T data);

	void print();

};

template <class T>
Node<T>* Skiplist<T>::_search(const T data, std::stack<Node<T>*>* s)
{
	Node<T> *tmp = _head;
	
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
		while (tmp->getNext(level) != nullptr && *(tmp->getNext(level)) <= data)
		{

			if (s)
			{
				s->push(tmp);
			}


			if (*(tmp->getNext(level)) == data)
			{
				return tmp->getNext(level);
			}
			else
			{
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

template <class T>
Skiplist<T>::Skiplist()
{
	srand((unsigned int)time(NULL));
	_head = new Node<T>(NULL);
}

template <class T>
Skiplist<T>::~Skiplist()
{
	Node<T> *tmp;

	while (_head != NULL) {
		tmp = _head;
		_head = _head->getNext();

		delete tmp;
	}
}

template <class T>
bool Skiplist<T>::search(const T data)
{
	return 0;//*(_search(data)) == data;
}

template <class T>
Node<T>* Skiplist<T>::insert(const T data)
{
	std::stack<Node<T>*> *visited = new std::stack<Node<T>*>;

	if (*(_search(data, visited)) == data) {
		return _head;
	}


	Node<T> *node = new Node<T>(data);
	Node<T> *tmp;

	int level = 0;
	bool over = false;

	while (!visited->empty() && !over)
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
			over = node->getLevel() <= tmp->getLevel();
		}
	}

	return _head;
}

template <class T>
Node<T>* Skiplist<T>::remove(const T data)
{
	std::stack<Node<T>*> *visited = new std::stack<Node<T>*>;

	Node<T> *old;
	Node<T> *tmp;

	old = _search(data, visited);

	// Item not in the list
	if (*old != data) {
		return _head;
	}

	int level = 0;
	bool over = false;

	while (!visited->empty() && !over)
	{
		tmp = visited->top();
		visited->pop();
		while (level <= std::min(old->getLevel(), tmp->getLevel())) {
			tmp->setNext(level, old->getNext(level));
			++level;
		}
		over = old->getLevel() <= tmp->getLevel();

	}


	if (old != _head)
	{
		delete old;
	}

	return _head;
}

template <class T>
void Skiplist<T>::print()
{
	Node<T> *tmp;
	int z = _head->getLevel();

	for (int i = z; i >= 0; i--)
	{
		tmp = _head;
		while (tmp)
		{
			if (tmp->getLevel() >= i) {
				if (tmp != _head) {
					//printf("%d\t", tmp->getData());
					cout << tmp->getData() << "\t";
				}
				else {
					printf("H\t");
				}
			}
			else
			{
				printf("-\t");
			}
			tmp = tmp->getNext();
		}
		printf("\n");
	}

}