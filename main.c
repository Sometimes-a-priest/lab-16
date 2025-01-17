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

	getSquareOfMatrixIfSymmetric(&m);

	outputMatrix(m);

	freeMemMatrix(&m);
}