#include <iostream>

using namespace std;

int a[52] = {0, };

int main(void)
{
	int n, l, r, sum, l1, r1;

	cin >> n;
	sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	cin >> l >> r;
	l1 = r1 = 0;
	if (sum < l * n || sum > r * n)
		cout << -1;
	else {
		for (int i = 0; i < n; i++) {
			if (a[i] < l)
				l1 += l - a[i];
			if (a[i] > r)
				r1 += a[i] - r;
		}
		cout << (l1 > r1 ? l1 : r1);
	}
	return 0;
}
