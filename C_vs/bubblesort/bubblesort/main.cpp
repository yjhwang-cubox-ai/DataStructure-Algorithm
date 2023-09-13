#include <stdio.h>
#include <stdlib.h>


void BubbleSort(int DataSet[], int Length) 
{
	int i = 0;
	int j = 0;
	int temp = 0;
	
	for (i = 0; i < Length - 1; i++) 
	{
		for (j = 0; j < (Length - (i + 1)); j++) {
			if (DataSet[j] > DataSet[j + 1]) {
				temp = DataSet[j + 1];
				DataSet[j + 1] = DataSet[j];
				DataSet[j] = temp;
			}
		}
	}

}

void InsertionSort(int DataSet[], int Length)
{
	int i = 0;
	int j = 0;
	int value = 0;
	int temp = 0;
	for (i = 1; i < Length; i++) {

		temp = DataSet[i];
		for (j = i; j > 0 && DataSet[j - 1] > temp; j--) {
			DataSet[j] = DataSet[j - 1];
		}
		DataSet[j] = temp;
	}
}

void quick_sort(int DataSet[], int left, int right) {
	int pL = left;
	int pR = right;
	int pivot = DataSet[(pL + pR) / 2];
	int temp;

	do {
		while (DataSet[pL] < pivot) {
			pL++;
		}
		while (DataSet[pR] > pivot) {
			pR--;
		}
	
		if (pL <= pR) {
			temp = DataSet[pR];
			DataSet[pR] = DataSet[pL];
			DataSet[pL] = temp;
			pL++;
			pR--;
		}
	} while (pL <= pR);

	if(left<pR)
		quick_sort(DataSet, left, pR);
	if (right > pL)
		quick_sort(DataSet, pL, right);\
}

void mergeSort(int* arr, int size)
{
	int* arrMerge = (int*)malloc(sizeof(int) * size);
	mergeSortUtil(arr, arrMerge, 0, size - 1);
	free(arrMerge);

}

void merge(int* arr, int* arrMerge, int left, int mid, int right)
{
	int idx1 = left;
	int idx2 = mid + 1;
	int idxM = left;

	for (int i = left; i <= right; i++) {
		arrMerge[i] = arr[i];
	}
	while (idx1 <= mid && idx2 <= right) {
		if (arrMerge[idx1] < arrMerge[idx2])
			arr[idxM++] = arrMerge[idx1];
		else
			arr[idxM++] = arrMerge[idx2];
	}
	while (idx1 )

}

void mergeSortUtil(int* arr, int* arrMerge, int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		mergeSortUtil(arr, arrMerge, left, mid);
		mergeSortUtil(arr, arrMerge, mid+1, right);
		merge(arr, arrMerge, left, mid, right);
	}
}










//int main() {
//	int DataSet[] = { 6,4,2,3,1,5 };
//	int Length = sizeof DataSet / sizeof DataSet[0];
//	int i = 0;
//
//	//BubbleSort(DataSet, Length);
//	//InsertionSort(DataSet, Length);
//	quick_sort(DataSet, 0, Length - 1);
//
//	for (i = 0; i < Length; i++) {
//		printf("%d", DataSet[i]);
//	}
//
//	printf("\n");
//
//	return 0;
//}

//정렬된 2개의 배열을 병합
void merge(int* arr1, int size1, int* arr2, int size2, int* arrMerge)
{
	int idx1 = 0;
	int	idx2 = 0;
	int idxM = 0;
	while (idx1 < size1 && idx2 < size2)
	{
		if (arr1[idx1] < arr2[idx2])
		{
			arrMerge[idxM] = arr1[idx1];
			idxM++;
			idx1++;
		}
		else
		{
			arrMerge[idxM] = arr2[idx2];
			idxM++;
			idx2++;
		}
	}
	while (idx1 < size1) arrMerge[idxM++] = arr1[idx1++];
	while (idx2 < size2) arrMerge[idxM++] = arr2[idx2++];


}

int main() {
	int arr1[6] = { 2,4,7,9,11,15 };
	int arr2[6] = { 1,5,8,14,19,21 };
	int arrMerge[12];

	merge(arr1, 6, arr2, 6, arrMerge);

	int Length = sizeof arrMerge / sizeof arrMerge[0];

	for (int i = 0; i < Length; i++) {
		printf("%d\t", arrMerge[i]);
	}

	return 0;

}
