#include<stdio.h>
#include<stdlib.h> 
#include<time.h>

#define n 10 //数组长度

void show(int a[]);
int partition(int a[], int low, int high);
void swap(int *a, int *b);

/* insertSort */
void insertSort(int a[],int k)
{
	int i, j;
	for (i = 1; i < k; i++)
	{
		if (a[i] < a[i - 1])
		{
			int temp = a[i];
			for (j = i - 1; j >= 0 && a[j] > temp; j--)
			{
				a[j + 1] = a[j];
			}
			a[j + 1] = temp;
		}
	}	
}
/* end insertSort */

/* quickSort */
void quickSort(int a[], int low, int high)
{
	if (low < high) {
		int p = partition(a, low, high);
		quickSort(a, low, p - 1);
		quickSort(a, p + 1, high);
	}
}

int partition(int a[], int low, int high)
{
	int pivot_p = high;
	int i = low - 1;
	for (int j = low; j < high; j++) {
		if (a[j] <= a[pivot_p]) {
			i = i + 1;
			if (i < j)
				swap(&a[i], &a[j]);
		}
	}
	if (a[pivot_p] < a[i + 1])
		swap(&a[pivot_p], &a[i + 1]);
	return i + 1;
}
/* end quickSort */

/* swap */
void swap(int *a, int *b)
{
	int c = 0;
	c = *a;
	*a = *b;
	*b = c;
}
/* end swap */

void show(int a[]) 
{
	int i;
	int k = 0;
	k = sizeof(a) / sizeof(a[0]);
	for ( i = 0; i < k; i++)
	{
		printf("%d->", a[i]);
	}
	printf("end");
}

/* main */
int main()
{
	int k = 0;
	int i, j;
	int input = 0;
	int a[n];
	srand((unsigned)time(NULL));//更新随机数
	k = sizeof(a) / sizeof(a[0]);//数组长度

	printf("生成10个随机数:\n");

	for (i = 0; i < k; i++)
	{
		a[i] = rand() % 100;
		printf("%d->", a[i]);
	}
	printf("end\n\n1.直接插入排序\n2.快速排序\n请选择:\n");

	scanf_s("%d",&input);
	switch (input)
	{
	case 1:
		printf("直接插入排序\n");
		insertSort(a, k);
		break;
	case 2:
		printf("快速排序\n");
		quickSort(a, 0, k-1);
		break;
	default:
		break;
	}

	printf("\n排序后:\n");
	for (i = 0; i < k; ++i)
	{
		printf("%d->", a[i]);
	}
	printf("end\n");

	getchar();
	getchar();

	return 0;
}
/* end main */