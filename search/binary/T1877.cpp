#include <iostream>
#include <cmath>

using namespace std;

int n, m, s, a[100001], mid, r, l;

/*
 * x：分段和的最大值
 * 贪心法检测是否能够按指定大小分段
 */
bool check(int x)
{
	int i, cnt = 0, lxy = 0;

	for (i=1; i <= n; i++) {
		// 遍历所有可能的分段
		if (lxy + a[i] <= x)
			lxy += a[i];
		else // 找到新的分段
			lxy=a[i], cnt++;
	}
	return cnt >= m;
}

int main(void)
{
	int i, j, k;
	cin >> n >> m;

	for (i = 1; i <= n; i++) {
		cin >> a[i];
		// l为a数组内的最大值，根据题意a数组的最大值一定是最小的分段和
		l = max(l,a[i]);
		// 分段和不可能大于总和
		r += a[i];
	}

	while (l <= r) {
		mid=(l+r)>>1;
		if (check(mid)) // 分段过多了
			l = mid + 1;
		else // 分段少了
			r = mid - 1;
	}
	cout << l; //由于l当前最小，所以输出l而不是mid或者r
	return 0;
}
