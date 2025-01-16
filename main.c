#include < stdint.h >
#include < memory.h >
#include < stdio.h >
#include < stdbool.h >
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include "arrayLib.h"
#include "matrix.h"

int getMax(int* a, int n) {
	size_t max = 0;
	for (size_t i = 0; i < n;i++) {
		if (a[max] < a[i]) {
			max = i;
		}
	}
	return a[max];
}
int main() {
	matrix m = getMemMatrix(3, 3);
	inputMatrix(&m);

	insertionSortRowsMatrixByRowCriteria(m, getMax);

	outputMatrix(m);

	freeMemMatrix(&m);
}