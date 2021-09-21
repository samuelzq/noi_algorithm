// 假设海报的宽度肯定能满足要求，因此矩形的宽度不需要考虑
// 利用单调栈统计不同高度值

#include <bits/stdc++.h>

using namespace std;
int n;
int ans;

stack <int> sta;

int main(void)
{
	cin >> n;
	ans = n;

	for(int i=1; i<=n; i++) {
		int x, y;
		cin >> x >> y;

		// 剔除比当前高度高的
		while (!sta.empty() && y < sta.top())
			sta.pop();

		// 剔除登高的，此处可以使用相同海报覆盖。
		if (!sta.empty() && y == sta.top())
			ans--;

		sta.push(y);
	}

	cout << ans;
	return 0;
}