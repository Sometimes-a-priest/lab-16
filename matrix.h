#pragma once
#ifndef INC_MATRIX_H
#define INC_MATRIX_H

typedef struct matrix {
	int** values; // �������� �������
	int nRows; // ���������� �����
	int nCols; // ���������� ��������
} matrix;

typedef struct position {
	int rowIndex;
	int colIndex;
} position;

// ���������� �������
matrix getMemMatrix(int nRows, int nCols);

// ���������� ������� ���������� ������
matrix getMemMatrixFullZero(int nRows, int nCols);

// ��������� � ������������ ������ ������ 
// �� nMatrices ������ �������� nRows �� nCols
matrix* getMemArrayOfMatrices(int nMatrices,
	int nRows, int nCols);

// ����������� ������, ���������� ���
// �������� ������� m
void freeMemMatrix(matrix* m);

// ����������� ������, ���������� ��� 
// �������� ������� ms �� nMatrices ������
void freeMemMatrices(matrix* ms, int nMatrices);

// ���� ������� m
void inputMatrix(matrix* m);

// ���� ������� �� nMatrices ������, 
// ���������� �� ������ ms
void inputMatrices(matrix* ms, int nMatrices);

//����� ������� m
void outputMatrix(matrix m);

//����� ������� �� nMatrices ������, 
// ���������� �� ������ ms.
void outputMatrices(matrix* ms, int nMatrices);

// ����� ����� � ����������� 
// �������� i1 � i2 � ������� m
void swapRows(matrix m, int i1, int i2);

//����� ������� � ����������� �������� j1 � j2 � ������� m
void swapColumns(matrix m, int j1, int j2);

//��������� ���������� ��������� ����� ������� m 
// �� ���������� �������� ������� 
// criteria ����������� ��� �����
void insertionSortRowsMatrixByRowCriteria(matrix m,
	int (*criteria)(int*, int));

// ��������� ���������� ������� �������� 
// ������� m �� ���������� �������� ������� 
// criteria ����������� ��� ��������
void selectionSortColsMatrixByColCriteria(matrix m,
	int (*criteria)(int*, int));

// ���������� �������� ��������, ���� ������� m 
// �������� ����������, ���� � � ��������� ������
bool isSquareMatrix(matrix* m);

//���������� �������� ��������, ���� ������� m1 � m2 �����, 
// ���� � � ��������� ������
bool areTwoMatricesEqual(matrix* m1, matrix* m2);

//���������� �������� ��������, ���� ������� m �������� ���������, 
// ���� � � ��������� ������
bool isEMatrix(matrix* m);

//���������� �������� ��������, ���� ������� m �������� ������������, 
// ���� � � ��������� ������
bool isSymmetricMatrix(matrix* m);

// ������������� ���������� ������� m
void transposeSquareMatrix(matrix* m);

// ������������� ������� m
void transposeMatrix(matrix* m);

//���������� ������� ������������ �������� ������� m
position getMinValuePos(matrix m);

//���������� ������� ������������� �������� ������� m
position getMaxValuePos(matrix m);

//���������� ������� ������� nRows �� nCols, 
// ����������� �� ��������� ������� a
matrix createMatrixFromArray(const int* a,
	size_t nRows, size_t nCols);

//���������� ��������� �� ������� ������� ������� �� nMatrices ������,
//����������� � ������������ ������, ����������� �� ��������� ������� a
matrix* createArrayOfMatrixFromArray(const int* values,
	size_t nMatrices, size_t nRows, size_t nCols);

// ���������� ������������ ������ m1 � m2
matrix mulMatrices(matrix m1, matrix m2);

// ���� ������ ���������� ������� A �����������, �� �������� A �� ��������� 
void getSquareOfMatrixIfSymmetric(matrix* m1);

// ���������� '������' ���� ������� �������� �� ��� ������� ���������
bool isMutuallyInverseMatrices(matrix m1, matrix m2);

//���������� ����� ������������ ��������� ���� ���������������� �������
long long findSumOfMaxesOfPseudoDiagonal(matrix m);


int getMinInArea(matrix m);


int countEqClassesByRowsSum(matrix m);

// ���������� ���������� "������" ��������� �������
int getNSpecialElement(matrix m);

// �������� ������������� ������ ������� ������ �� ��������, 
// � ������� ��������� ����������� ������� �������
void swapPenultimateRow(matrix m);

//���������� '������' ���� ������ ������� ����������� �� 
// ���������� ���������, ����� - '����'
bool hasAllNonDescendingRows(matrix m);

//���������� ����� ������, 
// ������ ������� ����������� �� ���������� ��������� 
int countNonDescendingRowsMatrices(matrix* ms, int nMatrix);

//���������� ���������� ������� ����� � �������
int countZeroRows(matrix m);

//������� �������, ������� ���������� ����� ������� �����
void printMatrixWithMaxZeroRows(matrix* ms, int nMatrix);

//���������� ������������ ���������� �������� �� ������� m
int getMaxAbsolutInMatrix(matrix m);

//������� ������� � ���������� ������
void printMatrixWithMinNormals(matrix* ms, int nMatrix);
#endif
