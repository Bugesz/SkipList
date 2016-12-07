#include <stdlib.h>

template <class T>
class Node {

	unsigned short _level;
	
	T _data;

	Node<T>* _next[50];

public:

	// Constructor
	Node<T>(T data, unsigned int max_level, double prob);

	// Destructor
	~Node<T>();

	// Getters
	T getData() {
		return _data;
	}

	unsigned short getLevel() {
		return _level;
	}

	Node<T>* getNext(unsigned short level = 0) {
		return _next[level];
	}

	// Setters
	void setNext(int level, Node<T>* obj) {
		_next[level] = obj;
	}

	void incLevel();
	void incLevel(Node* obj);

	// Comparsion operators
	bool operator ==(const T data) {
		return _data == data;
	}

	bool operator !=(const T data) {
		return _data != data;
	}

	bool operator <=(const T data) {
		return _data <= data;
	}

	bool operator >=(const T data) {
		return _data >= data;
	}

	bool operator  <(const T data) {
		return _data < data;
	}

	bool operator  >(const T data) {
		return _data > data;
	}
};

template <class T>
Node<T>::Node(T data, unsigned int max_level, double prob) {
	_data = data;
	_level = -1;
	do
	{
		_next[++_level] = NULL;
		//printf("%d\n", _level);
	} while (((double)rand() / (RAND_MAX)) < prob && _level <= max_level);

}

template <class T>
Node<T>::~Node()
{
}

template <class T>
void Node<T>::incLevel()
{
	_next[++_level] = NULL;
}

template <class T>
void Node<T>::incLevel(Node<T>* obj)
{
	_next[++_level] = obj;
}