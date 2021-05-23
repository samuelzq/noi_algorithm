#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	int m, t, c = 1;

	cin >> m;

	// 从1开始的连加，加数最多
	// n(1+n)=m, 解二次方程，得最大可能的数量。
	// 从最大可能窗口开始缩小。
	t = (sqrt(8 * m + 1) - 1) / 2;

	for (int i = t; i >= 2; i--) {
		int d, sum = i * (1 + i) / 2;

		d = m - sum;
		if (d % i == 0) {
			d = d / i;
			cout << 1 + d << ' ' << 1 + d + i - 1 << '\n';
		}
	}
	return 0;
}
