#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	long long n, k, p, ans;

	cin >> k >> n;
	ans = 0;
	p = 1;
	while (n) {
		if  (n & 1)
			ans += p;
		p *= k;
		n = n >> 1;
	}
	cout << ans;
	return 0;
}