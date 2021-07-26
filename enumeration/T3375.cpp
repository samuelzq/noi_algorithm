#include <iostream>

using namespace std;
int t[1005];

int main(void)
{
	int x, n, ans = 0;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
		ans += t[i];
	}
	cin >> x;
	for (int i = x + 1; i <= n; i++) {
		ans += t[i];
	}
	cout << ans;
	return 0;
}
