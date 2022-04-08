/**
 * https://vjudge.net/problem/UVA-435
 *
 * 从n个数据中遍历长度n-1的子集Si，从Si中计算所有可能子集的和，比较这个和加上Si外
 * 的那个数据是否满足条件。
 *
 * @File:   uva435.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-04-09
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 22;
int a[N];
int b[N];
int depth;
int total;
struct party {
	int idx;
	int num;
} pp[N];

void dfs(int n, int size, int idx)
{
	if (n >= depth - 1) {
		int sum = 0;
		for (int i = 0; i < size; i++)
			sum += a[i];
		if ((sum * 2 < total) && (sum + pp[idx].num) * 2 >= total) {
#if 0
			for (int i = 0; i < size; i++) {
				printf("%d ", a[i]);
			}
			printf(" + %d (idx=%d)\n", pp[idx].num, idx);
#endif
			pp[idx].idx++;
		}
		return;
	}

	a[size] = b[n];
	dfs(n + 1, size + 1, idx);
	dfs(n + 1, size, idx);
}

int main(void)
{
	int t;

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &depth);
		total = 0;
		for (int i = 0; i < depth; i++) {
			scanf("%d", &pp[i].num);
			total += pp[i].num;
			pp[i].idx = 0;
		}

		for (int i = 0; i < depth; i++) {
			for (int j = 0, k = 0; k < depth; j++, k++) {
				if (k == i) {
					k++;
				}
				b[j] = pp[k].num;
			}
			dfs(0, 0, i);
		}
		for (int i = 0; i < depth; i++) {
			printf("party %d has power index %d\n", i + 1, pp[i].idx);
		}
		printf("\n");
	}
	return 0;
}
