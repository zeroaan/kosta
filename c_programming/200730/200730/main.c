#include <stdio.h>

void float_sum(); // 1. 변수 선언 후 덧셈 해보기
void char_over(); // 2. char 범위(-128~127) 초과
void cast(); // 3. 강제 형 변환, 1.5부터 100.5까지 더하기
void while_print(); // 4. while 반복문 실행, break 사용
void for_print(); // 5. for 반복문 실행
void if_else(); // 6. if, else if, else 사용
void scanf_while(); // 7. scanf 사용
void mode_ab(); // 8. 모드 선택해서 사칙연산하기

int main() {
	mode_ab();

	return 0;
}

void mode_ab() {
	int mode;
	int a, b;
	float result = 0;

	while (1) {
		printf("모드를 입력하세요.\n(1:+, 2:-, 3:*, 4:/, 0:종료) : ");
		int num = scanf_s("%d", &mode);
		if (num == 0) {
			printf("잘못된 입력입니다. 다시 실행하세요.\n");
			break;
		}
		if (mode < 0 || mode > 4) {
			printf("잘못된 모드 입니다.");
			continue;
		}
		else if (mode == 0) {
			printf("감사합니다.\n");
			break;
		}
		printf("계산할 수를 두 개 입력하세요. : ");
		scanf_s("%d %d", &a, &b);

		if (mode == 1) {
			result = a + b;
		}
		else if (mode == 2) {
			result = a - b;
		}
		else if (mode == 3) {
			result = a * b;
		}
		else if (mode == 4) {
			result = (float)a / (float)b;
		}
		printf("계산값은 %.2f 입니다.", result);
	}
}

void scanf_while() {
	int i;
	while (1) {
		printf("오늘은 무슨 요일일까?\n1. 수요일, 2. 목요일, 3. 금요일\n정답은? : ");
		scanf_s("%d", &i);
		if (i == 1) {
			printf("틀렸습니다. ");
		}
		else if (i == 2) {
			printf("정답입니다. ");
			break;
		}
		else if (i == 3) {
			printf("틀렸습니다. ");
		}
		else {
			printf("다시 입력하세요. ");
		}
	}
}

void if_else() {
	int i;
	printf("나이를 입력하세요 : ");
	scanf_s("%d", &i);
	if (0 < i && i < 8) {
		printf("나이가 너무 어립니다.\n");
	}
	else if (8 < i && i < 14) {
		printf("초등학생입니다.\n");
	}
	else if (14 < i && i < 17) {
		printf("중학생입니다.\n");
	}
	else if (17 < i && i < 20) {
		printf("고등학생입니다.\n");
	}
	else {
		printf("성인입니다.\n");
	}
}

void for_print() {
	for (int i = 0; i < 10; i++) {
		printf("Wow, Hi~\n");
	}
}

void while_print() {
	int i = 0;
	while (i < 10) {
		printf("Hello, Jin young\n");
		i++;
		
		if (i == 5) {
			printf("i가 %d 입니다.\n", i);
			break;
		}
	}

	int j = 0;
	while (j < 3)
		printf("HI\n"), j++;
}

void cast() {
	double e1 = 3 + (int)3.14;
	printf("%f\n", e1);

	float result = 0;
	for (float i = 1.5; i < 101; i++) {
		result += i;
	}
	printf("%f\n", result);
}

void char_over() {
	char c = 129;
	printf("%d\n", c);

	char c1 = 10, c2 = 20;
	char c3 = c1 * c2;
	printf("%d\n", c3);
}

void float_sum() {
	float a, b, result;
	a = 5.3;
	b = 3.7;
	result = a + b;

	printf("덧셈 결과: %.1f\n", result);
	printf("%.1f 더하기 %.1f 은 %.1f 입니다.\n", a, b, result);
	printf("변수 result에 저장된 값: %.1f\n", result);
}