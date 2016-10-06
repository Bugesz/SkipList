#include <iostream>
#include "Skiplist.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <queue>

using namespace std;

typedef int Val_TYPE;
typedef vector<Val_TYPE> Container_TYPE;
typedef priority_queue<Val_TYPE, Container_TYPE> pri_queue;

class Queue : public pri_queue {
public:
	Container_TYPE::iterator begin() {
		return pri_queue::c.begin();
	}
	Container_TYPE::iterator end() {
		return pri_queue::c.end();
	}
}Q;

///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////

struct node
{
	int key_value;
	node *left;
	node *right;
};

class btree
{
public:
	btree();
	~btree() {
		destroy_tree();
	}

	void insert(int key);
	node *search(int key);
	void destroy_tree();

private:
	void destroy_tree(node *leaf);
	void insert(int key, node *leaf);
	node *search(int key, node *leaf);

	node *root;
};

btree::btree()
{
	root = NULL;
}

void btree::destroy_tree(node *leaf)
{
	if (leaf != NULL)
	{
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void btree::insert(int key, node *leaf)
{
	if (key< leaf->key_value)
	{
		if (leaf->left != NULL)
			insert(key, leaf->left);
		else
		{
			leaf->left = new node;
			leaf->left->key_value = key;
			leaf->left->left = NULL;    //Sets the left child of the child node to null
			leaf->left->right = NULL;   //Sets the right child of the child node to null
		}
	}
	else if (key >= leaf->key_value)
	{
		if (leaf->right != NULL)
			insert(key, leaf->right);
		else
		{
			leaf->right = new node;
			leaf->right->key_value = key;
			leaf->right->left = NULL;  //Sets the left child of the child node to null
			leaf->right->right = NULL; //Sets the right child of the child node to null
		}
	}
}

node *btree::search(int key, node *leaf)
{
	if (leaf != NULL)
	{
		if (key == leaf->key_value)
			return leaf;
		if (key<leaf->key_value)
			return search(key, leaf->left);
		else
			return search(key, leaf->right);
	}
	else return NULL;
}

void btree::insert(int key)
{
	if (root != NULL)
		insert(key, root);
	else
	{
		root = new node;
		root->key_value = key;
		root->left = NULL;
		root->right = NULL;
	}
}

node *btree::search(int key)
{
	return search(key, root);
}

void btree::destroy_tree()
{
	destroy_tree(root);
}

///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////

int main()
{

	Skiplist<double> tmp;
	btree tree;

	srand(12);


	clock_t begin;
	//int SIZE = 1000000;
	int SIZE = 10;
	begin = clock();
	for (int i = 0; i < SIZE; i++) {
		tmp.insert(rand());
	}
	


	if (SIZE <= 10) {

		tmp.insert(5);
		tmp.search(5);
		tmp.print();
		printf("Press ENTER to leave...\n");
		getchar();
		return 0;
	}
	cout << "Running time in seconds: \t" << double(clock() - begin) / CLOCKS_PER_SEC << endl;

	begin = clock();
	for (int i = 0; i < SIZE; i++) {
		tmp.search(rand());
	}
	cout << "Running time in seconds: \t" << double(clock() - begin) / CLOCKS_PER_SEC << endl;

	
	begin = clock();
	for (int i = 0; i < SIZE; i++) {
		tmp.remove(rand());
	}
	cout << "Running time in seconds: \t" << double(clock() - begin) / CLOCKS_PER_SEC << endl;
	

	cout << endl;

	begin = clock();
	for (int i = 0; i < SIZE; i++) {
		tree.insert(rand());
	}
	cout << "Running time in seconds: \t" << double(clock() - begin) / CLOCKS_PER_SEC << endl;

	begin = clock();
	for (int i = 0; i < SIZE; i++) {
		tree.search(rand());
	}
	cout << "Running time in seconds: \t" << double(clock() - begin) / CLOCKS_PER_SEC << endl;


	cout << endl;
	getchar();
	return 0;

	begin = clock();
	for (int i = 0; i < SIZE; i++) {
		Q.push(rand());
	}
	cout << "Running time in seconds: \t" << double(clock() - begin) / CLOCKS_PER_SEC << endl;

	
	begin = clock();
	for (int i = 0; i < SIZE; i++) {
		int z = rand();
		for (vector<int>::iterator p = Q.begin(); p != Q.end(); p++)
		{
			if (*p == z) {
				break;
			}
		}
	}
	cout << "Running time in seconds: \t" << double(clock() - begin) / CLOCKS_PER_SEC << endl;
	cout << endl << endl;
	


	
	getchar();
	return 0;
}