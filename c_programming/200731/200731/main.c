#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>

void test(); // 0. ȥ�� �ǽ�
void mode_select(); // 1. ��Ģ���� ��� ����
void number_input(int mode); // 2. ���� �Է�
void calculate(int a, int b, int mode); // 3. ��� �ϱ�
int add(int i, int j); // 4. ���ϱ� �Լ� ���
int minus(int i, int j); // 5. ���� �Լ� ���
int multiply(int i, int j); // 6. ���ϱ� �Լ� ���
float divide(int i, int j); // 7. ������ �Լ� ���
void input_key(); // 8. �Է¹��� Ű �� ���� ����
void input_key2(); // 9. getche �̿��Ͽ� �Է¹��� Ű �� ���� ����
void array(); // 10. �л��� ������ �Է¹ް�, ����, ����, ����� ���

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
		printf("\n�л� �̸� : ");
		scanf_s("%s", name[i], sizeof(name[i]));
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

void input_key2() {
	char key = NULL;
	while (key != '0') {
		printf("�ϳ��� ���ڸ� �Է��ϼ���.(0:����) : ");
		key = getche();

		if (key >= 97 && key <= 122) {
			printf(" �� �ҹ����Դϴ�.\n\n");
		}
		else if (key >= 65 && key <= 90) {
			printf(" �� �빮���Դϴ�.\n\n");
		}
		else if (key >= 49 && key <= 57) {
			printf(" �� �����Դϴ�.\n\n");
		}
		else if (key >= 33 && key <= 126 && key != 48) {
			printf(" �� Ư�������Դϴ�.\n\n");
		}
	}
	printf("\n����. �����մϴ�\n");
}

void input_key() {
	char key = NULL;
	while (key != '0') {
		printf("�ϳ��� ���ڸ� �Է��ϼ���.(0:����) : ");
		scanf_s("%c", &key);

		if (key == 10) {
			printf("\r");
		}
		else if (key >= 97 && key <= 122) {
			printf("�ҹ����Դϴ�.\n\n");
		}
		else if (key >= 65 && key <= 90) {
			printf("�빮���Դϴ�.\n\n");
		}
		else if (key >= 49 && key <= 57) {
			printf("�����Դϴ�.\n\n");
		}
		else if (key >= 33 && key <= 126 && key != 48) {
			printf("Ư�������Դϴ�.\n\n");
		}
	}
	printf("�����մϴ�\n");
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
	printf("��갪�� %.2f �Դϴ�.\n\n", result);
}

void number_input(int mode) {
	int a, b;

	printf("ù ��° ���ڸ� �Է��ϼ���. : ");
	scanf_s("%d", &a);
	printf("�� ��° ���ڸ� �Է��ϼ���. : ");
	scanf_s("%d", &b);

	calculate(a, b, mode);
}

void mode_select() {
	int mode;

	while (1) {
		printf("��带 �����ϼ���.\n(1:+, 2:-, 3:*, 4:/, 0:����) : ");
		int mode_num = scanf_s("%d", &mode);
		if (mode_num == 0) {
			printf("�߸��� �Է��Դϴ�. ���α׷��� �ٽ� �����ϼ���.\n");
			break;
		}
		if (mode < 0 || mode > 4) {
			printf("1 ~ 4 ������ ���ڸ� �Է��ϼ���.\n\n");
			continue;
		}
		else if (mode == 0) {
			printf("�̿����ּż� �����մϴ�.\n");
			break;
		}
		number_input(mode);
	}
}