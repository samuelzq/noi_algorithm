#include <iostream>
#include <algorithm>

using namespace std;

int d[100005];

bool cmp(int a, int b)
{
	return a > b;
}

int main(void)
{
	int n, m, g, ans, t;

	cin >> n >> m;
	t = g = ans = 0;

	for (int i = 0; i < n; i++) {
		int s, c;
		cin >> s >> c;
		d[i] = s - c;
		g += s;
		t += c;
	}
	if (t > m) {
		cout << -1;
	} else {
		sort(d, d + n, cmp);
		for (int i = 0; i < n; i++) {
			ans++;
			g -= d[i];
			if (g <= m)
				break;
		}
		cout << ans;
	}
	return 0;
}
