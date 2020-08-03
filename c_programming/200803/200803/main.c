#include <stdio.h>
#include <stdlib.h>
#define STU_MAX 5

void test(); // 1. ȥ�� �ǽ�
void char_null(); // 2. ����, ���ڿ� ����
void array(); // 3. �л� ������ �Է¹ް� ����, ����, ���, ��� ���
int rank_count(float avg[], int i); // 4. ���� ���ϱ�
void array2(); // 5. �� ������ �����ͷ� ����
void char_arr(); // 6. ���ڿ� �迭 ���� �ʱ�ȭ
int swap(int* a, int* b); // 7. ���� ���� �Լ�
int swap_main(); // 8. ���� ����
char swap2(char* a, char* b); // 9. ���� ���� �Լ�
void sort(int arr[], int num); // 10. ���� ���� �Լ�(���1)
void sort2(int arr[], int num); // 11. ���� ���� �Լ�(���2)
void sort3(char arr[], char num); // 12. ���� ���� �Լ�
int sort_main(); // 13. ���� ���� ����
int sort_main2(); // 14. ���� ���� ����

int main() {
	array();

	return 0;
}

void test() {

}

int sort_main2() {
	char str[100];
	printf("������ �Է��ϼ���. : ");
	scanf_s("%s", str, sizeof(str));
	int num = strlen(str);

	printf("--���� �� ����--\n");
	for (int i = 0; i < num; i++) {
		printf("%c", *(str + i));
	}

	sort3(str, num);
	printf("\n\n--���� �� �迭--\n");
	for (int i = 0; i < num; i++) {
		printf("%c", *(str + i));
	}

	return 0;
}

int sort_main() {
	int arr[] = { 5, 7, 1, 9, 2, 4, 6, 3, 8 };
	int num = sizeof(arr) / sizeof(int);

	printf("--���� �� �迭--\n");
	for (int i = 0; i < num; i++) {
		printf("%d ", *(arr + i));
	}

	sort2(arr, num);
	printf("\n\n--���� �� �迭--\n");
	for (int i = 0; i < num; i++) {
		printf("%d ", *(arr + i));
	}

	return 0;
}

void sort3(char arr[], char num) {
	for (int i = 0; i < num; i++) {
		for (int j = i + 1; j < num; j++) {
			if (arr[i] > arr[j]) {
				swap2(&arr[i], &arr[j]);
			}
		}
	}
}

void sort2(int arr[], int num) {
	for (int i = 0; i < num; i++) {
		for (int j = i + 1; j < num; j++) {
			if (arr[i] > arr[j]) {
				swap(&arr[i], &arr[j]);
			}
		}
	}
}

void sort(int arr[], int num) {
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

int swap_main() {
	int a = 5, b = 9;
	printf("���� �� : %d %d\n", a, b);
	swap(&a, &b);
	printf("���� �� : %d %d\n", a, b);
	
	return 0;
}

int swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;

	return 0;
}

char swap2(char* a, char* b) {
	char temp = *a;
	*a = *b;
	*b = temp;

	return 0;
}

void char_arr() {
	int i;
	//char ch;
	char str[6] = "Hello";

	printf("--���� �� ���ڿ�--\n");
	printf("%s \n", str);

	for (i = 0; i < 6; i++) {
		printf("%c , ", str[i]);
	}

	/* ���ڿ� ���� */
	for (i = 0; i < 3; i++) {
		swap2(&str[4 - i], &str[i]); // swap2(str + (4 - i), str + i)

		//ch = str[4 - i];
		//str[4 - i] = str[i];
		//str[i] = ch;
	}

	printf("\n\n--���� �� ���ڿ�--\n");
	printf("%s \n", str);
}

void array2() {
	float score[5][3];
	char buf[50];
	char* name[5];
	int student = sizeof(score) / sizeof(int) / 3;
	float sum, avg;

	for (int i = 0; i < student; i++) {
		name[i] = buf + (i * 10);
	}

	for (int i = 0; i < student; i++) {
		printf("\n�л� �̸� : ");
		scanf_s("%s", name[i], 10);
		printf("���� ������ �Է��ϼ���. : ");
		scanf_s("%f", &score[i][0]);
		printf("���� ������ �Է��ϼ���. : ");
		scanf_s("%f", &score[i][1]);
		printf("���� ������ �Է��ϼ���. : ");
		scanf_s("%f", &score[i][2]);
	}

	printf("\n%s\n", "  -------------------------------------------------------");
	printf("                    ����    ����    ����    ����    ���");
	
	for (int i = 0; i < student; i++) {
		sum = score[i][0] + score[i][1] + score[i][2];
		avg = sum / 3;
		printf("\n%10s �л� : %6.2f  %6.2f  %6.2f  %6.2f  %6.2f\n",
			name[i], score[i][0], score[i][1], score[i][2], sum, avg);
	}
	printf("%s\n", "  -------------------------------------------------------");
}

int rank_count(float avg[], int i) {
	int count = 1;
	for (int j = 0; j < STU_MAX; j++) {
		if (avg[i] < avg[j]) {
			count += 1;
		}
	}
	return count;
}
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void array() {
	float score[STU_MAX][3];
	char name[STU_MAX][10];
	char subject[3][8];
	int student = sizeof(score) / sizeof(int) / 3;
	float sum[STU_MAX], avg[STU_MAX];
	int rank[STU_MAX];

	printf("����� ���� 3���� �Է��ϼ���. : ");
	scanf_s("%s %s %s", subject[0], sizeof(subject[0]), subject[1],
		sizeof(subject[1]), subject[2], sizeof(subject[2]));

	for (int i = 0; i < student; i++) {
		printf("\n�л� �̸� : ");
		scanf_s("%s", name[i], sizeof(name[i]));
		printf("%s ������ �Է��ϼ���. : ", subject[0]);
		scanf_s("%f", &score[i][0]);
		printf("%s ������ �Է��ϼ���. : ", subject[1]);
		scanf_s("%f", &score[i][1]);
		printf("%s ������ �Է��ϼ���. : ", subject[2]);
		scanf_s("%f", &score[i][2]);
	}

	for (int i = 0; i < student; i++) {
		sum[i] = score[i][0] + score[i][1] + score[i][2];
		avg[i] = sum[i] / 3;
	}

	for (int i = 0; i < STU_MAX; i++) {
		rank[i] = rank_count(avg, i);
	}

	printf("\n%s\n", "  ------------------------------------------------------------------------");
	printf("                   %6s    %6s    %6s    %6s    %6s    %4s", 
		subject[0], subject[1], subject[2], "����", "���", "���");
	
	// ������ ���
	for (int i = 0; i < student; i++) {
		for (int j = 0; j < student; j++) {
			if (rank[j] == i + 1) {
				printf("\n%10s �л� : %8.2f  %8.2f  %8.2f  %8.2f  %8.2f  %4d\n",
					name[j], score[j][0], score[j][1], score[j][2], sum[j], avg[j], rank[j]);
			}
		}
	}
	
	// �Է� ������� ���
	/*
	for (int i = 0; i < student; i++) {
		printf("\n%10s �л� : %8.2f  %8.2f  %8.2f  %8.2f  %8.2f  %4d\n",
			name[i], score[i][0], score[i][1], score[i][2], sum[i], avg[i], rank[i]);
	}*/
	printf("%s\n", "  ------------------------------------------------------------------------");
}

void char_null() {
	char str1[5] = "Good";
	char str2[] = "morning";
	char str3 = 'A';

	printf("%s\n", str1);
	printf("%s %s\n", str1, str2);
	printf("%d\n", sizeof(str2) / sizeof(char)); // 8, �� �ڿ� null ����O
	printf("%d\n", sizeof(str3) / sizeof(char)); // 1, �� �ڿ� null ����X
}