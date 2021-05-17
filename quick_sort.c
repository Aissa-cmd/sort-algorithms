#include <stdio.h>
// quick sort

void echanger(int *arr, int i, int j);
int partition(int *arr, int start, int end);
void tri_rapide(int *arr, int start, int end);
void display(int *arr, int arrlen);

int main(int argc, char const *argv[])
{
	int array[] = {12, 2, -5, 67, 6};
	printf("\nles nombres avant tries...\n");
	display(array, sizeof(array)/sizeof(int));
	printf("\nles nombres apres tries...\n");
	tri_rapide(array, 0, 4);
	display(array, sizeof(array)/sizeof(int));
	return 0;
	return 0;
}

void echanger(int *arr, int i, int j) {
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int partition(int *arr, int start, int end) {
	int pivot, i, j, temp;
	pivot = arr[end];
	i = start - 1;

	for(j = start; j < end; j++) {
		if(arr[j] <= pivot) {
			i++;
			echanger(arr, i, j);
		}
	}
	echanger(arr, i+1, end);
	return i+1;
}

void tri_rapide(int *arr, int start, int end) {
	int p;
	if(start < end) {
		p = partition(arr, start, end);
		tri_rapide(arr, start, p-1);
		tri_rapide(arr, p+1, end);
	}
}

void display(int *arr, int arrlen) {
	for(int i = 0; i < arrlen; i++) {
		printf("%i ", arr[i]);
	}
}