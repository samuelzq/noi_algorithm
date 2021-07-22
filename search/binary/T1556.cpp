#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5+5;
int a[N];

int main(void)
{
	int n, m, x;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	while (m--) {
		int l, r, mid;
		cin >> x;

		l = 0;
		r = n - 1;
		if (x <= a[l]) {
			cout << -1 << '\n';
			continue;
		} else if (x > a[r]) {
			cout << a[r] << '\n';
			continue;
		}

		while (l <= r) {
			mid = l + (r - l) / 2;
			if (a[mid] == x)
				r = mid - 1;
			else if (a[mid] > x)
				r = mid - 1;
			else if (a[mid] < x)
				l = mid + 1;
		}
		cout << a[r] << '\n';
	}
	return 0;
}
