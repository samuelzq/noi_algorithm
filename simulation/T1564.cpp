#include <iostream>

using namespace std;

int main(void)
{
	long long n, ans;

	while (cin >> n) {
		long m = 1;
		ans = 1;
		while (m % n) {
			m = m % n * 10 + 1;
			ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}
