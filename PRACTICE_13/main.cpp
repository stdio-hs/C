/**
* 
���ϸ� : PRACTICE_13 

���α׷��� ���� �� �⺻��� : 5*5 ũ���� ��� A, B�� ���� ���� ����

���α׷� �ۼ��� : ������

���α׷� �ۼ����� : 2022�� 03�� 17��

**/

#define SIZE 5 //���簢�� ����� ũ��
#include <stdio.h>

void printMtrx(double M[][SIZE], int size) // ����� ǥ���ϱ� ���� Ȯ�� �ϼ��� �ڵ�
{
	for (int r = 0; r < size; r++)
	{
		for (int c = 0; c < size; c++)
		{
			if (r == 0 && c == 0)
				printf("%c%c  ", 0xa6, 0xa3);
			else if (r == (size - 1) && c == 0)
				printf("%c%c  ", 0xa6, 0xa6);
			else if (c == 0)
				printf("%c%c  ", 0xa6, 0xa2);

			printf("%7.2lf ", M[r][c]);
			if (r == 0 && c == (size - 1))
				printf("%c%c ", 0xa6, 0xa4);
			else if (r == (size - 1) && c == (size - 1))
				printf("%c%c ", 0xa6, 0xa5);
			else if (c == (size - 1))
				printf("%c%c ", 0xa6, 0xa2);
		}
		printf("\n");
	}
	printf("\n");
}


void multiplyMtrx(double A[][SIZE], double B[][SIZE], double E[][SIZE], int size)
{
	for (int r = 0; r < size; r++) // row _ �� _ ����
	{
		for (int c = 0; c < size; c++) // column _ �� _ ����
		{
			E[r][c] = 0; // E = A * B
			for (int k = 0; k < size; k++)
				E[r][c] += A[r][k] * B[k][c];
		}
	}
}


int main()
{
	double A[SIZE][SIZE] = {
	{5,4,3,2,1},
	{6,7,8,9,10},
	{11,12,13,14,15},
	{16,17,18,19,20},
	{21,22,23,24,25} }; // Matrix A ���

	double B[SIZE][SIZE] = {
		{1,0,0,0,0},
		{0,1,0,0,0},
		{0,0,1,0,0},
		{0,0,0,1,0},
		{0,0,0,0,1} }; // Matrix B ���

	double X[SIZE][SIZE]; //�ӽ� ���


	printf("��� A : \n");
	printMtrx(A, SIZE); // printMtrx Ȱ���Ͽ�, A ���

	printf("��� B : \n");
	printMtrx(B, SIZE); // printMtrx Ȱ���Ͽ�, B ���


	printf("��� A * B : \n");
	multiplyMtrx(A, B, X, SIZE);
	printMtrx(X, SIZE); // pritMtrx Ȱ���Ͽ�, A*B �Լ� ȣ���Ͽ�, ���
}
