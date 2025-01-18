#define _CRT_SECURE_NO_WARNINGS

#include < stdint.h >
#include < memory.h >
#include < stdio.h >
#include < stdbool.h >
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include "arrayLib.h"
#include "matrix.h"

int getDistance(int* a, int n) {
	int x = 0;

	for (size_t i = 0; i < n;i++) {
		x += pow(a[i],2);
	}
	return sqrt(x);
}

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	matrix mat = getMemMatrix(n, m);
	inputMatrix(&mat);

	insertionSortRowsMatrixByRowCriteria(mat, getDistance);

	outputMatrix(mat);

	freeMemMatrix(&mat);
}