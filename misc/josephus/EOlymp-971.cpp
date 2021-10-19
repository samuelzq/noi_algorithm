// a O(klogn) solution

#include <bits/stdc++.h>

using namespace std;

int josephus(int n, int k)
{
	if (n == 1)
		return 0;
	if (k == 1)
		return n-1;
	if (k > n)
		return (josephus(n-1, k) + k) % n;

	int cnt = n / k;
	int res = josephus(n - cnt, k);

	res -= n % k;
	if (res < 0)
		res += n;
	else
		res += res / (k - 1);
	return res;
}

int main(void)
{
	int n, k;

	scanf("%d %d", &n, &k);
	printf("%d\n", josephus(n, k) + 1);
	return 0;
}
