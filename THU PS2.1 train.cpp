// THU PS2.1 train.cpp : 定義主控台應用程式的進入點。

//#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

template <typename T> // dont use <class T>
class Stack {
	int _size = 0;
	int _capacity;
	T* _element;

public:
	// constructor
	Stack(int c = 0, T v = 0);
	//functions
	int size();
	bool empty();
	T top();
	T pop();
	void push(T const& e);
};

template <typename T> Stack<T>::Stack(int c, T v) {
	_capacity = c;

	_element = new T[_capacity];
	for (int i = 0; i < _capacity; i++) {
		_element[i] = v;
	}
}

template <typename T> int Stack<T>::size() { return _size; }
template <typename T> bool Stack<T>::empty() { return _size == 0; }
template <typename T> T Stack<T>::top() { return empty() ? -1 : _element[_size - 1]; }
template <typename T> T Stack<T>::pop() { return _element[--_size]; }
template <typename T> void Stack<T>::push(T const& e) { 
	_element[_size++] = e; 
}

int main()
{	
	int n, m, k, temp;

	scanf("%d %d", &n, &m);
	Stack<int> A(n, 0), B(n, 0), S(m, 0);
	Stack<string> ans(2*n, string());

	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		B.push(temp);
	}

	if (m == 0) {
		printf("%s\n", string("No").c_str());
		return 0;
	}

	for (int target = n; 0 < target; target--) {
		if (!S.empty() && S.top() == target) {
			A.push(S.pop());
			ans.push({ "push" });

		}else {
			do {
				if (B.empty()) {
					printf("%s", string("No").c_str());
					return 0; // can't continue
				}
				k = B.pop();
				ans.push({ "pop" });

				if (S.size() == m) {
					printf("%s", string("No").c_str());
					return 0;
				} // can't continue

				if (target == k) {
					// omit S.push(k) & S.pop operations; so still need to check if S is full beforehand
					A.push(k);
					ans.push({ "push" });
				}
				else {
					S.push(k);
				}
			} while (target != k);
		}
	}

	for (int i = 0; i < 2*n; i++) {
		printf("%s\n", ans.pop().c_str());
	}
    return 0;
}

