// 如果使用模拟法，算法复杂度O(2^n)，TLE。
// 将输入数据视为满二叉树上的叶子节点，输出为根节点。
// 每次修改叶子节点后，只需更改二叉树上的一条分枝即可。
// 算法复杂度O(n)。

#include <bits/stdc++.h>

using namespace std;

const int N = 18;
int a[(1 << N) + 10];

int main(void)
{
	int n, m, l, d, c;

	cin >> n >> m;
	n = 1 << n;
	l = n << 1;
	for (int i = n; i < l; i++)
		cin >> a[i];

	d = 0;
	c = n;
	while (c > 1) {
		for (int i = c; i < (c << 1); i += 2) {
			if (d)
				a[i >> 1] = a[i] ^ a[i + 1];
			else
				a[i >> 1] = a[i] | a[i + 1];
		}
		d ^= 1;
		c >>= 1;
	}
	for (int i = 0; i < m; i++) {
		int idx, x, ans, t, d;
		cin >> idx >> x;
		if (x != a[idx + n - 1]) {
			a[idx + n  - 1] = x;
			d = 0;
			c = (idx + n - 1) & ~1;
			while (c > 1) {
				if (d)
					a[c >> 1] = a[c] ^ a[c + 1];
				else
					a[c >> 1] = a[c] | a[c + 1];
				d ^= 1;
				c = (c >> 1) & ~1;
			}
		}
		cout << a[1] << '\n';
	}
	return 0;
}
