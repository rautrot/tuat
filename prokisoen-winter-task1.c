#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void printArray(int [6][8]);
void countNum(char *,int [6][8]);

int main()
{
	int data[6][8];
	char *input,str[256];
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)data[i][j] = 0;
	}

	scanf("%s", str);
	input = (char*)malloc(sizeof(char)*(strlen(str) + 1));
	strcpy(input, str);
	countNum(input, data);
	free(input);

	printArray(data);
	return 0;
}

//”z—ñ‚ð•\Ž¦‚·‚éŠÖ”
void printArray(int data[6][8])
{
	printf("X: 0 1 2 3 4 5 6 7");
	for (int i = 0; i < 6; i++)
	{
		printf("\n%c:", 'A' + i);
		for (int j = 0; j < 8; j++)
		{
			printf(" %d", data[i][j]);
		}
	}
}


//Še•¶Žš‚Ì‹——£‚ð‹‚ß‚éŠÖ”
void countNum(char *input,int data[6][8])
{
	int cnt = 0, i = 0,j,len;
	len = strlen(input);
	for (j = 'A'; j <= 'F'; j++,i = 0)
	{
		//ˆêŒÂ–Ú‚Ì•¶Žš‚ðŒ©‚Â‚¯‚é
		while (1)
		{
			if (input[i] == j || input[i] == '\0')break;
			i++;
		}
		for (i++; i < len; i++)
		{
			if (input[i] != j)
			{
				cnt++;
			}
			else
			{
				if (cnt>7)cnt = 7;
				data[j - 'A'][cnt]++;
				cnt = 0;
			}
		}
		cnt = 0;
	}
}