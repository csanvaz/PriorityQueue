// Priority Queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "priorityqueue.h"
#include <set>
#include <map>
#include <sstream>



int main()
{
	priorityqueue <string> test;
	//priorityqueue <int> test;
	//priorityqueue <double> test;
	priorityqueue <string> test2;
	int priority = 0;
	string names;
	/*
	test.enqueue("Dolores", 5);
	test.enqueue("Bernard", 4);
	test.enqueue("Ford", 2);
	test.enqueue("Arnold", 8);
	test.enqueue("Jasmine", 6);
	test.enqueue("Carlos", 11);*/


	/*test2.enqueue("James", 3);
	test2.enqueue("Mack", 2);
	test2.enqueue("Julie", 1);
	test2.enqueue("Jose", 9);
	test2.enqueue("Dusty", 7);
	test2.enqueue("Abby", 5);*/

	/*
	test2.enqueue("James", 3);
	test2.enqueue("Mack", 2);
	test2.enqueue("Julie", 1);
	test2.enqueue("Jose", 9);
	test2.enqueue("Dusty", 7);
	test2.enqueue("Abby", 5);
	test2.enqueue("Angie", 6);
	test2.enqueue("Logan", 4);*/

	/*
	test.enqueue(10, 5);
	test.enqueue(20, 4);
	test.enqueue(22, 2);
	test.enqueue(25, 8);
	test.enqueue(27, 6);
	test.enqueue(28, 11);
	*/

	/*
	test.enqueue(10.0, 5);
	test.enqueue(11.0, 4);
	test.enqueue(7.0, 2);
	test.enqueue(5.0, 8);
	test.enqueue(4.0, 6);
	test.enqueue(5.0, 11);*/


	
	test.enqueue("Dolores", 5);
	test.enqueue("Bernard", 4);
	test.enqueue("Ford", 2);
	test.enqueue("Arnold", 8);
	test.enqueue("Jasmine", 6);
	test.enqueue("Carlos", 11);
	test.enqueue("William", 8);
	test.enqueue("Teddy", 8);
	
	
	cout << "Testing Size:" << endl;
	cout << "Test 1: " << test.Size() << endl;
	//cout << "Test 2: " << test2.Size() << endl;
	cout << endl;
	//Testing toString Function
	cout << "Output of Test 1" << endl;
	cout << test.toString() << endl;
	//cout << test2.toString() << endl;

	//Testing Dequeue Function
	cout << "Testing Dequeue: " << endl;
	test.dequeue();
	cout << test.peek() << endl;
	test.dequeue();
	cout << test.peek() << endl;
	test.dequeue();
	cout << test.peek() << endl;
	test.dequeue();
	cout << test.peek() << endl;
	test.dequeue();
	cout << test.peek() << endl;
	test.dequeue();
	cout << test.peek() << endl;
	test.dequeue();
	cout << test.peek() << endl;
	test.dequeue();
	
	

	


	//Testing peek function
	//cout << test.peek();
	//cout << test.peek();
	//cout << test.peek();

	//Testing Equal operator
	//test2.operator=(test);
	

	//Testing Begin and Next Functions
	/*test.begin();

	
    while (test.next(names, priority)) {
	    cout << priority << " value: " << names << endl;
	}*/

	
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
