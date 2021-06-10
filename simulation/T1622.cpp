#include <iostream>

using namespace std;

short d[245][245] = {0};

int main(void)
{
	int n, m, r, ans;

	cin >> n >> m >> r;

	ans = 0;
	while (r--) {
		int x1, y1, x2, y2;

		cin >> x1 >> y1 >> x2 >> y2;

		for (int i = x1; i <= x2; i++) {
			for (int j = y1; j <= y2; j++) {
				if (d[i][j])
					continue;
				else {
					d[i][j] = 1;
					ans++;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
