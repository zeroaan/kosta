#ifndef __myheader_file_Loaded
#define __myheader_file_Loaded


int add_num(int a, int b) {
	return a + b;
}
int sum_num(int* array, int size) {
	int total = 0;
	for (int i = 0; i < size; i++) {
		total += array[i];
	}
	return total;
}

int max_num(int* array, int size) {
	int value = array[0];
	for (int i = 1; i < size; i++) {
		if (value < array[i]) {
			value = array[i];
		}
	}
	return value;
}

int min_num(int* array, int size) {
	int value = array[0];
	for (int i = 1; i < size; i++) {
		if (value > array[i]) {
			value = array[i];
		}
	}
	return value;
}

int iswap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
	
	return 0;
}
char cswap(char* a, char* b) {
	char temp = *a;
	*a = *b;
	*b = temp;
	
	return 0;
}

int isort(int* a, int num) {
	for (int i = 0; i < num; i++) {
		for (int j = i + 1; j < num; j++) {
			if (a[i] > a[j]) {
				iswap(&a[i], &a[j]);
			}
		}
	}
	return 0;
}
char csort(char* a, char num) {
	for (int i = 0; i < num; i++) {
		for (int j = i + 1; j < num; j++) {
			if (a[i] > a[j]) {
				cswap(&a[i], &a[j]);
			}
		}
	}
	return 0;
}

#endif