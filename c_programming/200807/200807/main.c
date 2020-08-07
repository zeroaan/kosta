#include <stdio.h>
#include <string.h>
#include "E:\\programming\\c_programming\\myheader.h"

int find(char* str, char c); // 1. �μ��� ���� c�� ���ڿ� str���� ã�Ƽ� �� ��ġ �ε����� �ǵ��� �ش�.
int find_s(char* str, char* cstr); // 2. �μ��� ���ڿ� c�� ���ڿ� str���� ã�Ƽ� �� ��ġ �ε����� �ǵ��� �ش�.
int ccount(char* str, char c); // 3. ���ڿ� str���� ���� c�� ���� ����
char* GetToken(int index, char* str, char c); // 4. ���ڿ� str���� ������ c�� ���� ���еǴ� ���ڿ� �� index ��°�� ���ڿ�(data)�� �ǵ����ش�.
char* token(char* str, char c); // 5. �� GetToken �Լ����� �ش� index �� ���ڿ��� �����.

int main() {
	/*
	int index;
	char* s = "abcdefg";
	index = find_s(s, "def");
	if (index == -1) { printf("�ش� ���ڸ� ã�� �� �����ϴ�.\n\n"); }
	else { printf("�ش� ������ �ε����� %d �Դϴ�.\n\n", index); }

	int count;
	char* s2 = "abcavfaf";
	count = ccount(s2, 'z');
	printf("�ش� ������ ������ %d�� �Դϴ�.\n\n", count); 
	*/

	char* s3 = "one,two,three,four,five,six";
	char c = ',';
	
	printf("'%c' �������� ���ڿ��� ������\n\n", c);
	for (int i = 0; i < ccount(s3, c) + 1; i++) {
		printf("%d��° ���ڿ� : %s\n", i + 1, GetToken(i, s3, c));
	}

	// int n = 3;
	// char* result = GetToken(n, s3, c);
	// if (result == NULL) { printf("index�� �ʹ� ũ�ų� �۽��ϴ�.\n"); }
	// else { printf("�ش� index ��° ���ڿ��� [%s] �Դϴ�.\n", result); }

	return 0;
}

int find(char* str, char c) {
	int i = 0;
	for (i = 0; i < (int)strlen(str) + 1; i++) {
		if (str[i] == c) { return i; }
	}
	/*
	while (*str) {
		if (*str == c) { return i; }
		str++; i++;
	}*/
	return -1;
}

int find_s(char* str, char* cstr) {
	int i, j;
	char value[100];
	for (i = 0; i < (int)strlen(str) + 1; i++) {
		if (str[i] == cstr[0]) {
			for (j = 0; j < (int)strlen(cstr) + 1; j++) {
				if (str[i + j] != cstr[j]) { break; }
				value[j] = str[i + j];
			}
			value[j] = 0;
		}
		if (strcmp(value, cstr) == 0) { return i; }
	}
	return -1;
}

int ccount(char* str, char c) {
	int i = 0;
	while (*str) {
		if (*str == c) i++;
		str++;
	}
	return i;
}

char value[100];
// �ش��ϴ� index ���ڿ��� value�� �ֱ�
char* token(char* str, char c) {
	for (int i = 0; i < (int)strlen(str) + 1; i++) {
		if (str[i] == c) {
			value[i] = 0;
			break;
		}
		value[i] = str[i];
	}
	return value;
}

// ���ڿ� str���� ������ c�� ���� ���еǴ� ���ڿ� ��
// index ��°�� ���ڿ�(data)�� �ǵ����ش�.
char* GetToken(int index, char* str, char c) {
	// index �μ��� �ش� ���ڿ� �ε����� ���� �� NULL ����
	if (index > ccount(str, c) || index < 0) {
		return NULL;
	}

	// index�� 0�� �� �� �� ���ڿ� �ٷ� ����
	if (index == 0) {
		return token(str, c);
	}

	// index�� 1 �̻��� ��
	int i = 0;
	while (*str) {
		str += find(str, c) + 1;
		i++;
		if (i == index) {
			return token(str, c);
		}
	}
}