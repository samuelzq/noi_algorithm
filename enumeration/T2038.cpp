#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int idx[1005];
int req[1005];
int len[1005];

int main(void)
{
	int n, q;

	cin >> n >> q;

	for (int i = 1; i <= n; i++)
		cin >> idx[i];
	sort(&idx[1], &idx[n]);

	for (int i = 1; i <= q; i++) {
		int l, d;
		cin >> l;
		len[i] = l;
		cin >> d;
		req[i] = d;
	}


	for (int i = 1; i <= q; i++) {
		int j;
		for (j = 1; j <= n; j++) {
			int a, b, k;
			a = idx[j];
			b = req[i];
			for (k = 0; k < len[i]; k++) {
				if (a % 10 != b % 10)
					break;
				a /= 10;
				b /= 10;
			}
			if (k == len[i]) {
				cout << idx[j] << '\n';
				break;
			}
		}
		if (j > n)
			cout << -1 << '\n';
	}
	return 0;
}
