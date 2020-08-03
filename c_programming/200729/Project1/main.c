#include <stdio.h>

int main(void) {
	printf("[%-7.2f]\n", 1.234);
	printf("[%-7.2f]\n", 20.0567);
	printf("[%-7.2f]\n", 35.0345);
	printf("[%-7.2f]\n", 420.123);
}

/*
int main(void) {
	printf("[%-5d]\n", 1);
	printf("[%-5d]\n", 20);
	printf("[%-5d]\n", 35);
	printf("[%-5d]\n", 420);
	printf("[%-5d]\n", 5182);
}
*/

/*
int main(void) {
	printf("My name is Ahn Jin Young!\n");
	printf("오늘은 %d일\n", 25);
	printf("체온은 %.1f도\n", 36.5);
	printf("%s\n", "감사합니다.");
}
*/

/*
int main(void) {
	printf("Hello, world! \n");
	char name[10];
	int birth;
	printf("이름을 입력하시오:");
	scanf_s("%s", name, sizeof(name));
	printf("생년월일을 입력하시오:");
	scanf_s("%d", &birth);
	printf("이름:%s\n생년월일:%d", name, birth);
	return 0;
}
*/