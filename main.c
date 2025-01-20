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

	int n, m;
	scanf("%d %d", &n, &m);

	matrix mat = getMemMatrix(n, m);
	inputMatrix(&mat);

	int x = getNSpecialElement(mat);

	printf("%d", x);

	outputMatrix(mat);

	freeMemMatrix(&mat);
}