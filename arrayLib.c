#define _CRT_SECURE_NO_WARNINGS

#include < stdio.h >
#include < limits.h >
#include < assert.h >
#include < stdbool.h >
#include < math.h >
#include "arrayLib.h"


void swapInt(int* a, int* b) {
	int a_copy = *a;
	*a = *b;
	*b = a_copy;
}

void inputArray(int* const array, const size_t n) {
	for (size_t i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}
}

void outputArray(const int* const array, const size_t n) {
	for (size_t i = 0; i < n; i++) {
		printf("%d ", array[i]);
	}
}

size_t lineralSearch(int* array, const size_t n,int num) {
	for (size_t i = 0; i < n; i++)
		if (array[i] == num) {
			return i;
		}
	return n;
}

void append(int* const a, size_t* const n, const int value) {
	a[*n] = value;
	(*n)++;
}


int compareInts(const void* a, const void* b) {
	int arg1 = *(const int*)a;
	int arg2 = *(const int*)b;

	if (arg1 < arg2) { return -1; }
	if (arg1 > arg2) {return 1;}
	return 0;
}

void deleteByPosUnsaveOrder(int* a, size_t* n, size_t pos) {
	a[pos] = a[*n - 1];
	(*n) --;
}


size_t binarySearch(const int* a, const size_t n, int x) {
	size_t left = 0;
	size_t right = n - 1;

	while (left <= right) {
		size_t middle = left + (right - left) / 2;

		if (a[middle] < x) {
			left = middle + 1;
		}
		else if (a[middle] > x) {
			right = middle - 1;
		}
		else {
			return middle;
		}
	}
	return n;
}


void insert(int* a, size_t* n, const size_t pos, const int value) {
	for (size_t i = *n - 1; i > pos; i--) {
		a[i + 1] = a[i];
	}
	a[pos + 1] = a[pos];
	a[pos] = value;
	(*n)++;
}


size_t binarySearchMoreOrEqual(const int* a, size_t n, int x) {
	if (a[0] >= x) {
		return 0;
	}
	size_t left = 0;
	size_t right = n;

	while (right - left > 1) {
		size_t middle = left + (right - left) / 2;

		if (a[middle] < x) {
			left = middle;
		}
		else {
			right = middle;
		}
	}
	return right;
}


void deleteByPosSaveOrder(int* a, size_t* n, const size_t pos) {
	for (size_t i = pos; i < *n - 1; i++)
		a[i] = a[i + 1];
	(*n) --;
}

void insertionSort(int* a, const size_t size) {
	for (size_t i = 1; i < size; i++) {
		int t = a[i];
		int j = i;
		while (j > 0 && a[j - 1] > t) {
			a[j] = a[j - 1];
			j--;
		}
		a[j] = t;
	}
}

void selectionSort(int* a, const int size) {
	for (int i = 0; i < size - 1; i++) {
		int minPos = i;
		for (int j = i + 1; j < size; j++)
			if (a[j] < a[minPos])
				minPos = j;
		swapInt(&a[i], &a[minPos]);
	}
}

long long getSum(int* a, int n) {
	long long x = 0;

	for (size_t i = 0;i < n;i++) {
		x += a[i];
	}

	return x;
}

bool isUnique(long long* a, size_t n) {

	for (size_t i = 0;i < n - 1;i++) {
		if (a[i] == a[i + 1]) {
			return 0;
		}
	}
	return 1;
}

int cmp_long_long(const void* pa, const void* pb) {
	long long arg1 = *(const long long*)pa;
	long long arg2 = *(const long long*)pb;

	if (arg1 < arg2) { return -1; }
	if (arg1 > arg2) { return 1; }
	return 0;
}

int countNUnique(long long* a, int n) {
	if (n == 0) {
		return 0;
	}
	int x = 1;

	for (size_t i = 0; i < n - 1;i++) {
		if (a[i] != a[i + 1]) {
			x++;
		}
	}

	return x;
}

bool isNonDescendingSorted(int* a, int n) {
	for (size_t i = 0; i < n - 1;i++) {
		if (a[i] > a[i + 1]) {
			return 0;
		}
	}

	return 1;
}

int reversCompareInts(const void* a, const void* b) {
	int arg1 = *(const int*)a;
	int arg2 = *(const int*)b;

	if (arg1 < arg2) { return 1; }
	if (arg1 > arg2) { return -1; }
	return 0;
}


int getMax(const int* a, const size_t n) {
	int max = a[0];
	for (size_t i = 0; i < n;i++) {
		if (max < a[i]) {
			max = a[i];
		}
	}

	return max;
}

int getAbsolutMax(int* a, const size_t n) {
	int max = abs(a[0]);
	for (size_t i = 0; i < n;i++) {
		if (max < abs(a[i])) {
			max = abs(a[i]);
		}
	}

	return max;
}

int getMin(const int* a, const size_t n) {
	int min = a[0];
	for (size_t i = 0; i < n;i++) {
		if (min > a[i]) {
			min = a[i];
		}
	}

	return min;
}