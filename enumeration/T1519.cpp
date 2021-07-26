#include <iostream>

using namespace std;

int main(void)
{
	int t, ans = 0;

	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;
		ans = 0;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j + i <= n; j++) {
				int k = n - i - j;
				if (i + 2 * j + 5 * k == m)
					ans++;
			}
		}
		cout << ans << '\n';
	}
	cout << endl;
	return 0;
}
