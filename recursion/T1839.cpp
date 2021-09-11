#include <iostream>

using namespace std;

int main(void)
{
	long long n, ans = 0;
	cin >> n;
	while (n > 0) {
		ans += (n + 1) / 2;
		n /= 4;
	}
	cout << ans << endl;
	return 0;
}
