// THU range.cpp : 定義主控台應用程式的進入點。
#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int compare(const void *a, const void *b) {
	int *pa = (int*)a;
	int *pb = (int*)b;

	return (*pa) - (*pb);
}

/*
int search(int* data, int n, int a, int b) {
	int front, back;
	bool foundA = false;

	for (int i = 0; i < n; i++) {
		//cout << data[i] << (a <= data[i])<<endl;
		if (!foundA && a <= data[i]) {
			front = i;
			foundA = true;
		}
		if (b < data[i]) {
			back = i;
			return back - front;
		}
		else if (b == data[i]) {
			back = i+1;
			return back - front;
		}
	}
	if (foundA) {
		return n - front;
	}
	else {
		return 0; 
	}
}
*/

int binSearchF(int* data, int e, int lo, int hi) {
	while (lo < hi) {
		int mi = (lo + hi) >> 1;
		if (e < data[mi]) hi = mi;
		else if (data[mi] < e) lo = mi + 1;
		else return mi;// == 
	}
	return lo;
}

int binSearchB(int* data, int e, int lo, int hi) {
	while (lo < hi) {
		int mi = (lo + hi) >> 1;
		if (e < data[mi]) hi = mi;
		else if (data[mi] < e) lo = mi + 1;
		else return mi+1;// == 
	}
	return lo;
}


int main()
{
	int a, b, n, m;
	scanf("%d %d\n", &n, &m);
	int* data = new int[n];
	int* result = new int[m];

	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
	}

	qsort(data, n, sizeof(int), compare);

	int temp = m;
	while (temp--) {
		cin >> a >> b;
		result[temp] = binSearchB(data, b, 0, n) - binSearchF(data, a, 0, n);
	}
	for (int i = m - 1; i >= 0; i--) {
		printf("%d\n", result[i]);
	}

	return 0;
}




