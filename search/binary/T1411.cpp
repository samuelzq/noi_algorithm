#include <iostream>

using namespace std;

int main(void)
{
	int m, n, ans;

	cin >> m;
	while (m--) {
		cin >> n;
		ans = 0;
		while (n > 1) {
			if (n % 2)
				ans++;
			ans++;
			n /= 2;
		}
		cout << ans << '\n';
	}
	return 0;
}
