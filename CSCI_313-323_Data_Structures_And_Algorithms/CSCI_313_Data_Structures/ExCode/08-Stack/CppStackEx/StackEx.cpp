#include <stdio.h>
#include <iostream> 
#include <stdlib.h>
#include <algorithm> 
#include <stack>

using namespace std;  

///------------------------------------------------------------------------------------
/// For further reference, see: https://en.cppreference.com/w/cpp/container
///------------------------------------------------------------------------------------
/// Broadly speaking, the containers in C++ are divided into 4 broad categories:
/// 1. Sequence Containers (a.k.a. lists): vector, deque, forward_list, list
/// 2. Associative Containers (a.k.a. balanced trees): set, multiset [Stores just the key values], map, multimap [Stores <key, value> pairs]  
/// 3. Unordered Associative Containers (a.k.a. hash tables): unordered_set, unordered_multiset, unordered_map, unordered_multipmap
/// 4. Container Adapters: stack, queue, priority_queue (a.k.a., binary heap)

int main() {
	cout << "Creating a lifo stack..." << endl;

	stack<int> S;

	cout << "push(4)" << endl;
	S.push(4);

	cout << "push(3)" << endl;
	S.push(3);

	cout << "push(7)" << endl;
	S.push(7);

	cout << "push(1)" << endl;
	S.push(1);

	cout << "push(9)" << endl;
	S.push(9);
	cout << "Number of elements in the stack: " << S.size() << endl;
	cout << "Element at the top of the stack: " << S.top() << endl;
	cout << "Removing the top element of the stack." << endl;
	S.pop();
	cout << "Element at the top of the stack now: " << S.top() << endl;
	cout << "Is the stack empty? " << (S.empty() ? "Yes" : "No") << endl;

	cout << "Removing the stack elements in order: ";
	while (!S.empty()) {
		cout << S.top() << ", ";
		S.pop();
	} //end-while
	cout << endl;
	cout << "Is the stack empty? " << (S.empty() ? "Yes" : "No") << endl;
	cout << "----------------------------------------------------------" << endl;
} // end-Test
