#include <iostream>

using namespace std;

int main(void)
{
	int n, ans;

	while (cin >> n && n != 0) {
		int a;
		ans = 0;
		a = n;

		while (a > 2) {
			ans += a / 3;
			a = a / 3 + a % 3;
		}

		if (a == 2)
			ans++;
		cout << ans << '\n';
	}
	return 0;
}
