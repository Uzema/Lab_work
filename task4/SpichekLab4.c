#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int check(int(x), int(y), int(n), int(m), int( **a)) {
	if ((x >= n) || (y >= m) || (x < 0) || (y < 0)) return 0;
	if (a[x][y] == 2 || a[x][y] == 0) return 0;
	if (x == (n-1) && y == (m-1)) return 1;
	if (a[x][y] == 1) {
		a[x][y] = 2;
		return check(x + 1, y, n, m, a) + check(x, y + 1, n, m, a) + check(x - 1, y, n, m, a) + check(x, y - 1, n, m, a);
	}
}

void main() {
	setlocale(LC_ALL, "RU");
	int n, m, x = 0, y = 0;

	do {
		printf("������� ����������� ����� � ��������\n");
		scanf_s("%d %d", &m, &n);
	} while ((m < 1) || (n < 1));

	int** a = malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) a[i] = (int*)malloc(m * sizeof(int));

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			do {
				printf("������� �������� �������� ������� (0 ��� 1) c ������������ %d %d\n", j, i);
				scanf_s("%d", &a[j][i]);
			} while (a[j][i] < 0 || a[j][i]>1);
		}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) printf("%d ", a[j][i]);
		printf("\n");
	}

	if (a[0][0]==0 || a[n-1][m-1]==0) printf("��� ����");
	else if (check(x, y, n, m, a) > 0) printf("���� ����");
	else printf("��� ����");
}