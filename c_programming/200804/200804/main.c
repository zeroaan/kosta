/* 200804/main.c */
#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 5

void test(); // 1. 혼자 실습
void swap(int* a, int* b); // 2. swap 함수
void sort(int* a, int num); // 3. sort 함수
int min_num(int* array, int size); // 4. 최소값 리턴 함수(정렬 후 첫 번째 값 리턴)
int min_num2(int* array, int size); // 5. 최소값 리턴 함수(배열 하나씩 비교하여 최소값 리턴)
int max_num(int* array, int size); // 6. 최대값 리턴 함수(정렬 후 마지막 값 리턴)
int max_num2(int* array, int size); // 7. 최대값 리턴 함수(배열 하나씩 비교하여 최대값 리턴)
int sum_num(int* array, int size); // 8. 합계 출력 함수
void mms_mode(); // 9. 최소, 최대, 합계 동작모드(배열 크기 고정)
void mms_mode2(); // 10. 최소, 최대, 합계 동작모드(배열 크기 입력)
void mode_input(int* array, int size); // 11. 모드 선택 후 출력

int main() {
	mms_mode2();
	return 0;
}

void test() {
	char* p1;
	int* p2;
	float* p3;
	double* p4;
	printf("%d %d %d %d\n", sizeof(p1), sizeof(p2), sizeof(p3), sizeof(p4));
}

void mode_input(int* array, int size) {
	int mode = 1;
	while (1) {
		printf("\n모드를 선택하세요.\n(1:최소값, 2:최대값, 3:합계, 4:정렬된 배열보기, 0:종료): ");
		int m = scanf_s("%d", &mode);
		if (m == 0) break;
		if (mode == 1) {
			printf("\n가장 작은 수는 %d 입니다.\n", min_num2(array, size));
		}
		else if (mode == 2) {
			printf("\n가장 큰 수는 %d 입니다.\n", max_num2(array, size));
		}
		else if (mode == 3) {
			printf("\n배열의 합계는 %d 입니다.\n", sum_num(array, size));
		}
		else if (mode == 4) {
			sort(array, size);
			printf("\n정렬된 배열은 { ");
			for (int i = 0; i < size; i++) {
				printf("%d ", array[i]);
			}
			printf("} 입니다.\n");
		}
		else if (mode == 0) {
			printf("\n감사합니다.\n");
			break;
		}
	}
	if (mode != 0) {
		printf("\n*************** 숫자만 입력해주세요 ***************\n");
	}
}

// 포인터 배열 사용
void mms_mode2() {
	int size;
	printf("배열 크기 입력 : ");
	scanf_s("%d", &size);
	int* arr = malloc(sizeof(int) * size); // 메모리 할당하여 배열 사용

	printf("정수 %d개를 입력해서 최소값, 최대값, 합계를 구하는 함수입니다.\n\n", size);
	for (int i = 0; i < size; i++) {
		printf("%d번째 수를 입력하세요 : ", i + 1);
		scanf_s("%d", &arr[i]);
	}

	// sort(arr, MAX_NUM);
	mode_input(arr, size);
	free(arr); // 메모리 할당 해제
}

// 일반 배열 사용
void mms_mode() {
	int arr[MAX_NUM];
	printf("정수 %d개를 입력해서 최소값, 최대값, 합계를 구하는 함수입니다.\n\n", MAX_NUM);
	for (int i = 0; i < MAX_NUM; i++) {
		printf("%d번째 수를 입력하세요 : ", i + 1);
		scanf_s("%d", &arr[i]);
	}
	// sort(arr, MAX_NUM);
	mode_input(arr, MAX_NUM);
}

int sum_num(int* array, int size) {
	int total = 0;
	for (int i = 0; i < size; i++) {
		total += array[i];
	}
	return total;
}

// 배열 하나씩 비교하고 최대값 찾아서 리턴
int max_num2(int* array, int size) {
	int value = array[0];
	for (int i = 1; i < size; i++) {
		if (value < array[i]) {
			value = array[i];
		}
	}
	return value;
}

// 정렬시킨 후 첫 번째 값을 최소값으로 리턴
int max_num(int* array, int size) {
	int num = array[size - 1];
	return num;
}

// 배열 하나씩 비교하고 최소값 찾아서 리턴
int min_num2(int* array, int size) {
	int value = array[0];
	for (int i = 1; i < size; i++) {
		if (value > array[i]) {
			value = array[i];
		}
	}
	return value;
}

// 정렬시킨 후 첫 번째 값을 최소값으로 리턴
int min_num(int* array, int size) {
	int num = array[0];
	return num;
}

void sort(int* a, int num) {
	for (int i = 0; i < num; i++) {
		for (int j = i + 1; j < num; j++) {
			if (a[i] > a[j]) {
				swap(&a[i], &a[j]);
			}
		}
	}
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}