#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int judge(int[], int[], int n);
void createh(int[], int[], int n);

int main()
{

	int sum1, sum2, n, index,i,k;
	printf("�v�f������͂��Ă�������:");
	scanf("%d", &n);

	//���Ԍv���p
	clock_t start, end;
	start = clock();

	int *a = (int*)malloc(sizeof(int)*n);
	a[0] = 1; //a[0]��1�ȏ�ł������肦�Ȃ�
	a[n-1] = 0; //a[n]��0�ȊO���肦�Ȃ�

	for (k = 1; k < n-1; k++)a[k] = 0;
	int *h = (int*)malloc(sizeof(int)*n);


	do
	{
		sum1 = 0;
		sum2 = 0;
		index = n - 1;
		for (k = 0; k < n; k++)
		{
			h[k] = 0;
			sum1 += a[k];
			sum2 += a[k] * k;
		}
		if (sum1 == n || sum2 >= n)
		{
			if (sum2 == n)
			{
				createh(a, h, n);

				if (judge(a, h, n) == 1)
				{
					printf("{%d", h[0]);
					for (i = 1; i < n; i++)printf(",%d", h[i]);
					printf("}\n");
				}
			}

			//����ȏ�a[n-2]�𑝂₵�Ă�sum1>n�ƂȂ邽��0�ł͂Ȃ���ԉ��̌����ЂƂグ��
			while (a[index] == 0)index--;
			a[index - 1]++;
			a[index] = 0;
		}
		else{
			a[n - 2]++;
		}


	} while (a[0] != n - 1);

	//���ԕ\��
	end = clock();
	printf("�������ԁF%.4f�b\n", (double)(end - start) / (double)CLOCKS_PER_SEC);

	free(a);
	free(h);

	fflush(stdin);
	getchar();
}

int judge(int a[], int h[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (a[i] != h[i])return 0; //a��h�������ł͂Ȃ���
	}
	return 1; //a��h��������
}

void createh(int a[], int h[], int n)
{
	int i,j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (a[j] == i)h[i]++;
		}
	}
}
