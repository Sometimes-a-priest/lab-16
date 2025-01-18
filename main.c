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
	matrix m = getMemMatrix(3, 4);
	inputMatrix(&m);

	int x = getMinInArea(m);

	printf("%d", x);

	freeMemMatrix(&m);
}