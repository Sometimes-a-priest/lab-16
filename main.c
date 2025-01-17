#include < stdint.h >
#include < memory.h >
#include < stdio.h >
#include < stdbool.h >
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include "arrayLib.h"
#include "matrix.h"


int main() {
	matrix m = getMemMatrix(3, 3);
	inputMatrix(&m);

	long long int* array = malloc(sizeof(long long int) * m.nRows);

	for (size_t i = 0;i < m.nRows;i++) {
		array[i] = getSum(m.values[i], m.nCols);
	}

	qsort(array, m.nRows, sizeof(long long int), compareInts);

	if (isUnique(array, m.nRows)) {
		transposeMatrix(&m);
	}

	free(array);
	outputMatrix(m);
	freeMemMatrix(&m);
}