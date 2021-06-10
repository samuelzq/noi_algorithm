#include <iostream>

using namespace std;

int main(void)
{
	int l, r, ans;

	cin >> l >> r;

	ans = 0;
	for (int i = l; i <= r; i++) {
		int t = i;
		while (t) {
			if (t % 10 == 7)
				ans++;
			t /= 10;
		}
	}
	cout << ans;
	return 0;
}
