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
	matrix m = getMemMatrix(4, 3);
	inputMatrix(&m);

	long long int x = findSumOfMaxesOfPseudoDiagonal(m);

	printf("%lld", x);

	freeMemMatrix(&m);
}