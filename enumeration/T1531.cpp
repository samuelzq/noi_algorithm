#include <iostream>

using namespace std;

int main(void)
{
	int n, m, ans, i;

	i = 0;
	while (cin >> n >> m && (n != 0 && m != 0)) {
		ans = 0;
		for (int a = 1; a < n - 1; a++) {
			for (int b = a + 1; b < n; b++) {
				int x, y;
				x = a*a + b*b + m;
				y = a*b;

				if (x % y == 0)
					ans++;
			}
		}
		cout << "Case " << ++i << ": " << ans << '\n';
	}
	cout << endl;
	return 0;
}
