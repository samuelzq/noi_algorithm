#include <iostream>

using namespace std;

int main(void)
{
	int h, u, d, ans;

	cin >> h >> u >> d;

	ans = 0;
	while (h > u) {
		h = h - u + d;
		ans++;
	}
	cout << ans + (h + (u - 1))/u;
	return 0;
}
