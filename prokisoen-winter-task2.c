#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int judge(int[10], int[10]);
void createh(int[10], int[10]);
int nexta(int[], int i);

int main()
{
	//���Ԍv���p
	clock_t start, end;
	start = clock();


	//a[0]��1�ȏサ�����肦�Ȃ�&&a[9]��0�ȊO����Ȃ�
	int a[10] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, h[10] = { 0 },sum=0;
	
	//�S�Ă̍��𑫂���10�ɂȂ鐔���̗�����߂�
	//h[n](0<n<10)�̍ő�l��10/n �܂蔼���ȍ~��0��1�̂�
	do
	{
		sum = 0;
		for (int k = 0; k < 10; k++)
		{
			h[k] = 0;
			sum += a[k];
		}
		if (sum == 10)
		{
			createh(a, h);

			if (judge(a, h) == 1)
			{
				printf("{%d", h[0]);
				for (int i = 1; i < 10; i++)printf(",%d", h[i]);
				printf("}\n");
			}
		}
		a[8]++;
	} while (nexta(a, 8) != 0);

	//���ԕ\��
	end = clock();
	printf("�������ԁF%d[ms]\n", end - start);


	getchar();
}

int judge(int a[10], int h[10])
{
	for (int i = 0; i < 10; i++)
	{
		if (a[i] != h[i])return 0; //a��h�������ł͂Ȃ���
	}
	return 1; //a��h��������
}

void createh(int a[10], int h[10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (a[j] == i)h[i]++;
		}
	}
}

//�z��a�����̂��̂ɂ���֐�
int nexta(int a[], int i)
{
	//a[0]��10�ɂȂ莟��I��
	if (a[0] == 10)return 0;
	if (i != 0)
	{
		if (a[i] > (10 / i)||a[2]==5||a[5]==2||a[1]==10)
		{
			a[i - 1]++;
			a[i] = 0;
			nexta(a, i - 1);
			return 1;
		}
	}
}
