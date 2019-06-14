#include<stdio.h>
#include<stdlib.h> 
#include<time.h>

#define n 10000 //数组长度

void show(int a[]);
int partition(int a[], int low, int high);
void swap(int *a, int *b);

/* insertSort */
void insertSort(int a[])
{
	int i, j;
	for (i = 1; i < n; i++)
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
	for (i = 0; i < k; i++)
	{
		printf("%d->", a[i]);
	}
	printf("end");
}

/* main */
int main()
{
	//int k = 0;
	int i, j;
	int input = 0;
	int a[n];
	double start, end, s;
	srand((unsigned)time(NULL));//更新随机数

	printf("生成%d个随机数:\n",n);
	for (i = 0; i < n; i++)
	{
		a[i] = rand();
	}

	printf("\n1.直接插入排序\n2.快速排序\n请选择:\n");
	scanf_s("%d", &input);
	switch (input)
	{
	case 1:
		printf("直接插入排序");
		start = clock();
		insertSort(a);
		end = clock();
		break;
	case 2:
		printf("快速排序\n");
		start = clock();
		quickSort(a, 0, n - 1);
		end = clock();
		break;
	default:
		break;
	}

	printf("\n花费时间：%f", (double)(end - start) /CLOCKS_PER_SEC);

	s = (rand() % 1000 / 1.0) / (rand() % 100 / 1.0);
	printf("\n%f", s);

	getchar();
	getchar();
	return 0;
}
/* end main */