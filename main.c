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

int main() {
	matrix *mat = getMemArrayOfMatrices(4, 2, 2);

	inputMatrices(mat, 4);

	int x = countNonDescendingRowsMatrices(mat, 4);

	printf("%d", x);

	freeMemMatrices(mat, 4);
}