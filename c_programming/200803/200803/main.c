#include <stdio.h>
#include <stdlib.h>
#define STU_MAX 5

void test(); // 1. 혼자 실습
void char_null(); // 2. 문자, 문자열 차이
void array(); // 3. 학생 점수를 입력받고 점수, 총점, 평균, 등수 출력
int rank_count(float avg[], int i); // 4. 순위 구하기
void array2(); // 5. 위 문제를 포인터로 적용
void char_arr(); // 6. 문자열 배열 변수 초기화
int swap(int* a, int* b); // 7. 정수 스왑 함수
int swap_main(); // 8. 스왑 메인
char swap2(char* a, char* b); // 9. 문자 스왑 함수
void sort(int arr[], int num); // 10. 숫자 정렬 함수(방법1)
void sort2(int arr[], int num); // 11. 숫자 정렬 함수(방법2)
void sort3(char arr[], char num); // 12. 문자 정렬 함수
int sort_main(); // 13. 숫자 정렬 메인
int sort_main2(); // 14. 문자 정렬 메인

int main() {
	array();

	return 0;
}

void test() {

}

int sort_main2() {
	char str[100];
	printf("문장을 입력하세요. : ");
	scanf_s("%s", str, sizeof(str));
	int num = strlen(str);

	printf("--변경 전 문장--\n");
	for (int i = 0; i < num; i++) {
		printf("%c", *(str + i));
	}

	sort3(str, num);
	printf("\n\n--변경 후 배열--\n");
	for (int i = 0; i < num; i++) {
		printf("%c", *(str + i));
	}

	return 0;
}

int sort_main() {
	int arr[] = { 5, 7, 1, 9, 2, 4, 6, 3, 8 };
	int num = sizeof(arr) / sizeof(int);

	printf("--변경 전 배열--\n");
	for (int i = 0; i < num; i++) {
		printf("%d ", *(arr + i));
	}

	sort2(arr, num);
	printf("\n\n--변경 후 배열--\n");
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
	printf("변경 전 : %d %d\n", a, b);
	swap(&a, &b);
	printf("변경 후 : %d %d\n", a, b);
	
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

	printf("--변경 전 문자열--\n");
	printf("%s \n", str);

	for (i = 0; i < 6; i++) {
		printf("%c , ", str[i]);
	}

	/* 문자열 변경 */
	for (i = 0; i < 3; i++) {
		swap2(&str[4 - i], &str[i]); // swap2(str + (4 - i), str + i)

		//ch = str[4 - i];
		//str[4 - i] = str[i];
		//str[i] = ch;
	}

	printf("\n\n--변경 후 문자열--\n");
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
		printf("\n학생 이름 : ");
		scanf_s("%s", name[i], 10);
		printf("국어 점수를 입력하세요. : ");
		scanf_s("%f", &score[i][0]);
		printf("영어 점수를 입력하세요. : ");
		scanf_s("%f", &score[i][1]);
		printf("수학 점수를 입력하세요. : ");
		scanf_s("%f", &score[i][2]);
	}

	printf("\n%s\n", "  -------------------------------------------------------");
	printf("                    국어    영어    수학    총점    평균");
	
	for (int i = 0; i < student; i++) {
		sum = score[i][0] + score[i][1] + score[i][2];
		avg = sum / 3;
		printf("\n%10s 학생 : %6.2f  %6.2f  %6.2f  %6.2f  %6.2f\n",
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

	printf("기록할 과목 3개를 입력하세요. : ");
	scanf_s("%s %s %s", subject[0], sizeof(subject[0]), subject[1],
		sizeof(subject[1]), subject[2], sizeof(subject[2]));

	for (int i = 0; i < student; i++) {
		printf("\n학생 이름 : ");
		scanf_s("%s", name[i], sizeof(name[i]));
		printf("%s 점수를 입력하세요. : ", subject[0]);
		scanf_s("%f", &score[i][0]);
		printf("%s 점수를 입력하세요. : ", subject[1]);
		scanf_s("%f", &score[i][1]);
		printf("%s 점수를 입력하세요. : ", subject[2]);
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
		subject[0], subject[1], subject[2], "총점", "평균", "등수");
	
	// 등수대로 출력
	for (int i = 0; i < student; i++) {
		for (int j = 0; j < student; j++) {
			if (rank[j] == i + 1) {
				printf("\n%10s 학생 : %8.2f  %8.2f  %8.2f  %8.2f  %8.2f  %4d\n",
					name[j], score[j][0], score[j][1], score[j][2], sum[j], avg[j], rank[j]);
			}
		}
	}
	
	// 입력 순서대로 출력
	/*
	for (int i = 0; i < student; i++) {
		printf("\n%10s 학생 : %8.2f  %8.2f  %8.2f  %8.2f  %8.2f  %4d\n",
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
	printf("%d\n", sizeof(str2) / sizeof(char)); // 8, 맨 뒤에 null 포함O
	printf("%d\n", sizeof(str3) / sizeof(char)); // 1, 맨 뒤에 null 포함X
}