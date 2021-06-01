#include <iostream>

using namespace std;

int main(void)
{
	long long x, n, ans;
	cin >> x >> n;
	ans = 1;
	for (int i = 0; i < n; i++)
		ans *= (1 + x);
	cout << ans;
	return 0;
}
