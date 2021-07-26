#include <iostream>
#include <algorithm>

using namespace std;

int xy[5005] = {0, };

int main(void)
{
	int ans = 0;
	int n, m, h, b;
	int x, y, j;

	cin >> n >> m >> h >> b;

	h += b;

	j = 0;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		if (x > h)
			continue;
		xy[j++] = y;
	}
	sort(xy, xy + j);
	for (int i = 0; i < j; i++) {
		if (m < xy[i])
			break;
		ans++;
		m -= xy[i];
	}
	cout << ans;
	return 0;
}
