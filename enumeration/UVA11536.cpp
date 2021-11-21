// 通过使用左右指针找最短序列
#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
int a[1000006], q[1003];

int main(void)
{
	int n, m, k, t;
	int ans;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		ans = INF;
		scanf("%d %d %d", &n, &m, &k);
		memset(q, 0, sizeof(q));
		for (int j = 1; j <= n; j++) {
			if (j >= 4)
				a[j] = (a[j - 1] + a[j - 2] + a[j - 3]) % m + 1;
			else
				a[j] = j;
		}

		int l, r;
		l = r = 1;
		int s = 0;
		while (1) {
			while (s < k && r <= n) {
				if (a[r] <= k && q[a[r]] == 0)
					s++;
				q[a[r]]++;
				r++;
			}

			while (s == k) {
				ans = min(r - l, ans);
				if (a[l] <= k && q[a[l]] == 1)
					s--;
				q[a[l]]--;
				l++;
			}
			if (r > n)
				break;
		}
		printf("Case %d: ", i);
		if (ans == INF)
			printf("sequence nai\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}