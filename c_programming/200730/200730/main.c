#include <stdio.h>

void float_sum(); // 1. ���� ���� �� ���� �غ���
void char_over(); // 2. char ����(-128~127) �ʰ�
void cast(); // 3. ���� �� ��ȯ, 1.5���� 100.5���� ���ϱ�
void while_print(); // 4. while �ݺ��� ����, break ���
void for_print(); // 5. for �ݺ��� ����
void if_else(); // 6. if, else if, else ���
void scanf_while(); // 7. scanf ���
void mode_ab(); // 8. ��� �����ؼ� ��Ģ�����ϱ�

int main() {
	mode_ab();

	return 0;
}

void mode_ab() {
	int mode;
	int a, b;
	float result = 0;

	while (1) {
		printf("��带 �Է��ϼ���.\n(1:+, 2:-, 3:*, 4:/, 0:����) : ");
		int num = scanf_s("%d", &mode);
		if (num == 0) {
			printf("�߸��� �Է��Դϴ�. �ٽ� �����ϼ���.\n");
			break;
		}
		if (mode < 0 || mode > 4) {
			printf("�߸��� ��� �Դϴ�.");
			continue;
		}
		else if (mode == 0) {
			printf("�����մϴ�.\n");
			break;
		}
		printf("����� ���� �� �� �Է��ϼ���. : ");
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
		printf("��갪�� %.2f �Դϴ�.", result);
	}
}

void scanf_while() {
	int i;
	while (1) {
		printf("������ ���� �����ϱ�?\n1. ������, 2. �����, 3. �ݿ���\n������? : ");
		scanf_s("%d", &i);
		if (i == 1) {
			printf("Ʋ�Ƚ��ϴ�. ");
		}
		else if (i == 2) {
			printf("�����Դϴ�. ");
			break;
		}
		else if (i == 3) {
			printf("Ʋ�Ƚ��ϴ�. ");
		}
		else {
			printf("�ٽ� �Է��ϼ���. ");
		}
	}
}

void if_else() {
	int i;
	printf("���̸� �Է��ϼ��� : ");
	scanf_s("%d", &i);
	if (0 < i && i < 8) {
		printf("���̰� �ʹ� ��ϴ�.\n");
	}
	else if (8 < i && i < 14) {
		printf("�ʵ��л��Դϴ�.\n");
	}
	else if (14 < i && i < 17) {
		printf("���л��Դϴ�.\n");
	}
	else if (17 < i && i < 20) {
		printf("����л��Դϴ�.\n");
	}
	else {
		printf("�����Դϴ�.\n");
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
			printf("i�� %d �Դϴ�.\n", i);
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

	printf("���� ���: %.1f\n", result);
	printf("%.1f ���ϱ� %.1f �� %.1f �Դϴ�.\n", a, b, result);
	printf("���� result�� ����� ��: %.1f\n", result);
}