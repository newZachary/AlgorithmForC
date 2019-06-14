#include"headerFile.h"
#include"defineFile.h"


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
void merge(int arr[], int low, int mid, int high) {
	int i, k;
	int *tmp = (int *)malloc((high - low + 1) * sizeof(int));
	//申请空间，使其大小为两个
	int left_low = low;
	int left_high = mid;
	int right_low = mid + 1;
	int right_high = high;

	for (k = 0; left_low <= left_high && right_low <= right_high; k++) {  // 比较两个指针所指向的元素
		if (arr[left_low] <= arr[right_low]) {
			tmp[k] = arr[left_low++];
		}
		else {
			tmp[k] = arr[right_low++];
		}
	}

	if (left_low <= left_high) {  //若第一个序列有剩余，直接复制出来粘到合并序列尾
	//memcpy(tmp+k, arr+left_low, (left_high-left_low+l)*sizeof(int));
		for (i = left_low; i <= left_high; i++)
			tmp[k++] = arr[i];
	}

	if (right_low <= right_high) {
		//若第二个序列有剩余，直接复制出来粘到合并序列尾
		//memcpy(tmp+k, arr+right_low, (right_high-right_low+1)*sizeof(int));
		for (i = right_low; i <= right_high; i++)
			tmp[k++] = arr[i];
	}

	for (i = 0; i < high - low + 1; i++)
		arr[low + i] = tmp[i];
	free(tmp);
	return;
}

void merge_sort(int arr[], unsigned int first, unsigned int last) {
	int mid = 0;
	if (first < last) {
		mid = (first + last) / 2; /* 注意防止溢出 */
		/*mid = first/2 + last/2;*/
		//mid = (first & last) + ((first ^ last) >> 1);
		merge_sort(arr, first, mid);
		merge_sort(arr, mid + 1, last);
		merge(arr, first, mid, last);
	}
	return;
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



/* main */
int main()
{
	int i, j, k;
	int input = 0;
	int a[n];
	double start, end;
	srand((unsigned)time(NULL));//更新随机数

	for (k = 0; k < 5; k++)
	{
		printf("第%d次排序,排序前\n", k + 1);
		for (i = 0; i < n; i++)
		{
			a[i] = rand()%100;
			printf("%d->", a[i]);
		}
		printf("end\n");

		//需要排序的算法
		HeapSort(a, n);

		printf("\n排序后:\n");
		for (j = 0; j < n; ++j)
		{
			printf("%d->", a[j]);
		}
		printf("end\n\n");

	}

	getchar();
	getchar();
	return 0;
}
/* end main */