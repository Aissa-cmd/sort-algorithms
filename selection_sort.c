#include <stdio.h>
// selection sort

int index_of_min(int *table, int idx, int len);
void tri_selection(int *table, int len);
void display(int *arr, int arrlen);

int main(int argc, char const *argv[])
{
	int numbers[5] = {8, 2, 4, 1, 3};
	printf("\nles nombres avant tries...\n");
	display(numbers, 5);
	printf("\nles nombres apres tries...\n");
	tri_selection(numbers, 5);
	display(numbers, 5);
	printf("\n");
	return 0;
}

int index_of_min(int *table, int idx, int len) {
	int i, index, min;
	min = table[idx];
	index = idx;
	for(i = idx+1; i < len; i++) {
		if(table[i] < min) {
			min = table[i];
			index = i;
		}
	}
	return index;
}

void tri_selection(int *table, int len) {
	int i, temp, k;
	for(i = 0; i < len; i++) {
		k = index_of_min(table, i, len);
		temp = table[i];
		table[i] = table[k];
		table[k] = temp;
	}
}

void display(int *arr, int arrlen) {
	for(int i = 0; i < arrlen; i++) {
		printf("%i ", arr[i]);
	}
}