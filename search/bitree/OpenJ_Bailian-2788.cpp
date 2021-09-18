#include <bits/stdc++.h>

using namespace std;

int pow2(int n)
{
	int p = 1;
	while (n--)
		p *= 2;
	return p;
}

int main(void)
{
	int n, m;
	int ans, l, p;

	while (cin >> m >> n) {
		int x, y;
		if (!m || !n)
			return 0;
		x = m, y = n;

		ans = 1;
		l = 1;
		y = x = m;
		// 累加每一层结点数，直到终止结点所在的层
		while (x < n) {
			p = pow2(l++);
			ans += p;
			x = x * 2 + 1;
			y = y * 2;
		}

		if (y > n)    // 结束结点不是子树的叶子结点，此时多计算了一层
			ans -= p;
		else {		  // 结束结点是子树的叶子，减去多算的结点
			while (x > n) {
				ans--;
				x--;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}