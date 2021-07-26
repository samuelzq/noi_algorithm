#include <iostream>
#include <algorithm>

using namespace std;

int p[102] = {0, };

int main(void)
{
	int n, ans = 0;

	while (cin >> n && n) {
		for (int i = 0; i < n; i++)
			cin >> p[i];

		sort(p, p + n);
		ans = 0;
		for (int i = 0; i < n / 2 + 1; i++) {
			ans += p[i] / 2 + 1;
		}
		cout << ans << '\n';
	}
	return 0;
}
