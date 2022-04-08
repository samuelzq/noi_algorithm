/**
 * Another Puzzling Problem UVA - 399
 * https://vjudge.net/problem/UVA-399
 *
 * 递推所有的排列，找到符合要求的排列组合。
 *
 * @File:   uva399.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-04-08
 *
 **/
#include <bits/stdc++.h>

using namespace std;

enum {
	TOP = 0,
	LEFT,
	BOTTOM,
	RIGHT,
	MAX_EDGE
};

// 每一片拼图
struct piece{
	int w, d;
	char p[26][26];
	int a[MAX_EDGE];
} pp[101];

// 用一个矩阵记录可能的排列方案
struct {
	int a[MAX_EDGE];
	int idx;
} solution[12][12];

int used[101];
int w, d, h;
bool finished;

char *get_line(char *buf)
{
	int c, i;
	i = 0;
	while ((c = getchar()) != EOF && c != '\n')
		buf[i++] = c;
	buf[i + i] = 0;
	return buf + i;
}

// 检测排列中新插入的一项是否正确
bool check(int i, int j)
{
	if (solution[i][j].a[TOP] + solution[i - 1][j].a[BOTTOM] != 0 ||
	    solution[i][j].a[LEFT] + solution[i][j - 1].a[RIGHT] != 0)
		return false;
	return true;
}

void print_solution(void)
{
	for (int i = 1; i <= w; i++) {
		for (int j = 0; j < d; j++) {
			for (int k = 1; k < w; k++)
				printf("%.*s", h, pp[solution[i][k].idx].p[j]);
			printf("%s\n", pp[solution[i][w].idx].p[j]);
		}
	}
}

void dfs(int n)
{
	if (n >= w * w) {
		finished = true;
		print_solution();
		return;
	}

	for (int i = 0; i <= w * w; i++) {
		int x, y;
		if (used[i])
			continue;
		x = n / w + 1;
		y = n % w + 1;
		solution[x][y].a[0] = pp[i].a[0];
		solution[x][y].a[1] = pp[i].a[1];
		solution[x][y].a[2] = pp[i].a[2];
		solution[x][y].a[3] = pp[i].a[3];
		if (check(x, y) == false)
			continue;
		used[i] = 1;
		solution[x][y].idx = i;
		dfs(n + 1);
		used[i] = 0;
		if (finished == true)
			return;
	}
}

int main(void)
{
	int t;

	scanf("%d", &t);
	while (t--) {
		memset(pp, 0, sizeof(pp));
		scanf("%d %d %d", &w, &d, &h);
		getchar();
		for (int i = 0; i < w * w; i++) {
			for (int j = 0; j < d; j++)
				get_line(pp[i].p[j]);
			pp[i].w = d;
			pp[i].d = h;
			scanf("%d %d %d %d", &pp[i].a[0], &pp[i].a[1], &pp[i].a[2], &pp[i].a[3]);
			getchar();
			getchar();
		}

		dfs(0);
		if (t >= 1)
			printf("\n");
	}
	return 0;
}
