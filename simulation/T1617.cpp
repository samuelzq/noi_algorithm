#include <iostream>

using namespace std;

int main(void)
{
	long long n, k, ans;

	cin >> n >> k;

	ans = 0;
	while (n >= k) {
		ans += k;
		n -= k - 1;
	}
	ans += n;
	cout << ans;
	return 0;
}
