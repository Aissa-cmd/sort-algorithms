#include <stdio.h>
#include <stdlib.h>

void display(int *arr, int arrlen);
void merge(int *arr, int start, int middle, int end);
void tri_par_fusion(int *arr, int start, int end);

int main(int argc, char const *argv[])
{
	int array[] = {12, 2, -5, 67, 6};
	printf("\nles nombres avant tries...\n");
	display(array, sizeof(array)/sizeof(int));
	printf("\nles nombres apres tries...\n");
	tri_par_fusion(array, 0, 4);
	display(array, sizeof(array)/sizeof(int));
	return 0;
}

void display(int *arr, int arrlen) {
	for(int i = 0; i < arrlen; i++) {
		printf("%i ", arr[i]);
	}
}

void merge(int *arr, int start, int middle, int end) {
	int length1, length2, k, i, j, *temp_arr1, *temp_arr2;
	// calculate the length of the left half of the array
	length1 = middle-start+1;
	// calculate the length of the right half of the array
	length2 = end-middle;

	// create two temprary array each with the corespoding length
	temp_arr1 = (int *)malloc(sizeof(int) * length1);
	temp_arr2 = (int *)malloc(sizeof(int) * length2);

	// copy the right half of the arry to temp_arr1
	for(i = 0; i < length1; i++) {
		temp_arr1[i] = arr[start+i];
	}

	// copy the right half of the arry to temp_arr2
	for(j = 0; j < length2; j++) {
		temp_arr2[j] = arr[middle+1+j];
	}

	i = 0;  // initial the index of the temp_arr1
	j = 0;  // initial the index of the temp_arr2
	k = start; // initial the index of the original array

	// while we did not reach the end of any of the temprary
	// array do the following
	while(i < length1 && j < length2) {
		if(temp_arr1[i] < temp_arr2[j]) {
			arr[k] = temp_arr1[i];
			i++;
		} else {
			arr[k] = temp_arr2[j];
			j++;
		}
		k++;
	}
	// one of the temprary arrays will reach its end before the 
	// other one so the following while loops, are making sure
	// to copy the left elements in one of the arrays to the original
	// array. eventually only one of the while loops will run
	// not both

	// copy the remaining of the temp_arr1 to the original array
	while(i < length1) {
		arr[k] = temp_arr1[i];
		i++;
		k++;
	}

	// copy the remaining of the temp_arr2 to the original array
	while(j < length2) {
		arr[k] = temp_arr2[j];
		j++;
		k++;
	}

	// free the space allocated for the tow temprary arrays
	free(temp_arr1);
	free(temp_arr2);
}

void tri_par_fusion(int *arr, int start, int end) {
	// start: the index of the first element in the array
	// end: the index of the last element in the array
	int middle;
	// check if we have more than one element in the arra
	if(start < end) {
		// calculate the index of the middle element in the array
		middle = (end+start)/2;
		// sort the left half of the array
		tri_par_fusion(arr, start, middle);
		// sort the right half of the array
		tri_par_fusion(arr, middle+1, end);
		// merge the two sorted halves
		merge(arr, start, middle, end);
	}
}