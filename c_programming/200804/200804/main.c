/* 200804/main.c */
#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 5

void test(); // 1. ȥ�� �ǽ�
void swap(int* a, int* b); // 2. swap �Լ�
void sort(int* a, int num); // 3. sort �Լ�
int min_num(int* array, int size); // 4. �ּҰ� ���� �Լ�(���� �� ù ��° �� ����)
int min_num2(int* array, int size); // 5. �ּҰ� ���� �Լ�(�迭 �ϳ��� ���Ͽ� �ּҰ� ����)
int max_num(int* array, int size); // 6. �ִ밪 ���� �Լ�(���� �� ������ �� ����)
int max_num2(int* array, int size); // 7. �ִ밪 ���� �Լ�(�迭 �ϳ��� ���Ͽ� �ִ밪 ����)
int sum_num(int* array, int size); // 8. �հ� ��� �Լ�
void mms_mode(); // 9. �ּ�, �ִ�, �հ� ���۸��(�迭 ũ�� ����)
void mms_mode2(); // 10. �ּ�, �ִ�, �հ� ���۸��(�迭 ũ�� �Է�)
void mode_input(int* array, int size); // 11. ��� ���� �� ���

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
		printf("\n��带 �����ϼ���.\n(1:�ּҰ�, 2:�ִ밪, 3:�հ�, 4:���ĵ� �迭����, 0:����): ");
		int m = scanf_s("%d", &mode);
		if (m == 0) break;
		if (mode == 1) {
			printf("\n���� ���� ���� %d �Դϴ�.\n", min_num2(array, size));
		}
		else if (mode == 2) {
			printf("\n���� ū ���� %d �Դϴ�.\n", max_num2(array, size));
		}
		else if (mode == 3) {
			printf("\n�迭�� �հ�� %d �Դϴ�.\n", sum_num(array, size));
		}
		else if (mode == 4) {
			sort(array, size);
			printf("\n���ĵ� �迭�� { ");
			for (int i = 0; i < size; i++) {
				printf("%d ", array[i]);
			}
			printf("} �Դϴ�.\n");
		}
		else if (mode == 0) {
			printf("\n�����մϴ�.\n");
			break;
		}
	}
	if (mode != 0) {
		printf("\n*************** ���ڸ� �Է����ּ��� ***************\n");
	}
}

// ������ �迭 ���
void mms_mode2() {
	int size;
	printf("�迭 ũ�� �Է� : ");
	scanf_s("%d", &size);
	int* arr = malloc(sizeof(int) * size); // �޸� �Ҵ��Ͽ� �迭 ���

	printf("���� %d���� �Է��ؼ� �ּҰ�, �ִ밪, �հ踦 ���ϴ� �Լ��Դϴ�.\n\n", size);
	for (int i = 0; i < size; i++) {
		printf("%d��° ���� �Է��ϼ��� : ", i + 1);
		scanf_s("%d", &arr[i]);
	}

	// sort(arr, MAX_NUM);
	mode_input(arr, size);
	free(arr); // �޸� �Ҵ� ����
}

// �Ϲ� �迭 ���
void mms_mode() {
	int arr[MAX_NUM];
	printf("���� %d���� �Է��ؼ� �ּҰ�, �ִ밪, �հ踦 ���ϴ� �Լ��Դϴ�.\n\n", MAX_NUM);
	for (int i = 0; i < MAX_NUM; i++) {
		printf("%d��° ���� �Է��ϼ��� : ", i + 1);
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

// �迭 �ϳ��� ���ϰ� �ִ밪 ã�Ƽ� ����
int max_num2(int* array, int size) {
	int value = array[0];
	for (int i = 1; i < size; i++) {
		if (value < array[i]) {
			value = array[i];
		}
	}
	return value;
}

// ���Ľ�Ų �� ù ��° ���� �ּҰ����� ����
int max_num(int* array, int size) {
	int num = array[size - 1];
	return num;
}

// �迭 �ϳ��� ���ϰ� �ּҰ� ã�Ƽ� ����
int min_num2(int* array, int size) {
	int value = array[0];
	for (int i = 1; i < size; i++) {
		if (value > array[i]) {
			value = array[i];
		}
	}
	return value;
}

// ���Ľ�Ų �� ù ��° ���� �ּҰ����� ����
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