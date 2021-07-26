#include <iostream>

using namespace std;
int mod = 32767;
int main(void)
{
	int n, k;
	int a, b, ans;

	cin >> n;

	while (n--) {
		cin >> k;
		b = 0;
		a = 1;
		ans = 0;
		for (int i = 1; i <= k; i++) {
			ans = (2 * b % mod + a) % mod;
			a = b;
			b = ans;
		}
		cout << ans << '\n';
	}
	return 0;
}