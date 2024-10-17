#include <Windows.h>
#include <stdio.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

int a[51][51];
int book[51][51],n,m,flag=0;

struct note
{
	int x;
	int y;
}s[100];

int top = 0;

void dfs(int x, int y, int front) {
	int i;

	if (x == n && y == m + 1) {
		flag = 1;
		printf("Сa��̫���ˣ����ҵ�������ˮ�ܵķ�����\n\n�����Ҳ��õ�����·�ߣ�O(��_��)O\n\n");
		for (i = 1; i <= top; i++) {
			printf("(%d,%d)", s[i].x, s[i].y);
		}
		printf("Сa����ô����Ȼ�����Ѿ�����ˣ��Ǿ��ټ��ɣ�\n\n");
		return;
	}

	if (x<1 || x>n || y<1 || y>m) {
		return;
	}

	if (book[x][y] == 1) {
		return;
	}

	book[x][y] = 1;

	top++;
	s[top].x = x;
	s[top].y = y;

	if (a[x][y] >= 5 && a[x][y] <= 6) {
		if (front == 1) {
			dfs(x, y + 1, 1);
		}
		if (front == 2) {
			dfs(x + 1, y, 2);
		}
		if (front == 3) {
			dfs(x, y - 1, 3);
		}
		if (front == 4) {
			dfs(x - 1, y, 4);
		}
	}

	if (a[x][y] >= 1 && a[x][y] <= 4) {
		if (front == 1) {
			dfs(x + 1, y, 2);
			dfs(x - 1, y, 4);
		}
		if (front == 2) {
			dfs(x, y + 1, 1);
			dfs(x, y - 1, 3);
		}
		if (front == 3) {
			dfs(x - 1, y, 4);
			dfs(x + 1, y, 2);
		}
		if (front == 4) {
			dfs(x, y + 1, 1);
			dfs(x, y - 1, 3);
		}
	}

	book[x][y] = 0;
	top--;
	return;
}

int main() {
	int i, j, num = 0;

	printf("**********��ӭ��Pipe_Game��Ϸ��**********\n");
	printf("��������ǰ��һ����ε����ر��ֳ�m*n�ĵ�λ�����Σ��������������������һЩˮ�ܣ�\n�㲻��Ҫ����Щˮ����ͨ��������Ϊ����һ��������Сa�����㡣\n");
	Sleep(1750);
	printf("\nСa����ˮ��ʱ����ѭ����ԭ��\nˮ�ܽ��Ӿ������ص����Ͻ��󲿱�Ե�����쵽���½��Ҳ���Ե��\nΪ�ˣ�����Ҫ��ϸ�����ÿ����λ�����������µ�ˮ��ʹСa�ܹ��������\n");
	Sleep(1750);
	printf("\nˮ��ֻ���������ͣ���ܺ�ֱ��\n���������״̬��ֱ��������״̬\n0��ʾ��ľ��1��2��3��4��ʾ�������״̬��5��6��ʾֱ������״̬��\n");
	Sleep(2000);
	printf("\n���ĵ�Сa��Ϊ��׼����һ��������ʾ����\n");
	Sleep(1400);
	printf("\n     5 4\n     5 3 5 3\n     1 5 3 0\n     2 3 5 1\n     6 1 1 5\n     1 5 5 4\n");
	Sleep(2000);
	printf("\n�������Сa�����ʾ�������һ����ͼ�ɣ�^_^\n");
	scanf_s("%d %d", &n, &m);

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			scanf_s("%d", &a[i][j]);
		}
	}

	dfs(1, 1, 1);

	if (flag == 0) {
		printf("Сa����ѽ�����Ҳ�����ˮ�����Ӻõķ�ʽ�R �n �Q\n");
	}

	getchar(); getchar();
	return 0;
}