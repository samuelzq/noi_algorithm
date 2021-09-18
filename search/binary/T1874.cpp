#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5+5;
int a[N];

int main(void)
{
	int m, n;
	long long ans;

	cin >> m >> n;

	for (int i = 0; i < m; i++)
		cin >> a[i];
	sort(a, a + m);

	ans = 0;
	while (n--) {
		int s, l, r, mid;
		cin >> s;

		l = 0;
		r = m - 1;

		if (s < a[l]) {
			ans += a[l] - s;
			continue;
		} else if (s > a[r]) {
			ans += s - a[r];
			continue;
		}
		while (l <= r) {
			mid = l + (r - l) / 2;
			if (a[mid] == s)
				break;
			else if (a[mid] > s)
				r = mid - 1;
			else if (a[mid < s])
				l = mid + 1;
		}
		if (a[mid] == s) {
			continue;
		} else {
			int t1, t2;
			t1 = s - a[r];
			t2 = a[l] - s;

			if (t1 > t2)
				ans += t2;
			else
				ans += t1;
		}
	}
	cout << ans;
	return 0;
}
