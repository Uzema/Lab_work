#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
int main() {
	// ����� ������ ������ 1(���� ���������� �����) ��� 2(��� ���������� �����)
	setlocale(LC_ALL, "Russian");
	int V;
	int W;
	int robot=0;
	int A=0;
	int right;
	int left;
	int array[1001];
	printf("������� ������� ������");
	scanf("%d%d", &left, &right);
	printf("������� ����� �� ���� �������� �� ������ ���������. 1 - ���� ���������� �����, 2 - �� ����������� ");
	scanf("%d", &V);
	if (V == 1) {
		robot = rand() % 1000;
		while (A!= robot) {
			printf("������� ����� �� ���������");
			scanf("%d", &A);
			if (A > robot) {
				printf("�������� ����������� ����� ������ ������");
			}
			else if (A < robot) {
				printf("�������� ����������� ����� ������ ������");
			}
			else if (A == robot) {
				printf("�� ������� �������� �����");
			};
		}
	}
	else {
		printf("������� �����, ������� ��������");
		scanf("%d", &A);
		robot = (right + left) / 2;
		while (robot != A) {
			printf("����� ���������� ����� ");
			printf("%d", robot);
			printf(" ���� ���� ����� ������, ������� 2. ���� ���� ����� ������, ������� 1. ���� ����� ������� �� 0) ");
			scanf("%d", &W);
			if (W == 1) {
				right = robot;
				robot = (right+left) / 2;
			}
			else if (W == 2) {
				left = robot;
				robot = (right + left) / 2
			}
		};
		printf("����� �������, ���� ����� = ");
		printf("%d", robot);
	};
	return 0;
}