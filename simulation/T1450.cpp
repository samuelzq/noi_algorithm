#include <iostream>

using namespace std;

int main(void)
{
	int n, m, i, j, ans;

	cin >> n >> m;

	ans = 0;
	for (i = 1; i < n; i++) {
		if (i >= m)
			break;
		for (j = i + 1; j <= n; j++) {
			if (j + i > m)
				break;
			else if (j + i == m)
				ans++;
		}
	}
	cout << ans;
	return 0;
}
