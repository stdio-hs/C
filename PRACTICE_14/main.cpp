/*
파일명 : PRACTICE_14

프로그램의 목적 및 기본기능 : 12 * 12

프로그램 작성자 : 이현성

프로그램 작성일지 : 2022년 3월 21일
*/


#include <stdio.h>
int main()
{
	printf(" >> 12 x 12 곱셈표 <<\n\n");
	printf("     |    1    2    3    4    5    6    7    8    9   10   11   12\n");
	printf(" ----+------------------------------------------------------------\n");
	for (int i = 1; i < 13; i++)
	{
		printf("%4d |", i);
		for (int j = 1; j < 13; j++)
			printf("%5d", i * j);
		printf("\n");
	}
}