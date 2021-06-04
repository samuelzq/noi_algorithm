#include <iostream>

using namespace std;

int main(void)
{
	int m, k, ans;

	cin >> m >> k;

	ans = 0;
	while (m) {
		if (m >= k) {
			m = m - k + 1;
			ans += k;
		} else {
			ans += m;
			m = 0;
		}
	}
	cout << ans;
	return 0;
}

