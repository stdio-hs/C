/**

���ϸ�: PRACTICE_11

���α׷��� ���� �� �⺻��� : ASCII code�� �Է¹ް�, �� ASCII code�� ����/����/����/����/��ȣ ���� �Ǻ��ϴ� ���α׷�

���α׷� �ۼ��� : ������

���α׷� �ۼ����� : 2022�� 03�� 22��

**/


#include <stdio.h>
int main()
{
	char ch;


	while (1)
	{
		printf("\nInput a character: ");
		scanf_s(" %c", &ch);
	


		if (ch == '.')
			break;

		else if ('0' <= ch && ch <= '9')
			printf("  => decimal number\n");
		else if ('A' <= ch && ch <= 'Z')
			switch (ch)
			{
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':
				printf("  => alphabet upper-case, vowel\n");
				break;
			default:
				printf("  => alphabet upper-case, consonant\n");
				break;
			}
		else if ('a' <= ch && ch <= 'z')
			switch (ch)
			{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				printf("  => alphabet lower-case, vowel\n");
				break;
			default:
				printf("  => alphabet lower-case, consonant\n");
				break;
			}

		else
		{
			printf("  => symbol (not decimal number, not alphabet\n");
		}
			

		
	}
}
