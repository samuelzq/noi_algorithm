#include <iostream>

using namespace std;

int main(void)
{
	int t;

	cin >> t;
	while (t--) {
		int n, m, d, ans;
		cin >> n >> m;
		if (n > m) {
			d = m;
			m = n;
			n = d;
		}
		ans = 0;
		if (n % 2 == 0)
			ans = (n / 2 - 1) * 4 + 2;
		else
			ans = n / 2 * 4;
		cout << ans << '\n';
	}
	return 0;
}
