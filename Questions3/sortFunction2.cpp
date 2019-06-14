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
/*-- �Ӽ��� --*/
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
/*--- ���������� ---*/
/*---- sortmain ----*/
void SortMain() 
{
	int i, j;
	int input = 1;
	int a[n];
	double start, end;
	srand((unsigned)time(NULL));//���������

	start = 0;
	end = 0;

	while (input)
	{
		//�����������
		for (i = 0; i < n; i++)
		{
			a[i] = rand();
		}

		//ѡ��ִ�в���
		printf("1.ֱ�Ӳ�������\n2.��������\n3.�鲢����\n4.������\n0.����\n��ѡ��:\n");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("ֱ�Ӳ�������");
			start = clock();
			insertSort(a);
			end = clock();
			break;
		case 2:
			printf("��������\n");
			start = clock();
			quickSort(a, 0, n - 1);
			end = clock();
			break;
		case 3:
			printf("�鲢����\n");
			start = clock();
			MergeSort(a, 0, n - 1);
			end = clock();
			break;
		case 4:
			printf("������\n");
			start = clock();
			HeapSort(a, n);
			end = clock();
			break;
		case 0:
			break;
		default:
			break;
		}

		//��֤�Ƿ��˳�
		if (input == 0)
		{
			printf("ȷ���˳�?\n0.�ǵ�\t1.����\n");
			scanf_s("%d", &input);
			continue;
		}

		//������
		printf("%d�������򻨷�ʱ�䣺%f\n", n, (double)(end - start) / CLOCKS_PER_SEC);

	}
}


/*- ExhaustiveSearch -*/
/*-- ��ٷ������� --*/
/*- ExhaustiveSearch -*/
void ExhaustiveSearch()
{
	int es_input = 0;
	int tree_n = 0;
	clock_t startTime, endTime;
	double dur;

	printf("*** ��ӭ������ٷ���������***\n");
	printf("��ѡ����Ҫ���еĲ���:\n1.�Ӽ���\n2.0-1��������\n0.�˳�\n");

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
/*-- �Ӽ��������� --*/
/*- SubsetTreeMain -*/
void SubsetTreeMain()
{
	int subtree_n = 0;
	clock_t startTime, endTime;
	double dur;

	printf("������һ����n,��n���Ӽ�����:\n");
	printf("��ʾ:�����϶����л����\n");
	scanf_s("%d",&subtree_n);

	

	dur = (double)(endTime - startTime) / CLOCKS_PER_SEC;
	printf("�㷨����ʱ�䣺%f s", dur);
	system("pause");
}

/* main */
int main()
{
	int main_input = 0;
	printf_s("��ѡ��:\n1.��������\n2.�Ӽ���\n0.�˳�\n");
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