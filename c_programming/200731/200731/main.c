#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>

void test(); // 0. 혼자 실습
void mode_select(); // 1. 사칙연산 모드 선택
void number_input(int mode); // 2. 숫자 입력
void calculate(int a, int b, int mode); // 3. 계산 하기
int add(int i, int j); // 4. 더하기 함수 사용
int minus(int i, int j); // 5. 빼기 함수 사용
int multiply(int i, int j); // 6. 곱하기 함수 사용
float divide(int i, int j); // 7. 나누기 함수 사용
void input_key(); // 8. 입력받은 키 값 종류 구분
void input_key2(); // 9. getche 이용하여 입력받은 키 값 종류 구분
void array(); // 10. 학생의 점수를 입력받고, 성적, 총점, 평균을 계산

int main() {
	array();

	return 0;
}

void test() {
	char* arr[3] = { "sadasdas", "dsdsad", "sdadsa" };

	printf("%s\n", arr[0]);
	printf("%s\n", arr[1]);
	printf("%s\n", arr[2]);
}

void array() {
	float score[5][3];
	char name[5][10];
	int student = sizeof(score) / sizeof(int) / 3;
	float sum, avg;

	for (int i = 0; i < student; i++) {
		printf("\n학생 이름 : ");
		scanf_s("%s", name[i], sizeof(name[i]));
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

void input_key2() {
	char key = NULL;
	while (key != '0') {
		printf("하나의 문자를 입력하세요.(0:종료) : ");
		key = getche();

		if (key >= 97 && key <= 122) {
			printf(" → 소문자입니다.\n\n");
		}
		else if (key >= 65 && key <= 90) {
			printf(" → 대문자입니다.\n\n");
		}
		else if (key >= 49 && key <= 57) {
			printf(" → 숫자입니다.\n\n");
		}
		else if (key >= 33 && key <= 126 && key != 48) {
			printf(" → 특수문자입니다.\n\n");
		}
	}
	printf("\n종료. 감사합니다\n");
}

void input_key() {
	char key = NULL;
	while (key != '0') {
		printf("하나의 문자를 입력하세요.(0:종료) : ");
		scanf_s("%c", &key);

		if (key == 10) {
			printf("\r");
		}
		else if (key >= 97 && key <= 122) {
			printf("소문자입니다.\n\n");
		}
		else if (key >= 65 && key <= 90) {
			printf("대문자입니다.\n\n");
		}
		else if (key >= 49 && key <= 57) {
			printf("숫자입니다.\n\n");
		}
		else if (key >= 33 && key <= 126 && key != 48) {
			printf("특수문자입니다.\n\n");
		}
	}
	printf("감사합니다\n");
}

float divide(int i, int j) {
	float result = (float)i / (float)j;
	return result;
}

int multiply(int i, int j) {
	int result = i * j;
	return result;
}

int minus(int i, int j) {
	int result = i - j;
	return result;
}

int add(int i, int j) {
	int result = i + j;
	return result;
}

void calculate(int a, int b, int mode) {
	float result = 0;

	switch (mode) {
	case 1:
		result = add(a, b);
		break;
	case 2:
		result = minus(a, b);
		break;
	case 3:
		result = multiply(a, b);
		break;
	case 4:
		result = divide(a, b);
		break;
	}
	printf("계산값은 %.2f 입니다.\n\n", result);
}

void number_input(int mode) {
	int a, b;

	printf("첫 번째 숫자를 입력하세요. : ");
	scanf_s("%d", &a);
	printf("두 번째 숫자를 입력하세요. : ");
	scanf_s("%d", &b);

	calculate(a, b, mode);
}

void mode_select() {
	int mode;

	while (1) {
		printf("모드를 선택하세요.\n(1:+, 2:-, 3:*, 4:/, 0:종료) : ");
		int mode_num = scanf_s("%d", &mode);
		if (mode_num == 0) {
			printf("잘못된 입력입니다. 프로그램을 다시 실행하세요.\n");
			break;
		}
		if (mode < 0 || mode > 4) {
			printf("1 ~ 4 사이의 숫자만 입력하세요.\n\n");
			continue;
		}
		else if (mode == 0) {
			printf("이용해주셔서 감사합니다.\n");
			break;
		}
		number_input(mode);
	}
}