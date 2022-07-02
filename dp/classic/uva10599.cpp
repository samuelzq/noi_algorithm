/**
 * Robots(II) UVA - 10599
 * https://vjudge.net/problem/UVA-10599
 *
 * 本题特殊之处是：虽然两个垃圾格之间可能存在多条路径，但是仅视为一条，所以和普通
 * 格子没有关系。由于格子的编号是递增的，因此可以视列编号为属性值，这样便用LIS的
 * 方法求解。找到所有可能的LIS，并记录下其中的一种。
 *
 * @File:   uva10599.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-06-28
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 10005;
struct node{
	int x, y;
} g[N];

int pre[N], dp[N], cnt[N]; // 分别为：路径、可收拾的垃圾数目、到达当前节点的路径数
int x, y, maxt = 0, pos = 0;
long long maxcnt = 0;

void output(int p)
{
	if (pre[p] != p)
		output(pre[p]);
	printf(" %d", (g[p].x - 1) * y + g[p].y);
}

bool cmp(struct node a, struct node b)
{
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

int main(void)
{
	int kase;

	kase = 1;
	while (scanf("%d %d", &x, &y) && x != -1 && y != -1) {
		int a, b, num = 0;
		num = 0;
		while (scanf("%d %d", &a, &b)) {
			if (a == 0 && b == 0)
				break;
			g[num].x = a;
			g[num].y = b;
			pre[num] = num;
			dp[num] = 1;
			cnt[num] = 1;
			num++;
		}
		sort(g, g + num, cmp);
		pos = 0;
		maxt = 0;
		maxcnt = 0;

		for (int i = 0; i < num; i++) {
			for (int j = 0; j < i; j++) {
				if (g[j].y <= g[i].y) {
					if (dp[j] + 1 > dp [i]) {
						dp[i] = dp[j] + 1;
						pre[i] = j;
						cnt[i] = cnt[j];
					} else if (dp[j] + 1 == dp[i]) {
						cnt[i] = cnt[j] + cnt[i];
					}
				}
			}

			if (dp[i] > maxt) {
				maxt = dp[i];
				maxcnt = cnt[i];
				pos = i;
			} else if (dp[i] == maxt){
				maxcnt += cnt[i];
			}
		}
		printf("CASE#%d: %d %lld", kase++, maxt, maxcnt);
		output(pos);
		printf("\n");
	}
	return 0;
}
