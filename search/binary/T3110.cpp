#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1003;
long long a[N];

int main(void)
{
	long long n, k, l, r, ans;

	cin >> n >> k;

	ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> a[j];
		sort(a, a + n);

		l = 0;
		r = n - 1;
		while (l < r) {
			if (k == a[l] + a[r]) {
				ans++;
				break;
			}
			else if (k < a[l] + a[r])
				r--;
			else
				l++;
		}
	}
	cout << ans;
	return 0;
}
