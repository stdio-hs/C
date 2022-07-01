/*

���ϸ� : PRACTICE_12

���α׷��� ���� �� �⺻��� : (�Է�)�� (�Է�)�� >> Ķ���� ��� �˰���

���α׷� �ۼ��� : ������
 
���α׷� �ۼ����� : 2022�� 3�� 16��

*/

#include <stdio.h>
#include <stdbool.h>
#define WEEKDAY_AD01Jan01 MON // the weekday of AD Jan 1.
#define DAYS_PER_WEEK 7
#define day_1 1
enum WEEKDAY { SUN, MON, TUE, WED, THR, FRI, SAT };
enum MONTH { JAN = 1, FED, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
const char* weekDayName[7] = { "SUN", "MON", "TUE", "WED", "THR", "FRI", "SAT" };
const char* monthName[13] = { "", "January", "February",
"March", "April","May", "June", "July", "August", "September", "October", "November", "December" };


bool isLeapYear(int year) // �������� �ƴ��� ���ϴ� �Լ�.
{
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		return true;
	else
		return false;
}


int getDaysFromJan01AD01(int year, int month, int day) // ���� 1�� 1�� 1�Ϸκ��� �� ��° ������ ���ϴ� �Լ�
{
	int daysInMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int daysFromAD01Jan01 = 0;
	int daysInYear;
	int days = 0;
	for (int y = 1; y < year; y++) // < �Է� ���� ������ > ���⵵������ (�� >> ��) ���.
	{
		daysInYear = isLeapYear(y) ? 366 : 365; // ������ ������ ���ɽ� 366, ������ 365
		days += daysInYear; // days�� �� ��� �� ����
	}
	if (isLeapYear(year)) // < 2. �Է� ���� ���� > ���� �ľ� ��, �׿� ���� (�� >> ��) ���.
		daysInMonth[2] = 29;
	for (int m = 1; m < month; m++)
	{
		days += daysInMonth[m];
	}
	days += day_1;
	daysFromAD01Jan01 = days;

	return daysFromAD01Jan01;
}


void printCalender(int year, int month, int day)
{
	int x; // (�Է°�)�� (�Է°�)�� 1�� _ ���� ���� ����
	int y = 1; // Ķ���� (��) ����� �� �ְ� �����ִ� ����
	int i = 0; // ���Ͽ� ���߾� ����ϱ� ���� ���� �Ѱ� ī��Ʈ
	int daysFromJan01AD01_1 = 0; // < ���� 1�� 1�� 1�� ~~ (�Է°�)�� 1�� 1�� > ���� �ϼ� ���� ����
		int daysInMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // 1~12 ������ �޺� �ϼ�
		daysFromJan01AD01_1 = getDaysFromJan01AD01(year, month, day); // < ���� 1�� 1�� 1��~~(�Է°�)�� 1�� 1�� > ���� �ϼ� �Լ� GET
		x = daysFromJan01AD01_1 % DAYS_PER_WEEK; // < (�Է°�)�� (�Է°�)�� 1�� > �� ���������
		if (isLeapYear(year)) // (�Է°�)���� ������ ��� => 2��(28��) >> 2��(29��)�� ����
			daysInMonth[2] = 29;
	printf(">>>>>>>>>>> %s of %d <<<<<<<<<<<<\n", monthName[month], year); // �Է°�(��) >> ����� ��� _ enum�Լ� Ȱ��
		printf("=====================================\n");
	for (int wk = SUN; wk <= SAT; wk++) // enum�Լ� Ȱ���Ͽ� < ��~�� > ���
	{
		printf("%5s", weekDayName[wk]);
	}
	printf("\n-------------------------------------\n");
	for (i; i < x; i++) // ��¥�� �´� ���Ϻ��� ��½�Ű���� �ϱ�.
	{
		printf("     ");
	}
	for (y; y < daysInMonth[month] + 1; y++) // ��¥ ���
	{
		printf("%3d  ", y);
		if ((y + i) % 7 == 0)
		{
			printf("\n\n");
		}
	}
	printf("\n=====================================\n\n");
}


int main()
{
	int x, y;
	for (;;)
	{
		printf("Input year (0 to quit) and month for print_calenar() : ");
		scanf_s("%d %d", &x, &y);
		if (x == 0)
		{
			break;
		}
		printf("\n");
		printCalender(x, y, day_1);
	}
	return 0;
}