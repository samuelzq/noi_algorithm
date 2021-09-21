// 首先按珠子的位置排序。
// 然后利用一个单调队列维护珠子的种类，如果头尾间珠子的总类为k，
// 则更新长度并弹出队列头部的元素。
// 一种简单的做法是使用双指针来替代单调队列。

#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+5;
struct point
{
	int type, pos;
	bool operator<(const point &tmp)const {
		return pos < tmp.pos;
	}
}p[N];
int vis[65];

int main()
{
	int n, k, cnt = 0;
	scanf("%d%d", &n, &k);

	// 接收数据，并按位置排序
	for (int i = 1, m; i <= k; i++) {
		scanf("%d", &m);
		for(int j = 0, x; j < m; j++) {
			scanf("%d", &x);
			p[cnt + 1].type = i;
			p[cnt + 1].pos = x;
			cnt++;
		}
	}
	sort(p + 1, p + cnt + 1);

	int head = 1, tail = 0, ans = 0x3f3f3f3f, sum = 0;
	for (int i = 1; i <= cnt; i++) {
		++tail;				// 等效于入队
		vis[p[i].type]++;	// 统计当前队列中个类型珠子的数量

		// 有新的类型入队
		if (vis[p[i].type] == 1)
			sum++;
		while (sum == k) {
			ans = min(ans, p[tail].pos - p[head].pos);
			vis[p[head].type]--;
			// 队列中少了一种类型的珠子
			if (vis[p[head].type]==0)
				sum--;
			// 更新队列头，由于队列是按位置排序，显然将会得到更小的值
			head++;
		}
	}
	printf("%d\n", ans);
	return 0;
}