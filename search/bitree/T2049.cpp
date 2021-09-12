#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1000005;
int n, m, sum[N],l[N], r[N], a[N];

ll read()
{
	ll sum=0, f=1;
	char ch = getchar();
	while (ch > '9' || ch < '0'){
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		sum = (sum << 3) + (sum << 1) + ch - '0';
		ch = getchar();
	}
	return sum * f;
}

void dfs(int x)
{
	sum[x] = 1;
	if (l[x] != -1) {
		dfs(l[x]);
		sum[x] += sum[l[x]];
	}
	if (r[x] != -1) {
		dfs(r[x]);
		sum[x] += sum[r[x]];
	}
}

int check(int x, int y)
{
	if (x == -1 && y == -1)
		return 1;
	if (x != -1 && y != -1 &&
		a[x] == a[y] && check(l[x], r[y]) && check(r[x], l[y]))
		return 1;
	return 0;
}

int main(void)
{
//	freopen("tree.in","r",stdin);
//	freopen("tree.out","w",stdout);
	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i <= n; i++) {
		l[i] = read();
		r[i] = read();
	}
	dfs(1);
	int ans = 0;
    for (int i = 1; i <= n; i++) {
    	if (check(l[i], r[i]))
			ans = max(ans, sum[i]);
	}
	cout << ans;
	return 0;
}