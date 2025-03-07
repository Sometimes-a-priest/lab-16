#pragma once
#ifndef INC_ARRAYLIB_H
#define INC_ARRAYLIB_H
#include < stddef.h >
#include < stdbool.h >

void swapInt(int* a, int* b);

// ���� ������� ������� n
void inputArray(int* const array, const size_t n);

// ����� ������� ������� n
void outputArray(const int* const array, const size_t n);

size_t lineralSearch(int* array, size_t n, int num);

// ���������� �������� value � ����� ������� data ������� n
void append(int* a, size_t * n, int value);

// ���������� ����� ��� ������
int compareInts(const void* a, const void* b);

// �������� �������� �� ������� (�������������� ������)
void deleteByPosUnsaveOrder(int* a, size_t* n, size_t pos);

// ���������� ������� ��������� �������� x
// � ��������������� ������� a ������� n ��� ��� �������, ����� - SIZE_MAX
size_t binarySearch(const int* a, const size_t n, int x);

// ������� �������� �� ��������� value
// � ������ data ������� n �� ������� pos
void insert(int* a, size_t* n, const size_t pos, const int value);

// ���������� ������� ������� �������� ������� ��� �������� x
// � ��������������� ������� a ������� n
// ��� ���������� ������ �������� ���������� n
size_t binarySearchMoreOrEqual(const int* a, const size_t n, int x);

// �������� �� ������� data ������� n �������� �� ������� pos
// � ����������� ������� ���������� ���������
void deleteByPosSaveOrder(int* a, size_t* n, const size_t pos);

//���������� ���������
void insertionSort(int* a, const size_t size);

// ���������� �������
void selectionSort(int* a, const int size);

// ���������� ����� ��������� �������
long long getSum(int* a, int n);

//���������� "������" ���� � ��������������� 
// ������� ��� ���������� �������� 
bool isUnique(long long* a, size_t n);

//���������� long long ����� ��� ������
int cmp_long_long(const void* pa, const void* pb);

//���������� ���������� ���������� ��������� �������
int countNUnique(long long* a, int n);

//���������� '������' ���� ������ ���������� 
// �� ���������� ���������, ����� - '����'
bool isNonDescendingSorted(int* a, int n);

//���������� ��� ������ ��������� �� �������������
int reversCompareInts(const void* a, const void* b);

// ���������� ������������ �������� �� ������� 
int getMax(const int* a, const size_t n);

// ���������� ������������ ���������� �������� �� ������� 
int getAbsolutMax(const int* a, const size_t n);

//���������� ����������� �������� �� ������� 
int getMin(const int* a, const size_t n);

#endif