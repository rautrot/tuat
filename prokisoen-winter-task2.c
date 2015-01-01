 #define _CRT_SECURE_NO_WARNINGS
 #include <stdio.h>
 #include <stdlib.h>
 
 int judge(int[10], int[10]);
 void createh(int[10], int[10]);
 void nexta(int[],int i);
 
 int main()
 {
 	int a[10] = { 6,2,1,0,0,0,1,0,0,0 }, h[10] = { 0 }, index[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
 	//全ての項を足して10になる数字の列を求める
    //h[n](0<n<10)の最大値は10/n つまり半分以降は0か1のみ

        
 	createh(a, h);
 	if (judge(a, h) == 1)
 	{
 		printf("{%d", h[0]);
 		for (int i = 1; i < 10; i++)printf(",%d", h[i]);
 		printf("}\n");
 	}
 	getchar();
 }
 
 int judge(int a[10], int h[10])
 {
 	for (int i = 0; i < 10; i++)
 	{
 		if (a[i] != h[i])return 0; //aとhが同じではない時
 	}
 	return 1; //aとhが同じ時
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
+
+//配列aを次のものにする関数
int nexta(int a[],int i)
{
	int sum=0;
	if(a[i]==(10/a[i]))
        {
        	a[i-1]++;
        	a[i]=0;
        	nexta(a,i-1);
        }
	//a[1]が10になり次第終了
	else if(a[1]==10)return 1;
	for(int j=1;j<10;j++)sum+=a[j];
	a[0]=10-sum;
	return 0;
}
