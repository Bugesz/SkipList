#include <iostream>
#include "Skiplist.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctime>

using namespace std;

int main()
{

	Skiplist tmp;

	srand(time(NULL));

	for (int i = 0; i < 15; i++) {
		tmp.insert(rand() % 10);
	}


	cout << "Meplau!" << endl;

	cout << endl << endl;
	tmp.print();
	
	getchar();
	return 0;
}