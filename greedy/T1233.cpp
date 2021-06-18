#include <iostream>
#include <algorithm>

using namespace std;

int c[20004] = {0, };

int main(void)
{
	int n, b, h, ans;

	cin >> n >> b;
	for (int i = 0; i < n; i++)
		cin >> c[i];

	sort(c, c + n);
	h = ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		h += c[i];
		ans++;
		if (h >= b)
			break;
	}
	cout << ans;
	return 0;
}
