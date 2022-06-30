/**
���ϸ�: PRACTICE_09
���α׷��� ���� �� �⺻��� : 16���� �������� 10����, 8����, 2���� ǥ���� Bit-wise ���
���α׷� �ۼ��� : ������
���α׷� �ۼ����� : 2022�� 03�� 10��
**/

#include<stdio.h>
#define BIT_MASK 0x01
#define NUM_BITS_INT 32
enum BinOp_Type { BIT_AND, BIT_OR, BIT_XOR, BIT_SL, BIT_SR, BIT_NOT };
const char* bop_sign[] = { "&", "|", "^", "<<", ">>", "~" };
void  printInt_Bits(int d);

void printIntOper_Bits(BinOp_Type bop, int x, int y, int z) // enum�Լ��� �̿��� 32���� ��� _ ���� ������ �ƴ�, PrintInt_Bit �Լ� Ȱ���Ͽ� ���
{
	if (bop != BIT_NOT) // BIT_NOT �� ��� ����� �ٸ��� ������ IF ``		 ���� Ȱ���Ͽ� BIT_NOT ����,
	{
		printf("    "); printInt_Bits(x); printf("\n");
		printf(" %2s ", bop_sign[bop]); printInt_Bits(y); printf("\n");
		printf(" -----------------------------------------------------------------------\n");
		printf("    "); printInt_Bits(z); printf("\n");

	}
	else // BIT_NOT�� ���� ���
	{
		printf(" %2s ", bop_sign[bop]); printInt_Bits(y); printf("\n");
		printf(" -----------------------------------------------------------------------\n");
		printf("    "); printInt_Bits(z); printf("\n");
	}

}

void printInt_Bits(int d) // ���� ����� �� ���� CODE
{
	unsigned long bit;

	for (int n = (NUM_BITS_INT - 1); n >= 0; n--)
	{
		bit = (d & (BIT_MASK << n)) && 1; // �Է°��� �̵���Ű�� ���� �ƴ�, BIT_MASK �� �̵����� && �Լ� Ȱ��
		printf("%d", bit);

		if ((n % 8) == 0)
			printf(" ");
	}
}

int main()
{
	int x_1, x_2; // 16���� ������ �Է°�
	int c; // calculated _ ��� ��� ��

	printf("Input first hexadecimal numbers in (0x00000 ~ 0xFFFFF) : ");
	scanf_s("%x", &x_1); //16���� ������ �Է°� _ ù��°
	printf(" x_1 = %#010x = ( in decimal ) %#10d = ( in octal ) %o \n   =", x_1, x_1, x_1, x_1);
	printInt_Bits(x_1); printf("\n");
	printf("\n");

	printf("Input second hexadecimal numbers in (0x00000 ~ 0xFFFFF) : ");
	scanf_s("%x", &x_2); //16���� ������ �Է°� _ �ι�°
	printf(" x_2 = %#010x = ( in decimal ) %#10d = ( in octal ) %o \n   =", x_2, x_2, x_2, x_2);
	printInt_Bits(x_2); printf("\n\n");


	c = x_1 & x_2;
	printf("\nBitwise AND : %#010X & %#010X => %#010X\n", x_1, x_2, c);
	printIntOper_Bits(BIT_AND, x_1, x_2, c);

	c = x_1 | x_2;
	printf("\nBitwise OR : %#010X | %#010X => %#010X\n", x_1, x_2, c);
	printIntOper_Bits(BIT_OR, x_1, x_2, c);


	c = x_1 ^ x_2;
	printf("\nBitwise XOR : %#010X ^ %#010X => %#010X\n", x_1, x_2, c);
	printIntOper_Bits(BIT_XOR, x_1, x_2, c);

	c = x_1 << 3;
	printf("\nBitwise Shift Left : %#010X << %#010x => %#010X\n", x_1, 3, c);
	printIntOper_Bits(BIT_SL, x_1, 0x3, c);

	c = x_2 >> 3;
	printf("\nBitwise Shift Right : %#010X >> %#010x => %#010X\n", x_1, 3, c);
	printIntOper_Bits(BIT_SR, x_2, 3, c);

	c = ~x_2;
	printf("\nBitwise NOT : ~ %#010X => %#010X\n", x_2, c);
	printIntOper_Bits(BIT_NOT, x_2, x_2, c);
}