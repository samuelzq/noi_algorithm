// 题目描述
// 输出自然数 11 到 nn 所有不重复的排列，即 nn 的全排列，
// 要求所产生的任一数字序列中不允许出现重复的数字。

#include <iostream>
#include <iomanip>

using namespace std;

#define N        0x10000
bool vis[N];  // 访问标记数组
int a[N];     // 排列数组，按顺序储存当前搜索结果
int n;

void dfs(int step)
{
	if (step == n + 1) {  // 边界
		for (int i = 1; i <= n; i++) {
			cout << setw(5) << a[i];
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++) {
		// 在每一级，遍历剩余的所有数字
		if (vis[i] == 0) {
			vis[i] = 1;
			a[step] = i;
			dfs(step + 1);
			vis[i] = 0;
		}
	}
	return;
}

int main()
{
	cin >> n;
	dfs(1);
}
