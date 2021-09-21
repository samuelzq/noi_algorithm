// 求区间和的快速方法是利用前缀和。
// 本题区间只有上限值，因此需要一个可变大小的滑动窗口。
// 首先找出前缀和中最小的单调递增队列，然后根据滑动窗口的大小求区间和。

#include <bits/stdc++.h>

using namespace std;
const int N = 5e5 + 10;
int head = 1, tail = 1;
int a[N], s[N], mq[N];

int main(void)
{
	int n, m, ans;

	cin >> n >> m;
	s[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		// 求前缀和，以便快速计算区间和
		s[i] = s[i - 1] + a[i];
	}
	ans = -0x3f7f7f7f;
	for (int i = 1; i <= n; i++) {
		// 求前缀和 中最小的单调递增序列
		while (head <= tail && s[i] <= s[mq[tail]])
			tail--;
		mq[++tail] = i;
		while (i - m > mq[head])
			head++;
		ans = max(ans, (s[i] - s[mq[head]]));
	}
	cout << ans;
	return 0;
}