/**
 * Almost Union-Find UVA - 11987
 * https://vjudge.net/problem/UVA-11987
 *
 * 需要从并查集中删除指定的元素。
 * 由于不能够保证集合的路径被完美压缩过，因此不能简单将某结点的父结点
 * 设未0。可以将每一个节点放到一个盒子中，集合中彼此相连接的是盒子，
 * 盒子中可以没有结点。当一个结点被从集合中删除时，相当于从当前盒子中
 * 移到一个空余的盒子中。
 *
 * 完美的算法需要考虑空盒子的回收和重复利用。本题中由于操作次数有限，
 * 可以预先准备足够数量的盒子。
 *
 * @File:   uva11987.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-09-15
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 200005;
int p[N];     // 描述集合的表，集合中可能链接有空盒子
long long int sum[N];
int num[N];
int id[N];    // 结点当前所在的盒子
int idx = 0;

int find(int x)
{
	if (x == p[x])
		return x;
	else {
		int px = find(p[x]);
		return p[x] = px;
	}
}

void merge(int x, int y)
{
	int px, py;

	px = find(id[x]);
	py = find(id[y]);

	sum[py] += sum[px];
	num[py] += num[px];
	sum[px] = 0;
	num[px] = 0;
	p[px] = py;
}

void move(int x)
{
	int xx = id[x];
	int px = find(xx);

	sum[px] -= x;
	num[px] -= 1;
	id[x] = ++idx;
	sum[id[x]] = x;
	num[id[x]] = 1;
	p[id[x]] = id[x];
}

int main(void)
{
	int n, m;

	while (cin >> n >> m) {
		for (int i = 1; i <= n; i++) {
			num[i] = 1;
			sum[i] = p[i] = id[i] = i;
		}
		idx = n;

		for (int i = 0; i < m; i++) {
			int op, p1;

			cin >> op >> p1;
			if (op == 3) {
				int pp;
				pp = find(id[p1]);
				cout << num[pp] << ' ' << sum[pp] << '\n';
			} else if (op == 1) {
				int p2;
				cin >> p2;
				if (find(id[p1]) != find(id[p2]))
					merge(p1, p2);
			} else if (op == 2) {
				int p2;
				cin >> p2;
				if (find(id[p1]) != find(id[p2])) {
					move(p1);
					merge(p1, p2);
				}
			}
		}
	}
	return 0;
}
