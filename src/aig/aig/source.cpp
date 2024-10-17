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
		printf("小a：太好了！我找到了连接水管的方案！\n\n这是我采用的连接路线：O(∩_∩)O\n\n");
		for (i = 1; i <= top; i++) {
			printf("(%d,%d)", s[i].x, s[i].y);
		}
		printf("小a：那么，既然任务已经完成了，那就再见吧！\n\n");
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

	printf("**********欢迎玩Pipe_Game游戏！**********\n");
	printf("现在你面前有一块矩形的土地被分成m*n的单位正方形，请你在这块土地上埋设一些水管，\n你不需要将这些水管连通起来，因为会有一名机器人小a来帮你。\n");
	Sleep(1750);
	printf("\n小a连接水管时会遵循如下原则：\n水管将从矩形土地的左上角左部边缘，延伸到右下角右部边缘。\n为此，你需要仔细地设计每个单位正方形中埋下的水管使小a能够完成任务！\n");
	Sleep(1750);
	printf("\n水管只有两种类型：弯管和直管\n弯管有四种状态，直管有两种状态\n0表示树木；1，2，3，4表示弯管四种状态；5，6表示直管两种状态。\n");
	Sleep(2000);
	printf("\n贴心的小a还为你准备了一份他做的示例：\n");
	Sleep(1400);
	printf("\n     5 4\n     5 3 5 3\n     1 5 3 0\n     2 3 5 1\n     6 1 1 5\n     1 5 5 4\n");
	Sleep(2000);
	printf("\n请你仿照小a给你的示例，设计一个地图吧！^_^\n");
	scanf_s("%d %d", &n, &m);

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			scanf_s("%d", &a[i][j]);
		}
	}

	dfs(1, 1, 1);

	if (flag == 0) {
		printf("小a：哎呀！我找不到让水管连接好的方式≧ ﹏ ≦\n");
	}

	getchar(); getchar();
	return 0;
}