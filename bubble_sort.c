#include <stdio.h>
// bubble sort

void tri_a_bulle(int *table, int len);
void display(int *arr, int arrlen);

int main(int argc, char const *argv[])
{
	int numbers[5] = {12, 2, -5, 67, 6};
	printf("\nles nombres avant tries...\n");
	display(numbers, 5);
	printf("\nles nombres apres tries...\n");
	tri_a_bulle(numbers, 5);
	display(numbers, 5);
	printf("\n");
	return 0;
}

void display(int *arr, int arrlen) {
	for(int i = 0; i < arrlen; i++) {
		printf("%i ", arr[i]);
	}
}

void tri_a_bulle(int *table, int len) {
	int swap_flag, temp, i;
	int j = 0;
	do {
		j++;
		swap_flag = 0;
		for(i = 0; i < len-j; i++) {
			if(table[i] > table[i+1]) {
				temp = table[i];
				table[i] = table[i+1];
				table[i+1] = temp;
				swap_flag = 1;
			}
		}
	} while(swap_flag > 0);
}

