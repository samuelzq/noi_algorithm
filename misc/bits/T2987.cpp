// 任何一个2的幂都可以按要求合并成1。一个数中2的幂的个数是这个数按要求合并后得到的组数。
// 如果组数满足要求，则无需添加。
// 第一个比n大的2的幂可以按要求两两合并最后成一杯。但是问题是求添加的最小值。
// n可以合并的杯数等于其二进制表示中1的个数。求得比n大的k个1的最小的数即可。

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n, k, m, t;

	cin >> n >> k;

	// 求第一个比n大的2的幂
	m = 1;
	while (m <= n)
		m <<= 1;

	// 尝试减去k个最接近于n的2的幂
	t = 1;
	while (t < k) {
		while (m > n)
			m >>= 1;
		n -= m;
		t++;
	}
	if (n == 0) {
		// 无需购买额外的杯子即可完成合并
		cout << 0;
		return 0;
	}

	// 剩余的杯子需要凑成2的幂
	m = 1;
	while (m < n)
		m <<= 1;
	cout << m - n;
	return 0;
}