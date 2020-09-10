#include <iostream>
#include <cstdlib>
using namespace std;

// define default capacity of stack
#define SIZE 100000

// Class for stack
template <class X>
class mystack
{
	X *arr;
	int topS;
	int capacity;

public:
	mystack(int size = SIZE);	// constructor

	void push(X);
	X pop();
	X top();

	int size();
	bool empty();
	bool isFull();

	
};

// Constructor to initialize stack
template <class X>
mystack<X>::mystack(int size)
{
	arr = new X[size];
	capacity = size;
	topS = -1;
}

// function to add an element x in the stack
template <class X>
void mystack<X>::push(X x)
{
	if (isFull())
	{
		
		exit(EXIT_FAILURE);
	}

	
	arr[++topS] = x;
}

// function to pop top element from the stack
template <class X>
X mystack<X>::pop()
{
	// check for stack underflow
	if (empty())
	{
		
		exit(EXIT_FAILURE);
	}

	

	// decrease stack size by 1 and (optionally) return the popped element
	return arr[topS--];
}

// function to return top element in a stack
template <class X>
X mystack<X>::top()
{
	if (!empty())
		return arr[topS];
	else
		exit(EXIT_FAILURE);
}

// Utility function to return the size of the stack
template <class X>
int mystack<X>::size()
{
	return topS + 1;
}

// Utility function to check if the stack is empty or not
template <class X>
bool mystack<X>::empty()
{
	return topS == -1;	// or return size() == 0;
}

// Utility function to check if the stack is full or not
template <class X>
bool mystack<X>::isFull()
{
	return topS == capacity - 1;	// or return size() == capacity;
}

