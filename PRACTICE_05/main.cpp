/**
���ϸ�: PRACTICE_05
���α׷��� ���� �� �⺻��� : �ʴ����� �Էµ� ���� ��,��,�ʷ� ȯ���ϴ� ���α׷�
���α׷� �ۼ��� : ������
���α׷� �ۼ����� : 2022�� 03�� 09��
**/

#include <stdio.h>

int main()
{
	int x_1, x_2, x_3; // input second, input second - time, input second - time - minute
	int t, m, s; // output _ time, minute, second

	printf("<<< �ʴ����� �Էµ� ���� ��,��,�ʷ� ȯ�����ִ� ���α׷��Դϴ�. >>\n\n");
	printf("�ʴ����� ���ڸ� �Է��Ͻÿ�. : ");
	scanf_s("%d", &x_1); // �����Է� (�ʴ���)

	t = x_1 / 3600; // �� ���
	x_2 = x_1 - t * 3600; // �Է°�(��) - ��(��) 
	
	m = x_2 / 60; // �� ���
	x_3 = x_2 - m * 60; // �Է°�(��) - ��(��) - ��(��)

	s = x_3;

	printf("[ %d sec = %d�ð� %d�� %d�� �Դϴ�. ]\n",x_1, t, m, s);

	return 0;
}

