#include <iostream>

using namespace std;

int main(void)
{
	int n, ans = 0;

	cin >> n;

	while (n = n >> 1)
		ans++;
	cout << ans;
	return 0;
}
