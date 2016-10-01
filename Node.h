class Node {
	int _level;
	int _data;

	Node* _next[30];

public:

	// Constructor
	Node(int data);

	// Destructor
	~Node();

	// Getters
	int getData() {
		return _data;
	}

	int getLevel() {
		return _level;
	}

	Node *getNext(int level = 0) {
		return _next[level];
	}

	// Setters
	void setNext(int level, Node* obj) {
		_next[level] = obj;
	}

	void incLevel();
	void incLevel(Node* obj);

	// Comparsion operators
	bool operator ==(const int data) {
		return _data == data;
	}

	bool operator <=(const int data) {
		return _data <= data;
	}

	bool operator !=(const int data) {
		return _data != data;
	}
};