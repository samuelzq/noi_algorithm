#include <bits/stdc++.h>

using namespace std;
const int N = 101;
int g[N][N];    // 有向图描述矩阵，横向表示起始点，纵向表示目标点
int arr[N];     // 该数组用于记录被查询的结点可能到达的终点结点
int v[N];       // 当前结点是否被访问过
int n;

// 查询结点p能够到达的所有结点
void check(int u)
{
	v[u] = 1;
	for (int i = 1; i <= n; i++) {
		if (g[i][u]) {
			if (!v[i])     // 避免路径循环
				check(i);
			arr[i] = 1;    // 能够到达该结点
		}
	}
}

int main(void)
{
	int i, j;

again:
	scanf("%d", &n);
	if (!n)
		return 0;

	memset(g, 0, sizeof(g));
	while (scanf("%d", &i) && i) {
		while (scanf("%d", &j) && j) {
			g[j][i] = 1;
		}
	}
	int t, q;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &q);
		memset(arr, 0, sizeof(arr));
		memset(v, 0, sizeof(v));
		check(q);

		queue<int> aq;

		for (int k = 1; k <= n; k++) {
			if (!arr[k])
				aq.push(k);
		}
		printf("%d", aq.size());
		while (aq.size()) {
			printf(" %d", aq.front());
			aq.pop();
		}
		printf("\n");
	}
	goto again;
}