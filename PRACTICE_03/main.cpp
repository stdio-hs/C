/**
���ϸ�: PRACTICE_03
���α׷��� ���� �� �⺻��� : ������� (������/����)�� �Է�, ������� (����/�ѳ���) ��� 
���α׷� �ۼ��� : ������
���α׷� �ۼ����� : 2022�� 03�� 07��
**/

#include <stdio.h>
#define PI 3.14

int main()
{
	int r, h; // radius������ height����
	double v, sa; // volume���� surface area�ѳ���

	printf("������� �������� �Է��Ͻÿ� : ");
	scanf_s("%d", &r);
	printf("������� ���̸� �Է��Ͻÿ� : ");
	scanf_s("%d", &h);

	v = r * r * PI * h; // ����
	sa = (2 * r * r * PI) + (2 * PI * r * h); // �ѳ���

	printf("������� ���Ǵ� %.2lf �Դϴ�.\n", v);
	printf("������� �ѳ��̴� %.2lf �Դϴ�.", sa);

	return 0;
}

