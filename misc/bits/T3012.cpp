#include <bits/stdc++.h>

using namespace std;
const int N = 2e5+5;
int a[N];

int main(void)
{
	int n;
	int ans;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	ans = a[n - 1] & a[n - 2];
	if (ans != 0) {
		ans = max(ans, a[n - 2] & a[n - 3]);
	} else {
		for (int i = n - 1; i >= 1; i--) {
			for (int j = i - 1; j >= 0; j--) {
				int t = a[i] & a[j];
				if (t > ans) {
					cout << t;
					return 0;
				}
			}
		}
	}

	cout << ans;
	return 0;
}