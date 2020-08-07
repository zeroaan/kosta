#include <stdio.h>
#include <string.h>
#include "E:\\programming\\c_programming\\myheader.h"

int find(char* str, char c); // 1. 인수인 문자 c를 문자열 str에서 찾아서 그 위치 인덱스를 되돌려 준다.
int find_s(char* str, char* cstr); // 2. 인수인 문자열 c를 문자열 str에서 찾아서 그 위치 인덱스를 되돌려 준다.
int ccount(char* str, char c); // 3. 문자열 str에서 문자 c의 갯수 세기
char* GetToken(int index, char* str, char c); // 4. 문자열 str에서 구분자 c로 각각 구분되는 문자열 중 index 번째의 문자열(data)를 되돌려준다.
char* token(char* str, char c); // 5. 위 GetToken 함수에서 해당 index 인 문자열을 만든다.

int main() {
	/*
	int index;
	char* s = "abcdefg";
	index = find_s(s, "def");
	if (index == -1) { printf("해당 문자를 찾을 수 없습니다.\n\n"); }
	else { printf("해당 문자의 인덱스는 %d 입니다.\n\n", index); }

	int count;
	char* s2 = "abcavfaf";
	count = ccount(s2, 'z');
	printf("해당 문자의 갯수는 %d개 입니다.\n\n", count); 
	*/

	char* s3 = "one,two,three,four,five,six";
	char c = ',';
	
	printf("'%c' 기준으로 문자열을 나누기\n\n", c);
	for (int i = 0; i < ccount(s3, c) + 1; i++) {
		printf("%d번째 문자열 : %s\n", i + 1, GetToken(i, s3, c));
	}

	// int n = 3;
	// char* result = GetToken(n, s3, c);
	// if (result == NULL) { printf("index가 너무 크거나 작습니다.\n"); }
	// else { printf("해당 index 번째 문자열은 [%s] 입니다.\n", result); }

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
// 해당하는 index 문자열만 value에 넣기
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

// 문자열 str에서 구분자 c로 각각 구분되는 문자열 중
// index 번째의 문자열(data)를 되돌려준다.
char* GetToken(int index, char* str, char c) {
	// index 인수가 해당 문자열 인덱스를 넘을 때 NULL 리턴
	if (index > ccount(str, c) || index < 0) {
		return NULL;
	}

	// index가 0일 때 맨 앞 문자열 바로 리턴
	if (index == 0) {
		return token(str, c);
	}

	// index가 1 이상일 때
	int i = 0;
	while (*str) {
		str += find(str, c) + 1;
		i++;
		if (i == index) {
			return token(str, c);
		}
	}
}