#include <iostream>

using namespace std;

long long gcd(long long x, long long y)
{
	if (x < y)
		return gcd(y, x);
	else {
		if (y == 0)
			return x;
		else
			return gcd(y, x % y);
	}
}

int main(void)
{
	long long n, m;
	long long ans;

	cin >> n >> m;
	ans = n * m / gcd(n, m);
	cout << ans;
	return 0;
}
