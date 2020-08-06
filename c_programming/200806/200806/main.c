#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_NUM 6

void lotto(); // 1. 로또 프로그램
int MyRand(int max); // 2. 랜덤 난수 생성
void MyNameGen(int len); // 3. 랜덤 문자열 생성
char* MyNameGen2(int len); // 4. 랜덤 문자열 생성2

int main() {
	char* s;
	s = MyNameGen2(10);
	printf("%s", s);
	return 0;
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