// 题目大意：
// 有N种物品和一个容量为M的背包，每种物品有重量w和价值v两种属性，
// 要求选若干个物品（每种物品只能选一次）放入背包使背包中物品的总价值最大
// 且背包中物品的总重量不超过背包的容量。

#include <algorithm>
#include <iostream>

// https://oi-wiki.org/search/heuristic/
// heuristic-search 启发式搜索
using namespace std;
const int N = 105;
int m, t, ans;
struct Node {
	int time, value;
	double f;
} node[N];

bool operator<(Node p, Node q) { return p.f > q.f; };

// f() - 估价函数。
//       根据限制条件求从起始点开始所能取得的最大值。
// idx: 估值起始点
// time: 限制值
//
// 返回：所得最大值
int f(int idx, int time)
{
	int tot = 0;
	for (int i = idx; i <= m; i++) {
		if (time >= node[i].time) {
			time -= node[i].time;
			tot += node[i].value;
		} else
			return (int)(tot + time * node[i].f);
	}
	return tot;
}

// 评估使用了深度遍历
// idx: 当前结点编号
// time: 剩余时间
// v: 当前以取得值
void dfs(int idx, int time, int v) 
{
	ans = max(ans, v);
	if (idx > m)
		return; // 可行性剪枝

	// 忽略当前结点是否能够取得更佳的解
	if (f(idx + 1, time) + v > ans)
		dfs(idx + 1, time, v);

	if (node[idx].time <= time) // 将当前结点计入，重新评估
		dfs(idx + 1, time - node[idx].time, v + node[idx].value);
}

int main()
{
	cin >> t >> m;
	for (int i = 1; i <= m; i++) {
		cin >> node[i].time >> node[i].value;
		node[i].f = 1.0 * node[i].value / node[i].time;
	}
	sort(node + 1, node + m + 1);
	dfs(1, t, 0);
	cout << ans << endl;
	return 0;
}
