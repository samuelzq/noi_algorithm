#include <iostream>

using namespace std;

char b1[502][502];
char b2[502][502];

int main(void)
{
	int t, n, a0, a1, a2, a3;
	int i, j;

	cin >> t;

	while (t--) {
		cin >> n;
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				cin >> b1[i][j];
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				cin >> b2[i][j];

		a0 = a1 = a2 = a3 = 0;
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				a0 += (b1[i][j] == b2[i][j]);
				a1 += (b1[i][j] == b2[j][n - (i - 1)]);
				a2 += (b1[i][j] == b2[n - (i - 1)][n - (j - 1)]);
				a3 += (b1[i][j] == b2[n - (j - 1)][i]);
			}
		}
		if (a0 == n * n)
			cout << 0;
		else if (a1 == n * n)
			cout << 90;
		else if (a2 == n * n)
			cout << 180;
		else if (a3 == n * n)
			cout << 270;
		else
			cout << -1;
		cout << '\n';
	}
	return 0;
}
