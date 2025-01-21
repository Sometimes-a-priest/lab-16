#include < stdint.h >
#include < assert.h >
#include < memory.h >
#include < stdio.h >
#include < stdbool.h >
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include "arrayLib.h"
#include "matrix.h"

matrix getMemMatrix(int nRows, int nCols) {
	int** values = (int**)malloc(sizeof(int*) * nRows);

	for (int i = 0; i < nRows; i++) {
		values[i] = (int*)malloc(sizeof(int) * nCols);
	}
	return (matrix) { values, nRows, nCols };
}

matrix getMemMatrixFullZero(int nRows, int nCols) {
	int** values = (int**)malloc(sizeof(int*) * nRows);

	for (int i = 0; i < nRows; i++) {
		values[i] = (int*)calloc(nCols,sizeof(int));
	}
	return (matrix) { values, nRows, nCols };
}

matrix* getMemArrayOfMatrices(int nMatrices,
	int nRows, int nCols) {
	matrix* ms = (matrix*)malloc(sizeof(matrix) * nMatrices);

	for (int i = 0; i < nMatrices; i++) {
		ms[i] = getMemMatrix(nRows, nCols);
	}
	return ms;
}

void freeMemMatrix(matrix* m) {
	for (size_t i = 0; i < m->nRows;i++) {
		free(m->values[i]);
	}
	free(m->values);
}

void freeMemMatrices(matrix* ms, int nMatrices) {
	for (size_t i = 0;i < nMatrices;i++) {
		freeMemMatrix(ms + i);
	}
	free(ms);
}


void inputMatrix(matrix* m) {
	for (size_t i = 0;i < m->nRows;i++) {
		inputArray(m->values[i],m->nCols);
	}
}

void inputMatrices(matrix* ms, int nMatrices) {
	for (size_t i = 0; i < nMatrices; i++) {
		inputMatrix(ms + i);
	}
}

void outputMatrix(matrix m) {
	printf("\n");
	for (size_t i = 0; i < m.nRows; i++) {
		outputArray(m.values[i], m.nCols);
		printf("\n");
	}
}

void outputMatrices(matrix* ms, int nMatrices) {
	for (size_t i = 0;i < nMatrices; i++) {
		outputMatrix(*(ms + i));
	}
}

void swapRows(matrix m, int i1, int i2) {
	assert(i1 < m.nRows && i2 < m.nRows);

	int *m_copy = *(m.values + i1);
	*(m.values + i1) = *(m.values + i2);
	*(m.values + i2) = m_copy;
}

void swapColumns(matrix m, int j1, int j2) {
	assert(j1 < m.nCols && j2 < m.nCols);

	for (size_t i = 0; i < m.nRows; i++) {
		swapInt(&m.values[i][j1], &m.values[i][j2]);
	}
}

void insertionSortRowsMatrixByRowCriteria(matrix m,
	int (*criteria)(int*, int)) {
	int* a = (int*)malloc(sizeof(int) * m.nRows);

	for (size_t i = 0; i < m.nRows; i++) {
		a[i] = criteria(m.values[i], m.nCols);
	}

	for (size_t i = 1; i < m.nRows; i++) {
		int t = a[i];
		int j = i;
		int* ptr = *(m.values + i);

		while (j > 0 && a[j - 1] > t) {
			a[j] = a[j - 1];
			*(m.values + j) = *(m.values + j - 1);
			j--;
		}
		a[j] = t;
		*(m.values + j) = ptr;
	}
	free(a);
}

void selectionSortColsMatrixByColCriteria(matrix m,
	int (*criteria)(int*, int)) {

	int* a = (int*)malloc(sizeof(int) * m.nRows);
	int* b = (int*)malloc(sizeof(int) * m.nRows);

	for (size_t j = 0; j < m.nRows;j++) {
		for (size_t i = 0;i < m.nCols; i++) {
			a[i] = m.values[i][j];
		}
		b[j] = criteria(a, m.nCols);
	}

	for (int i = 0; i < m.nRows; i++) {
		int minPos = i;

		for (int j = i + 1; j < m.nRows; j++) {
			if (b[j] < b[minPos]) {
				minPos = j;
			}
		}
		swapColumns(m, i,minPos);
		swapInt(&b[i], &b[minPos]);
	}

	free(a);
	free(b);
}

bool isSquareMatrix(matrix* m) {
	return m->nCols == m->nRows;
}

bool areTwoMatricesEqual(matrix* m1, matrix* m2) {
	int x = 1;
	if (m1->nCols != m2->nCols || m1->nRows != m2->nRows) {
		return 0;
	}

	for (size_t i = 0; i < m1->nRows; i++) {
		x &= !memcmp(m1->values[i], m2->values[i], 
			sizeof(int) * m1->nCols);
	}

	return x;
}

bool isEMatrix(matrix* m) {
	if (!isSquareMatrix) {
		return 0;
	}

	for (size_t j = 0; j < m->nRows;j++) {
		for (size_t i = 0; i < m->nRows;i++) {
			if (m->values[j][i] > 1) {
				return 0;
			}
			if (m->values[j][i] > 0 && i != j) {
				return 0;
			}
		}
	}

	return 1;
}

bool isSymmetricMatrix(matrix* m) {
	if (!isSquareMatrix) {
		return 0;
	}

	for (size_t i = 1; i < m->nRows;i++) {
		for (size_t j = 0;j < i;j++) {
			if (m->values[j][i] != m->values[i][j]) {
				return 0;
			}
		}
	}

	return 1;
}

void transposeSquareMatrix(matrix* m) {
	if (!isSquareMatrix) {
		return 0;
	}

	for (size_t i = 1; i < m->nRows;i++) {
		for (size_t j = 0;j < i;j++) {
			swapInt(&m->values[j][i], &m->values[i][j]);
		}
	}
}

void transposeMatrix(matrix* m) {

	int* a = malloc(sizeof(int) * m->nRows);
	matrix b = getMemMatrix(m->nCols, m->nRows);

	for (size_t i = 0; i < m->nCols;i++) {
		for (size_t j = 0; j < m->nRows;j++) {
			a[j] = m->values[j][i];
		}
		memcpy(b.values[i], a, sizeof(int) * m->nRows);
	}

	free(a);

	freeMemMatrix(m);

	(*m) = (b);
}

position getMinValuePos(matrix m) {
	position min;
	min.colIndex = 0;
	min.rowIndex = 0;

	for (size_t i = 0;i < m.nRows;i++) {
		for (size_t j = 0; j < m.nCols;j++) {
			if (m.values[i][j] <
				m.values[min.rowIndex][min.colIndex]) {
				min.rowIndex = i;
				min.colIndex = j;
			}
		}
	}

	return min;
}


position getMaxValuePos(matrix m) {
	position max;
	max.colIndex = 0;
	max.rowIndex = 0;

	for (size_t i = 0;i < m.nRows;i++) {
		for (size_t j = 0; j < m.nCols;j++) {
			if (m.values[i][j] >
				m.values[max.rowIndex][max.colIndex]) {
				max.rowIndex = i;
				max.colIndex = j;
			}
		}
	}

	return max;
}

matrix createMatrixFromArray(const int* a, 
	size_t nRows, size_t nCols) {

	matrix m = getMemMatrix(nRows, nCols);
	int k = 0;

	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCols; j++) {
			m.values[i][j] = a[k++];
		}
	}
	return m;
}

matrix* createArrayOfMatrixFromArray(const int* values,
	size_t nMatrices, size_t nRows, size_t nCols) {
	matrix* ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);
	int l = 0;

	for (size_t k = 0; k < nMatrices; k++) {
		for (size_t i = 0; i < nRows; i++) {
			for (size_t j = 0; j < nCols; j++) {
				ms[k].values[i][j] = values[l++];
			}
		}
	}
	return ms;
}

matrix mulMatrices(matrix m1, matrix m2) {

	assert(m1.nCols == m2.nRows);

	matrix m = getMemMatrixFullZero(m1.nRows, m2.nCols);

	for (size_t l = 0; l < m.nCols;l++) {
		for (size_t j = 0; j < m1.nRows;j++) {
			for (size_t i = 0; i < m1.nCols;i++) {
				m.values[j][l] += (m1.values[j][i] * m2.values[i][l]);
			}
		}
	}

	return m;
}

void getSquareOfMatrixIfSymmetric(matrix* m1) {
	if (!isSymmetricMatrix) {
		return 0;
	}

	matrix m = mulMatrices(*m1, *m1);

	freeMemMatrix(m1);
	(*m1) = (m);
}

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {

	matrix m = mulMatrices(m1, m2);

	int x = isEMatrix(&m);

	freeMemMatrix(&m);

	return x;
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {

	long long int x = 0;

	for (size_t l = 1; l < m.nCols;l++) {
		int max = m.values[0][l];
		for (size_t i = 0, j = l; i < m.nRows && j < m.nCols;i++, j++)
		{
			if (max < m.values[i][j]) {
				max = m.values[i][j];
			}
		}
		x += max;
	}

	for (size_t l = 1; l < m.nRows;l++) {
		int max = m.values[l][0];
		for (size_t i = l, j = 0; i < m.nRows && j < m.nCols;i++, j++)
		{
			if (max < m.values[i][j]) {
				max = m.values[i][j];
			}
		}
		x += max;
	}

	return x;
}

int getMinInArea(matrix m) {
	position p = getMaxValuePos(m);

	size_t j = 0;
	int min = m.values[p.rowIndex][p.colIndex];

	for (int i = p.rowIndex - 1;i >= 0; i--) {
		j++;
		size_t l = p.colIndex - j;

		while (l < m.nCols && l < p.colIndex + j) {
			if (min > m.values[i][l]) {
				min = m.values[i][l];
			}
			l++;
		}
	}

	return min;
}


int countEqClassesByRowsSum(matrix m) {
	long long* a = calloc(m.nRows, sizeof(long long));

	for (size_t i = 0; i < m.nRows;i++) {
		for (size_t j = 0; j < m.nCols;j++) {
			a[i] += m.values[i][j];
		}
	}

	qsort(a, m.nRows, sizeof(long long), cmp_long_long);

	int x = countNUnique(a, m.nRows);
	free(a);

	return x;
}

int getNSpecialElement(matrix m) {
	int special = 0;

	for (size_t i = 0;i < m.nCols;i++) {
		int x = 0;
		int max = m.values[0][i];
		for (size_t j = 0; j < m.nRows;j++) {
			x += m.values[j][i];
			if (max < m.values[j][i]) {
				max = m.values[j][i];
			}
		}
		if (x - max < max) {
			special++;
		}
	}

	return special;
}

void swapPenultimateRow(matrix m) {
	if (m.nRows < 2) {
		return;
	}

	int* a = malloc(sizeof(int) * m.nRows);
	position minP = getMinValuePos(m);

	for (size_t i = 0; i < m.nRows;i++) {
		a[i] = m.values[i][minP.colIndex];
	}

	for (size_t i = 0; i < m.nCols;i++) {
		m.values[m.nRows - 2][i] = a[i];
	}

	free(a);
}

bool hasAllNonDescendingRows(matrix m) {
	int x = 1;

	for (size_t i = 0; i < m.nRows;i++) {
		x &= isNonDescendingSorted(m.values[i], m.nCols);
	}

	return x;
}

int countNonDescendingRowsMatrices(matrix* ms, int nMatrix) {
	int x = 0;

	for (size_t i = 0;i < nMatrix;i++) {
		x += hasAllNonDescendingRows(ms[i]);
	}

	return x;
}

int countZeroRows(matrix m) {
	int x = 0;

	for (size_t i = 0;i < m.nRows;i++) {
		if (getSum(m.values[i], m.nCols) == 0) {
			x++;
		}
	}

	return x;
}

void printMatrixWithMaxZeroRows(matrix* ms, int nMatrix) {

	int maxZero;

	int* a = malloc(sizeof(int) * nMatrix);

	for (size_t i = 0;i < nMatrix;i++) {
		a[i] = countZeroRows(ms[i]);
	}

	maxZero = getMax(a, nMatrix);

	for (size_t i = 0;i < nMatrix;i++) {
		if (a[i] == maxZero) {
			outputMatrix(ms[i]);
		}
	}

	free(a);
}

int getMaxAbsolutInMatrix(matrix m) {
	int max = 0;
	int x;

	for (size_t i = 0;i < m.nRows;i++) {
		x = getAbsolutMax(m.values[i], m.nCols);

		if (x > max) {
			max = x;
		}
	}

	return max;
}

void printMatrixWithMinNormals(matrix* ms, int nMatrix) {
	int* a = malloc(sizeof(int) * nMatrix);
	int min;

	for (size_t i = 0; i < nMatrix;i++) {
		a[i] = getMaxAbsolutInMatrix(ms[i]);
	}

	min = getMin(a, nMatrix);

	for (size_t i = 0;i < nMatrix;i++) {
		if (a[i] == min) {
			outputMatrix(ms[i]);
		}
	}
	free(a);
}