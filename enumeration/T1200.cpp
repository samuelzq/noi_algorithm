#include <iostream>
#include <algorithm>

using namespace std;

int ans[1000];

int main(void)
{
	int n, m = 0;
	int a, b, c;
	int s;

	cin >> n;

	for (a = 1; a <= n; a++) {
		if (n % a != 0)
			continue;
		s = n / a;
		for (b = a; b <= s; b++) {
			if (s % b != 0)
				continue;
			c = s / b;

			// 计算此时的表面积
			ans[m] = 2*(a*b+b*c+c*a);
			m++;
		}
	}

	// 从小到大排序
	sort(&ans[0], &ans[m]);
	cout << ans[0];
	return 0;
}
