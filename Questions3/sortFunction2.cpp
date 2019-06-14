#include"headerFile2.h"
#include"defineFile2.h"

using namespace std;
void OutputOneSubsetBinary();
void OutputOneSubset();
void Subsetting(int subtree_n);
static vector<int> subtree_s;

/* swap */
void swap(int *a, int *b)
{
	int c = 0;
	c = *a;
	*a = *b;
	*b = c;
}
/* end swap */

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

void quickSort(int a[], int low, int high)
{
	if (low < high) {
		int p = partition(a, low, high);
		quickSort(a, low, p - 1);
		quickSort(a, p + 1, high);
	}
}
/* end quickSort */

/* merge  */
void TwoWayMerge(int a[], int p, int q, int r)
{
	int *b = new int[r + 1];
	int i = p, j = q + 1, k = p;
	while (i <= q && j <= r) {
		if (a[i] <= a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}
	if (i == q + 1)
		for (; j <= r; j++)
			b[k++] = a[j];
	else
		for (; i <= q; i++)
			b[k++] = a[i];
	for (i = p; i <= r; i++)
		a[i] = b[i];
	delete b;
}

void MergeSort(int a[], int low, int high)
{
	if (low < high) {
		int mid = (low + high) / 2;
		MergeSort(a, low, mid);
		MergeSort(a, mid + 1, high);
		TwoWayMerge(a, low, mid, high);
	}
}
/*   end  merge  */



/*  HeapSort  */
void SiftDown(int H[], int m, int k)
{
	bool done = false;
	while (!done && (k = 2 * k + 1) < m) {
		if (k + 1 < m && H[k + 1] > H[k])
			k++;
		if (H[(k - 1) / 2] < H[k])
			swap(&H[(k - 1) / 2], &H[k]);
		else done = true;
	}
}
void Heapify(int H[], int m)
{
	for (int j = m / 2 - 1; j >= 0; j--) {
		SiftDown(H, m, j);
	}
}
void HeapSort(int H[], int m)
{
	Heapify(H, m);
	for (int i = m - 1; i > 0; i--) {
		swap(&H[0], &H[i]);
		SiftDown(H, i, 0);
	}
}
/*  end Heapsort  */


/*------------*/
/*-- 子集树 --*/
/*------------*/
void Subsetting(int subtree)
{
	if (subtree > 0) {
		subtree_s.push_back(0);
		Subsetting(subtree - 1);
		subtree_s.pop_back();
		subtree_s.push_back(1);
		Subsetting(subtree - 1);
		subtree_s.pop_back();
	}
	else {
		OutputOneSubsetBinary();
		OutputOneSubset();
		printf("\n");
	}
}
static void OutputOneSubsetBinary()
{
	static int cnt = 0;
	printf("%03d: ", ++cnt);
	for (int i = subtree_s.size() - 1; i >= 0; i--)
		printf("%d", subtree_s[i]);
}
static void OutputOneSubset()
{
	printf("; {");
	int k = 0;
	for (int i = subtree_s.size() - 1; i >= 0; i--) {
		if (subtree_s[i] == 1) {
			if (k > 0)
				printf(",");
			printf("%d", subtree_s.size() - i);
			k++;
		}
	}
	printf("}");
}


/*---- sortmain ----*/
/*--- 排序主函数 ---*/
/*---- sortmain ----*/
void SortMain() 
{
	int i, j;
	int input = 1;
	int a[n];
	double start, end;
	srand((unsigned)time(NULL));//更新随机数

	start = 0;
	end = 0;

	while (input)
	{
		//生成随机数组
		for (i = 0; i < n; i++)
		{
			a[i] = rand();
		}

		//选择执行操作
		printf("1.直接插入排序\n2.快速排序\n3.归并排序\n4.堆排序\n0.结束\n请选择:\n");
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
		case 3:
			printf("归并排序\n");
			start = clock();
			MergeSort(a, 0, n - 1);
			end = clock();
			break;
		case 4:
			printf("堆排序\n");
			start = clock();
			HeapSort(a, n);
			end = clock();
			break;
		case 0:
			break;
		default:
			break;
		}

		//验证是否退出
		if (input == 0)
		{
			printf("确认退出?\n0.是的\t1.不是\n");
			scanf_s("%d", &input);
			continue;
		}

		//排序结果
		printf("%d组数排序花费时间：%f\n", n, (double)(end - start) / CLOCKS_PER_SEC);

	}
}


/*- ExhaustiveSearch -*/
/*-- 穷举法主函数 --*/
/*- ExhaustiveSearch -*/
void ExhaustiveSearch()
{
	int es_input = 0;
	int tree_n = 0;
	clock_t startTime, endTime;
	double dur;

	printf("*** 欢迎进入穷举法主函数：***\n");
	printf("请选择需要进行的操作:\n1.子集树\n2.0-1背包问题\n0.退出\n");

	scanf_s("%d",&es_input);

	switch (es_input)
	{
	case 1:
		startTime = clock();
		do
		{
			Subsetting(tree_n);
			endTime = clock();
		} while ((endTime - startTime) / 60 < 600);
		break;
	case 2:
		break;
	case 0:
		break;
	default:
		break;
	}
}

/*- SubsetTreeMain -*/
/*-- 子集树主函数 --*/
/*- SubsetTreeMain -*/
void SubsetTreeMain()
{
	int subtree_n = 0;
	clock_t startTime, endTime;
	double dur;

	printf("请输入一个数n,求n的子集个数:\n");
	printf("提示:个数较多运行会很慢\n");
	scanf_s("%d",&subtree_n);

	

	dur = (double)(endTime - startTime) / CLOCKS_PER_SEC;
	printf("算法运行时间：%f s", dur);
	system("pause");
}

/* main */
int main()
{
	int main_input = 0;
	printf_s("请选择:\n1.数组排序\n2.子集树\n0.退出\n");
	scanf_s("%d",&main_input);
	switch (main_input)
	{
	case 1:
		SortMain();
		break;
	case 2:
		SubsetTreeMain();
		break;
	case 0:
		break;
	default:
		break;
	}
	
	getchar();
	return 0;
}
/* end main */