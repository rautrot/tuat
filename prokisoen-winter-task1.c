#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int[6][8]);
void countNum(char *, int[6][8]);

int main()
{
	int data[6][8], num[6] = { 0 }, first[6] = { 0 },k,i,j;
	char c;
	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 8; j++)data[i][j] = 0;
	}
	while ((c = getchar()) >= 'A' && c <='F')
	{
		for (k = 0; k < 6; k++)
		{
			if (c == ('A' + k))
			{
				if (first['A' + k - 65] == 0)first['A' + k - 65]++;
				else
				{
					if (num['A'+k - 65] > 7)num['A'+k - 65] = 7;
					data['A'+k - 65][num['A'+k - 65]]++;
				}
				num['A' + k - 65] = -1;
			}
		}
		for (k = 0; k < 6; k++)num[k]++;
	}
	printArray(data);
	
	fflush(stdin);
	getchar();
	
	return 0;
}

//配列を表示する関数
void printArray(int data[6][8])
{
	int i,j;
	printf("X: 0 1 2 3 4 5 6 7");
	for (i = 0; i < 6; i++)
	{
		printf("\n%c:", 'A' + i);
		for (j = 0; j < 8; j++)
		{
			printf(" %d", data[i][j]);
		}
	}
}
