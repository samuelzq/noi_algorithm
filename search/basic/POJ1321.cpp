#include <iostream>

using namespace std;

int chb[10][10] = {0, };
bool v[10] = {0, };
int n = 0;
int k = 0;
int ans = 0;

void dfs(int c, int d, int k)
{
	int i, j;
	if (k == 1) {
		for (j = 0; j <= d; j++)
		for (i = 1; i <= n; i++) {
			if (chb[c + j][i] && v[i])
				ans++;
		}
		return;
	}

	for (j = 0; j <= d; j++) {
		for (i = 1; i <= n; i++) {
			if (chb[c + j][i] && v[i]) {
				v[i] = 0;
				dfs(c + j + 1, d - j, k - 1);
				v[i] = 1;
			}
		}
	}
}

int main(void)
{
	int k;

	while (cin >> n >> k && (n != -1 && k != -1)) {
		char c;

		if (k > n) {
			cout << 0 << '\n';
			continue;
		}

		for (int i = 0; i <= n + 1; i++)
			v[i] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> c;
				if (c == '#') {
					v[j] = 1;
					chb[i][j] = 1;
				} else {
					chb[i][j] = 0;
				}
			}
		}
		ans = 0;
		dfs(1, n - k, k);
		cout << ans << '\n';
	}
	return 0;
}
