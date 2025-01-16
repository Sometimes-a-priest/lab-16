#include < stdint.h >
#include < memory.h >
#include < stdio.h >
#include < stdbool.h >
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include "arrayLib.h"
#include "matrix.h"

int getMin(int* a, int n) {
	size_t min = 0;
	for (size_t i = 0; i < n;i++) {
		if (a[min] > a[i]) {
			min = i;
		}
	}
	return a[min];
}

int main() {
	matrix m = getMemMatrix(3, 3);
	inputMatrix(&m);

	selectionSortColsMatrixByColCriteria(m, getMin);

	outputMatrix(m);

	freeMemMatrix(&m);
}