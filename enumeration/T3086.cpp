// 本题如果简单暴力枚举会LTE
// 可以记录每个数出现的次数，然后利用约数关系计算组合数量

#include <iostream>

using namespace std;

int a[105] = {0, };

int gcd(int a, int b)
{
	int t;

	if (a < b) {
		t = a;
		a = b;
		b = t;
	}
	t = b;

	while (t) {
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int main(void)
{
	int n, k;
	long long ans = 0;

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		a[t]++;
	}

	for (int i = 1; i <= 100; i++) {
		int g;
		long long sum;
		if (a[i] == 0)
			continue;

		// 求k和i的最大公约数
		g = gcd(k, i);

		sum = 0;
		for (int j = i + 1; j <= 100; j++) {
			// 后面的数如果和gcd的积是否满足条件
			if (j % (k / g) == 0)
				sum += a[j];
		}
		ans += a[i] * sum;

		// 检查该数两两相乘是否满足条件
		if (i * i % k == 0)
			ans += a[i] * (a[i] - 1) / 2;
	}
	cout << ans;
	return 0;
}
