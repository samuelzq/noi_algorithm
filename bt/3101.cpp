// 题中有一个陷阱，深搜的时候是按列输出的，不是行输出.

#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+6;
int vc[N], vld[N+N], vrd[N+N];
int bq[N];
int ans = 0;

void dfs(int n, int r)
{
	if (ans)
		return;
	if (r == n) {
		for (int j = 0; j < n; j++)
			cout << bq[j] << '\n';
		ans++;
		return;
	}

	for (int c = 0; c < n; c++) {
		if (vc[c] || vld[c + r] || vrd[c - r + n - 1])
			continue;
		bq[r] = c + 1;
		vc[c] = 1;
		vld[c + r] = 1;
		vrd[c - r + n - 1] = 1;
		dfs(n, r + 1);
		vc[c] = 0;
		vld[c + r] = 0;
		vrd[c - r + n - 1] = 0;
	}
	return;
}

int main(void)
{
	int n;
	cin >> n;
	dfs(n, 0);
	//cout << ans << '\n';
	return 0;
}
