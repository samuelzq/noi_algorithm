#include <iostream>

using namespace std;

int main(void)
{
	int t, ans;
	long long n, k, m;

	cin >> t;

	while (t--) {
		cin >> n >> k;
		m = 2 * k - 1;

		ans = n / m * 2;
		n = n % m;
		if (n > k)
			ans += 2;
		else if (n != 0)
			ans += 1;
		cout << ans << '\n';
	}
	return 0;
}
