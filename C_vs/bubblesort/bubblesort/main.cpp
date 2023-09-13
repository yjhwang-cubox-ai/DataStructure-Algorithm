#include <stdio.h>

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

int main() {
	int DataSet[] = { 6,4,2,3,1,5 };
	int Length = sizeof DataSet / sizeof DataSet[0];
	int i = 0;

	//BubbleSort(DataSet, Length);
	//InsertionSort(DataSet, Length);
	quick_sort(DataSet, 0, Length - 1);

	for (i = 0; i < Length; i++) {
		printf("%d", DataSet[i]);
	}

	printf("\n");

	return 0;
}


