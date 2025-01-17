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
	matrix m = getMemMatrix(2, 2);
	inputMatrix(&m);

	matrix m1 = getMemMatrix(2, 2);
	inputMatrix(&m1);

	int x = isMutuallyInverseMatrices(m, m1);

	printf("%d", x);

	freeMemMatrix(&m);
	freeMemMatrix(&m1);
}