#include <iostream>

using namespace std;

int main(void)
{
	int n;

	cin >> n;
	while (n--) {
		long long v, ans = 0;
		int t;
		cin >> t;
		v = 1;
		while (t--) {
			ans += v;
			ans %= 10000;
			v += 2;
			v %= 10000;
		}
		cout << ans << '\n';
	}
	return 0;
}
