// 根据提示，计数最终会形成一个循环结，该循环有两种形式：
// 1、循环起始点为0；
// 2、循环起始点不是0。
// 循环中的被点到的序列即为出队的序号。
// 找到循环的中的起点，统计循环中所有序号的个数即可。

#include <bits/stdc++.h>

using namespace std;

long long f(long long x, long long a, long long b, long long mod)
{
	long long r;

	r = x * x % mod;
	r = r * a % mod;
	r = (r + b) % mod;
	return r;
}

int main(void)
{
	long long n, a, b;

	while (scanf("%lld", &n) != EOF && n != 0) {
		long long h, t, len;

		scanf("%lld %lld", &a, &b);

		// 快速前进，找到第一个被重复计数的位置
		h = t = 0;
		do {
			h = f(f(h, a, b, n), a, b, n);
			t = f(t, a, b, n);
		} while (h != t);

		// 找到第一个被计数3次的位置，它即为循环的起始点
		// 第一个2次计数的位置为0，则3次重合仍然是该位置
		h = 0;
		while (h != t) {
			// 找到第一个3次重合的位置
			h = f(h, a, b, n);
			t = f(t, a, b, n);
		}

		// 统计循环中数据的个数
		len = 0;
		do {
			h = f(h, a, b, n);
			len++;
		} while (h != t);
		printf("%lld\n", n - len);
	}
	return 0;
}
