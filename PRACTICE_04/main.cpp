/**
���ϸ�: PRACTICE_04
���α׷��� ���� �� �⺻��� : �л� ���� �����͸� (10��) �Է� ���� ��, �ִ밪 �ּҰ�, ��հ��� ���ϴ� ���α׷��Դϴ�.
���α׷� �ۼ��� : ������
���α׷� �ۼ����� : 2022�� 03�� 07��
**/

#include <stdio.h>

int main()
{
	int arr[10];
	int i;
	int max, min;
	double sum, average;



	for (i = 0; i < 10; i++)
	{
		printf("%d ��° �л��� ������ �Է��Ͻÿ�. : ", i+1);
		scanf_s("%d", &arr[i]);
	}


	max = 0;
	for (i = 0; i < 10; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	printf("���� ����� ���� : %d\n", max);


	min = 100;
	for (i = 0; i < 10; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	printf("���� ���� ���� : %d\n", min);


	sum = 0;
	for (i = 0; i < 10; i++)
	{
		sum += arr[i];
	}
	average = sum / 10;
	printf("��� ���� : %.lf", average);


	return 0;
}