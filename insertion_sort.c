#include <stdio.h>
// insertion sort

void tri_insertion(int *arr, int arrLength);
void display(int *arr, int arrlen);

int main() 
{
	int numbers[5] = {8, 2, 4, 1, 3};
	printf("\nles nombres avant tries...\n");
	display(numbers, 5);
	printf("\nles nombres apres tries...\n");
	tri_insertion(numbers, 5);
	display(numbers, 5);
	printf("\n");
	return 0;
}

void tri_insertion(int *arr, int arrLength) {
	int i;
	for (i = 0; i < arrLength; i++) {
		int current = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > current) {
			arr[j + 1] = arr[j];
			j -= 1;
		}
		arr[j + 1] = current;
	}
}

void display(int *arr, int arrlen) {
	for(int i = 0; i < arrlen; i++) {
		printf("%i ", arr[i]);
	}
}