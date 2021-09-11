// 如果前r个房间没有暖气，则无解。
// 如果前r个房间中有暖气，则在检测最后一个有暖气的房间之后的
// 2r-1个房间中是否有暖气。如果无，则无解。如果有，则重复这一
// 检测流程。

#include <iostream>

using namespace std;
int t[1004] = {0, };

int main(void)
{
	int n, r, i, j, l, k;
	bool f = false;
	int ans = 0;

	cin >> n >> r;
	for (i = 1; i <= n; i++)
		cin >> t[i];
	if (r >= n) {
		cout << -1;
		return 0;
	}

	k = 0;
	j = 2 * r - 1;
	i = l = 0;

	/* 检测头部的r个房间 */
	for (l = r; l > 0; l--) {
		if (t[l])
			break;
	}
	if (l == 0) {
		cout << -1;
		return 0;
	}

	/* 以2r-1为区间，循环检测是否有房间中存在暖气 */
	ans = 1;
	while (l + r - 1 < n) {
		k = l;
		if (l + j > n)
			l = n;
		else
			l += j;

		i = l;
		while (!t[i] && i > k)
			i--;
		if (i == k) {
			cout << -1;
			return 0;
		} else {
			ans++;
			l = i;
		}
	}
	cout << ans;
	return 0;
}
