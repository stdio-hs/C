/*

���ϸ� : PL22_HW04_1_21912240_������

���α׷��� ���� �� �⺻��� : (����Լ�&�ݺ���)�������� �ŵ������� ����ϸ� �ɸ� �ð� ����

���α׷� �ۼ��� : ������

���α׷� �ۼ����� : 2022�� 3�� 28��

*/
#include<stdio.h> 
#include<time.h> // �߰������ �� ��
#include<WIndows.h> // �߰������ �� ��

double powerRecur(double base, int exponent); // �ݺ��� ����
double powerIter(double base, int exponent); // ����Լ� ����

int main(void)
{
    time_t t_before, t_after; // ��������, ������ _ ��
    double t_diff; // �ð� ���� 
    LARGE_INTEGER freq, t1, t2; // ����_��������, ����_������ _ �и���
    LONGLONG t_diff_pc; // ����_�ð�����
    
    double t_elapse_ms; // �ð����

    double result_i, result_r;
    double base = 1.015;

    QueryPerformanceFrequency(&freq); // ����
    for (int expo = 1000; expo <= 4000; expo += 1000)
    {
        time(&t_before); // ��������
        QueryPerformanceCounter(&t1); // ����_��������
        result_i = powerIter(base, expo);
        QueryPerformanceCounter(&t2); // ����_������
        time(&t_after); // ������ 
        t_diff = difftime(t_after, t_before); // �ð� ����
        t_diff_pc = t2.QuadPart - t1.QuadPart; // ����_�ð�����
        t_elapse_ms = ((double)t_diff_pc / (double)freq.QuadPart) * 10000; // �ð����
        printf("PowerItera(1.015, %d) by iterative = %40.5lf, took (%3f) sec, (%10.2lf) milli-second\n", expo, result_i, t_diff, t_elapse_ms); // ��, �и���

        time(&t_before);
        QueryPerformanceCounter(&t1);
        result_r = powerRecur(base, expo);
        QueryPerformanceCounter(&t2);
        time(&t_after);
        t_diff = difftime(t_after, t_before);
        t_diff_pc = t2.QuadPart - t1.QuadPart;
        t_elapse_ms = ((double)t_diff_pc / (double)freq.QuadPart) * 10000;
        printf("PowerRecur(1.015, %d) by recursive = %40.5lf, took (%3f) sec, (%10.2lf) milli-second\n", expo, result_r, t_diff, t_elapse_ms);
    }
    return 0;
}

double powerIter(double base, int exponent)
{
    double num = base;
    for (int i = 1; i < exponent; i++)
        num *= base;
    return num;
}
double powerRecur(double base, int exponent)
{
    double num = base;
    if (exponent > 1)
        num *= powerRecur(num, exponent - 1);
    return num;
}
