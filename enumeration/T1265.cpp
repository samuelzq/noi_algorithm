#include <iostream>

using namespace std;

int d[105] = {0, };

int main(void)
{
	int t, n, m, max, idx, dm;
	cin >> t;

	while (t > 0) {
		cin >> n >> m;
		t--;

		for (int i = 1; i <= n; i++)
			cin >> d[i];
		d[0] = 0;

		if (m >= n) { // 补签卡足够
			cout << 100 << '\n';
			continue;
		}

		max = 0;
		for (int i = m+1; i <= n; i++) {
			int j = i - m - 1;
			dm = d[i] - d[j] - 1;
			if (dm > max)
				max = dm;
		}
		cout << max << '\n';
	}
	return 0;
}
