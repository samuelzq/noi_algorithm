#include <iostream>
#include <algorithm>

using namespace std;

const int N=1e5+5;
int a[N];

int main(void)
{
	int n, m, l, r;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);

	cin >> m;
	l = 0;
	r = n - 1;
	while (l < r) {
		int t = a[l] + a[r];
		if (t == m) {
			cout << a[l] << ' ' << a[r];
			return 0;
		} else if (t > m) {
			r--;
		} else {
			l++;
		}
	}
	cout << "No";
	return 0;
}
