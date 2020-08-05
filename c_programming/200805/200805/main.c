#include <stdio.h>
#include <stdlib.h>
#define STU_MAX 5
#define MAN_NUM 3

void test(); // 1. ȥ�� �ǽ�
void struct_test(); // 2. ����ü �ǽ�
void score_array(); // 3. ������ �ߴ� ���� �Է� ������ ����ü�� �����
void score_array2(); // 3. ������ �ߴ� ���� �Է� ������ ����ü�� �����
int rank_count(float avg[], int i); // 4. ������ �ߴ� ���� ���ϱ�

struct person {
	char name[20];
	char phone[20];
	int age;
};

int main() {
	score_array2();

	return 0;
}

void test() {

}

void struct_test() {
	struct person man[MAN_NUM];
	struct person* pMan;
	pMan = man;

	for (int i = 0; i < MAN_NUM; i++) {
		printf("�̸��� ��ȭ��ȣ�� �Է��ϼ��� (%d/%d) : \n", i + 1, MAN_NUM);
		scanf_s("%s %s", man[i].name, sizeof(man[i].name), man[i].phone, sizeof(man[i].phone));
		printf("\n");
	}

	printf("%5s %20s %20s\n", " ", "�̸�", "��ȭ��ȣ");
	for (int i = 0; i < MAN_NUM; i++) {
		printf("%5s %20s %20s\n", " ", (&pMan[i])->name, (*(pMan + i)).phone);
	}

	/*
	for (int i = 0; i < MAN_NUM; i++) {
		printf("%d��° ����� �̸��� %s �Դϴ�.\n", i + 1, (&pMan[i])->name);
		printf("��ȭ��ȣ�� %s �Դϴ�.\n\n", (*(pMan + i)).phone);
	}
	*/

	/*
	// ����ü ���� 1
	printf("name : %s\n", man[0].name);
	printf("phone : %s\n", man[0].phone);

	// ����ü ���� 2
	printf("name : %s\n", (pMan[1]).name);
	printf("phone : %s\n", (*(pMan+1)).phone);

	// ����ü ���� 3
	printf("name : %s\n", (&pMan[2])->name);
	printf("phone : %s\n", (pMan+2)->phone);
	*/
}

int rank_count(float avg[], int i) {
	int count = 1;
	for (int j = 0; j < STU_MAX; j++) {
		if (avg[i] < avg[j]) {
			count += 1;
		}
	}
	return count;
}

struct student {
	char name[10];
	float kor;
	float eng;
	float math;
	float sum;
	float avg;
	int rank;
};

void score_array2() {
	struct student stu[STU_MAX];
	struct student* pStu;
	pStu = stu;

	float sum[STU_MAX], avg[STU_MAX];
	int rank[STU_MAX];

	for (int i = 0; i < STU_MAX; i++) {
		printf("\n�л� �̸�(%d/%d) : ", i + 1, STU_MAX);
		scanf_s("%s", stu[i].name, sizeof(stu[i].name));
		printf("���� ������ �Է��ϼ���. : ");
		scanf_s("%f", &stu[i].kor);
		printf("���� ������ �Է��ϼ���. : ");
		scanf_s("%f", &stu[i].eng);
		printf("���� ������ �Է��ϼ���. : ");
		scanf_s("%f", &stu[i].math);
	}

	for (int i = 0; i < STU_MAX; i++) {
		sum[i] = stu[i].kor + stu[i].eng + stu[i].math;
		avg[i] = sum[i] / 3;
	}

	for (int i = 0; i < STU_MAX; i++) {
		rank[i] = rank_count(avg, i);
	}

	printf("\n%s\n", "  ---------------------------------------------------------------------");
	printf("%s %10s %8s %8s %8s %8s %8s %8s",
		" ", "�̸�", "����", "����", "����", "����", "���", "���");
	printf("\n%s\n", "  ---------------------------------------------------------------------");

	// ������ ���
	for (int i = 0; i < STU_MAX; i++) {
		for (int j = 0; j < STU_MAX; j++) {
			if (rank[j] == i + 1) {
				printf("%s %10s %8.2f %8.2f %8.2f %8.2f %8.2f %7d\n",
					" ", (pStu + j)->name, (pStu + j)->kor, (pStu + j)->eng, (pStu + j)->math, sum[j], avg[j], rank[j]);
			}
		}
	}

	// �Է� ������� ���
	/*
	for (int i = 0; i < student; i++) {
	printf("\n%10s �л� : %8.2f  %8.2f  %8.2f  %8.2f  %8.2f  %4d\n",
	name[i], score[i][0], score[i][1], score[i][2], sum[i], avg[i], rank[i]);
	}*/
	printf("%s\n", "  ---------------------------------------------------------------------");
}

void score_array() {
	struct student stu[STU_MAX];
	struct student* pStu;
	pStu = stu;

	float avg_rank[STU_MAX];

	for (int i = 0; i < STU_MAX; i++) {
		printf("\n�л� �̸�(%d/%d) : ", i+1, STU_MAX);
		scanf_s("%s", stu[i].name, sizeof(stu[i].name));
		printf("���� ������ �Է��ϼ���. : ");
		scanf_s("%f", &stu[i].kor);
		printf("���� ������ �Է��ϼ���. : ");
		scanf_s("%f", &stu[i].eng);
		printf("���� ������ �Է��ϼ���. : ");
		scanf_s("%f", &stu[i].math);
	}

	for (int i = 0; i < STU_MAX; i++) {
		(*(pStu + i)).sum = stu[i].kor + stu[i].eng + stu[i].math;
		(*(pStu + i)).avg = (*(pStu + i)).sum / 3;
	}

	for (int i = 0; i < STU_MAX; i++) {
		(*(pStu + i)).rank = rank_count(avg_rank, i);
	}

	printf("\n%s\n", "  ---------------------------------------------------------------------");
	printf("%s %10s %8s %8s %8s %8s %8s %8s",
		" ", "�̸�", "����", "����", "����", "����", "���", "���");
	printf("\n%s\n", "  ---------------------------------------------------------------------");

	// ������ ���
	for (int i = 0; i < STU_MAX; i++) {
		for (int j = 0; j < STU_MAX; j++) {
			if ((*(pStu + j)).rank == i + 1) {
				printf("%s %10s %8.2f %8.2f %8.2f %8.2f %8.2f %7d\n",
					" ", (pStu + j)->name, (pStu + j)->kor, (pStu + j)->eng, (pStu + j)->math, (pStu + j)->sum, (pStu + j)->avg, (pStu + j)->rank);
			}
		}
	}

	// �Է� ������� ���
	/*
	for (int i = 0; i < student; i++) {
	printf("\n%10s �л� : %8.2f  %8.2f  %8.2f  %8.2f  %8.2f  %4d\n",
	name[i], score[i][0], score[i][1], score[i][2], sum[i], avg[i], rank[i]);
	}*/
	printf("%s\n", "  ---------------------------------------------------------------------");
}