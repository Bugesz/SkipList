#include <iostream>
#include "Skiplist.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <queue>
#include "avl.h"

using namespace std;


int main()
{

	Skiplist<int> tmp(50, 0.65);
	AVL tree;

	clock_t begin;

	int SIZE = 1000000;
	
	//SIZE = 16;

	begin = clock();
	for (int i = 0; i < SIZE; i++) {
		tmp.insert(rand()%SIZE);
	}
	
	if (SIZE <= 15) {
		tmp.insert(5);
		tmp.search(5);
		tmp.print();
		printf("Press ENTER to leave...\n");
		getchar();
		return 0;
	}

	cout << "Building..." << endl;
	cout << "Running time in seconds: \t" << double(clock() - begin) / CLOCKS_PER_SEC << "s" <<endl;


	begin = clock();
	for (int i = 0; i < SIZE; i++) {
		tmp.search(rand()%SIZE);
	}
	cout << "Searching..." << endl;
	cout << "Running time in seconds: \t" << double(clock() - begin) / CLOCKS_PER_SEC << "s" <<endl;

	
	begin = clock();
	for (int i = 0; i < SIZE; i++) {
		tmp.remove(rand()%SIZE);
	}
	cout << "Removing..." << endl;
	cout << "Running time in seconds: \t" << double(clock() - begin) / CLOCKS_PER_SEC << "s" <<endl;
	

	cout << endl;

	begin = clock();
	for (int i = 0; i < SIZE; i++) {
		tree.insert(rand()%SIZE);
	}
	cout << "Tree insert..." << endl;
	cout << "Running time in seconds: \t" << double(clock() - begin) / CLOCKS_PER_SEC << "s" <<endl;

	begin = clock();
	for (int i = 0; i < SIZE; i++) {
		tree.search(rand()%SIZE);
	}
	cout << "Tree search..." << endl;
	cout << "Running time in seconds: \t" << double(clock() - begin) / CLOCKS_PER_SEC << "s" <<endl;

	begin = clock();
	for (int i = 0; i < SIZE; i++) {
		tree.remove(rand()%SIZE);
	}
	cout << "Tree remove..." << endl;
	cout << "Running time in seconds: \t" << double(clock() - begin) / CLOCKS_PER_SEC << "s" <<endl;


	cout << endl;
	return 0;
}