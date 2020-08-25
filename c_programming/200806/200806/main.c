#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_NUM 6
#define MAX_MAN 3
#define STU_MAX 3

void lotto(); // 1. 로또 프로그램
int MyRand(int max); // 2. 랜덤 난수 생성
void MyNameGen(int len); // 3. 랜덤 문자열 생성
char* MyNameGen2(int len); // 4. 랜덤 문자열 생성2
void ascii(); // 5. 아스키 코드 출력
void ascii2(); // 5. 아스키 코드 출력
int CC(int i);

typedef struct person {
	char name[20];
	int age;
	int a, b, c;
} ps;

int main() {
	lotto();

	return 0;
}

int CC(int i) {
	if ((i == 7) || (i == 8) || (i == 9) || (i == 10) || (i == 11) || (i == 13)) {
		return 32;
	}
	return 0;
}

void ascii2() {
	int i;
	int i1;
	int col = 5;
	int offset = (128 + (col - 1)) / col;
	FILE *fp = fopen("E:\\programming\\c_programming\\test.txt", "wb");

	for (i = 0; i < 26; i++) {
		if ((i == 1)) {
			fprintf(fp, "%3d  %3x  %3c  |  ", i, i, i);
			fprintf(fp, "%3d  %3x  %3c  |  ", i + 26, i + 26, ' ');
			fprintf(fp, "%3d  %3x  %3c  |  ", i + 52, i + 52, i + 52);
			fprintf(fp, "%3d  %3x  %3c  |  ", i + 78, i + 78, i + 78);
			fprintf(fp, "%3d  %3x  %3c\n", i + 104, i + 104, i + 104);
		}
		else if ((i == 7) || (i == 8) || (i == 9) || (i == 10) || (i == 11) || (i == 13)) {
			fprintf(fp, "%3d  %3x  %3c  |  ", i, i, ' ');
			fprintf(fp, "%3d  %3x  %3c  |  ", i + 26, i + 26, i + 26);
			fprintf(fp, "%3d  %3x  %3c  |  ", i + 52, i + 52, i + 52);
			fprintf(fp, "%3d  %3x  %3c  |  ", i + 78, i + 78, i + 78);
			fprintf(fp, "%3d  %3x  %3c\n", i + 104, i + 104, i + 104);
		}
		else if ((i == 24) || (i == 25)) {
			fprintf(fp, "%3d  %3x  %3c  |  ", i, i, i);
			fprintf(fp, "%3d  %3x  %3c  |  ", i + 26, i + 26, i + 26);
			fprintf(fp, "%3d  %3x  %3c  |  ", i + 52, i + 52, i + 52);
			fprintf(fp, "%3d  %3x  %3c  |\n", i + 78, i + 78, i + 78);
		}
		else {
			fprintf(fp, "%3d  %3x  %3c  |  ", i, i, i);
			fprintf(fp, "%3d  %3x  %3c  |  ", i + 26, i + 26, i + 26);
			fprintf(fp, "%3d  %3x  %3c  |  ", i + 52, i + 52, i + 52);
			fprintf(fp, "%3d  %3x  %3c  |  ", i + 78, i + 78, i + 78);
			fprintf(fp, "%3d  %3x  %3c\n", i + 104, i + 104, i + 104);
		}
	}

	/*for (i = 0; i < offset; i++) {
		i1 = i;
		fprintf(fp, "%3d %3x %3c | ", i1, i1, CC(i1)); i1 += offset;
		fprintf(fp, "%3d %3x %3c | ", i1, i1, CC(i1)); i1 += offset;
		fprintf(fp, "%3d %3x %3c | ", i1, i1, CC(i1)); i1 += offset;
		fprintf(fp, "%3d %3x %3c | ", i1, i1, CC(i1)); i1 += offset;
		if (i1 < 128) {
			fprintf(fp, "%3d %2x %3c | ", i1, i1, CC(i1));
		}
		fprintf(fp, "\n");
	}*/

}

void ascii() {
	int i;

	for (i = 0; i < 26; i++) {
		if ((i == 1)) {
			fprintf("%3d  %3x  %3c  |  ", i, i, i);
			fprintf("%3d  %3x  %3c  |  ", i + 26, i + 26,  ' ');
			fprintf("%3d  %3x  %3c  |  ", i + 52, i + 52, i + 52);
			fprintf("%3d  %3x  %3c  |  ", i + 78, i + 78, i + 78);
			fprintf("%3d  %3x  %3c\n", i + 104, i + 104, i + 104);
		}
		else if ((i == 7) || (i == 8) || (i == 9) || (i == 10) || (i == 11) || (i == 13)) {
			fprintf("%3d  %3x  %3c  |  ", i, i, ' ');
			fprintf("%3d  %3x  %3c  |  ", i + 26, i +26, i + 26);
			fprintf("%3d  %3x  %3c  |  ", i + 52, i + 52, i + 52);
			fprintf("%3d  %3x  %3c  |  ", i + 78, i + 78, i + 78);
			fprintf("%3d  %3x  %3c\n", i + 104, i + 104, i + 104);
		}
		else if ((i == 24) || (i == 25)) {
			fprintf("%3d  %3x  %3c  |  ", i, i, i);
			fprintf("%3d  %3x  %3c  |  ", i + 26, i + 26, i + 26);
			fprintf("%3d  %3x  %3c  |  ", i + 52, i + 52, i + 52);
			fprintf("%3d  %3x  %3c  |\n", i + 78, i + 78, i + 78);
		}
		else { 
			fprintf("%3d  %3x  %3c  |  ", i, i, i);
			fprintf("%3d  %3x  %3c  |  ", i + 26, i + 26, i + 26);
			fprintf("%3d  %3x  %3c  |  ", i + 52, i + 52, i + 52);
			fprintf("%3d  %3x  %3c  |  ", i + 78, i + 78, i + 78);
			fprintf("%3d  %3x  %3c\n", i + 104, i + 104, i + 104);
		}
	}
}

char str[100];
char* MyNameGen2(int len) {
	int i;
	srand(time(NULL));
	str[0] = MyRand(23) + 65;
	for (i = 1; i < len; i++) {
		str[i] = MyRand(23) + 97;
	}
	str[i] = 0;
	return str;
}

void MyNameGen(int len) {
	int i, n;
	srand(time(NULL));
	printf("%c", MyRand(23) + 65);
	for (i = 1; i < len; i++) {
		n = MyRand(23) + 97;
		printf("%c", n);
	}
	printf("\n");
}

int MyRand(int max) {
	int i;
	i = rand() % max + 1;
	return i;
}

void lotto() {
	int i, j, k, n, m;
	int random[MAX_NUM];
	srand(time(NULL));

	for (k = 0; k < 5; k++) {
		printf("%d 번째 로또번호 : ", k + 1);
		for (i = 0; i < MAX_NUM; i++)
		{
			n = MyRand(45);
			random[i] = n;
			for (j = 0; j < i; j++) {
				if (n == random[j]) {
					i -= 1;
					break;
				}
			}
		}
		for (m = 0; m < MAX_NUM; m++) {
			printf("%3d ", random[m]);
		}
		printf("\n");
	}

}