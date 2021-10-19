#include <bits/stdc++.h>

using namespace std;

long long josephus(long long n, long long k)
{
	if (n == 2)
		return 1 - (k & 1);
	if (k == 1)
		return n - 2;
	if (k > n)
		return (josephus(n - 1, k) + k) % n;

	long long cnt = n / k;
	long long ret = josephus(n - cnt, k);
	ret -= n % k;
	if (ret < 0)
		ret += n;
	else
		ret += ret / (k - 1);
	return ret;
}

int main(void)
{
	long long n, k;
	while (scanf("%lld %lld", &n, &k) != EOF && n != 0 && k != 0) {
		printf("%lld\n", josephus(n, k) + 1);
	}
	return 0;
}
