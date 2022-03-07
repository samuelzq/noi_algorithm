#include <bits/stdc++.h>

using namespace std;

int vc[11];
int vr[11];
int vhe[41];
int vht[31];
int ans[11];

void dfs(int n, int r)
{
	if (r == n) {
		ans[n]++;
		return;
	}

	for (int c = 0; c < n; c++) {
		if (!vr[r] && !vc[c] && !vhe[r - c + n] && !vht[r + c]) {
			vr[r] = 1;
			vc[c] = 1;
			vhe[r - c + n] = 1;
			vht[r + c] = 1;
			dfs(n, r + 1);
			vr[r] = 0;
			vc[c] = 0;
			vhe[r - c + n] = 0;
			vht[r + c] = 0;

		}
	}
}

int main(void)
{
	int n;
	memset(ans, -1, sizeof(ans));
	while (cin >> n && n != 0) {
		if (ans[n] != -1) {
			cout << ans[n] << '\n';
			continue;
		}
		ans[n] = 0;
		dfs(n, 0);
		cout << ans[n] << '\n';
	}
	return 0;
}
