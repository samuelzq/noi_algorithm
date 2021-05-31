#include <iostream>

using namespace std;

const int s[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main(void)
{
	int n, ans = 0;

	cin >> n;

	for (int i = 0; i <= 2000; i++) {
		for (int j = 0; j <= 2000; j++) {
			int c, d, e;
			c = i + j;
			e = 0;
			do {
				d = c % 10;
				e += s[d];
				c /= 10;
			} while (c != 0);
			c = i;
			do {
				d = c % 10;
				e += s[d];
				c /= 10;
			} while (c != 0);
			c = j;
			do {
				d = c % 10;
				e += s[d];
				c /= 10;
			} while (c != 0);
			if (e + 4 == n) {
				// cout << i << '+' << j << '=' << i+j << '\n';
				ans += 1;
			}
		}
	}
	cout << ans;
	return 0;
}
