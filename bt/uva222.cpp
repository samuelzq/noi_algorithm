/**
 * Budget Travel UVA - 222
 * https://vjudge.net/problem/UVA-222
 *
 * 根据进站的条件，遍历当前停靠之后每一个加油站。
 *
 * @File:   uva222.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-04-04
 *
 **/
#include <bits/stdc++.h>

using namespace std;
const int N = 52;
const double det = 1e-7;
double dist[N], p[N];
int stops;
double dd, cap, mpg, cost, ans;

void dfs(int d, double dst, double cst)
{
	if (d == stops || (dst + cap * mpg >= dd)) {
		if (cst < ans)
			ans = cst;
		return;
	}

	for (int i = d; i < stops; i++) {
		double fused = (dist[i] - dst) / mpg;
		if ((fused >= cap / 2.0 || dist[i] + (cap - fused) * mpg < dist[i + 1]) &&
			 fused <= cap)
			 dfs(i + 1, dist[i], cst + 2.0 + fused * p[i] / 100.0);
	}
}

int main(void)
{
	int t = 0;
	while (scanf("%lf", &dd) && dd >= 0) {
		scanf("%lf %lf %lf %d", &cap, &mpg, &cost, &stops);
		ans = 0;
		for (int i = 0; i < stops; i++) {
			scanf("%lf %lf", &dist[i], &p[i]);
			ans += p[i] * cap;
		}
		dist[stops] = dd;
		dfs(0, 0, 0);
		printf("Data Set #%d\n", ++t);
		printf("minimum cost = $%.2lf\n", ans + cost);
	}
	return 0;
}
