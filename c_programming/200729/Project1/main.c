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
	printf("������ %d��\n", 25);
	printf("ü���� %.1f��\n", 36.5);
	printf("%s\n", "�����մϴ�.");
}
*/

/*
int main(void) {
	printf("Hello, world! \n");
	char name[10];
	int birth;
	printf("�̸��� �Է��Ͻÿ�:");
	scanf_s("%s", name, sizeof(name));
	printf("��������� �Է��Ͻÿ�:");
	scanf_s("%d", &birth);
	printf("�̸�:%s\n�������:%d", name, birth);
	return 0;
}
*/