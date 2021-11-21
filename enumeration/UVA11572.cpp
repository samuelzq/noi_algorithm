// 最长不重复子序列
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+3;
int a[N];

int main(void)
{
	int t;

	scanf("%d", &t);
	while (t--) {
		int n, ans;
		scanf("%d", &n);

		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		map<int, int> mp;

		ans = 0;
		for (int start = 0, end = 0; end < n; end++) {
			if (mp.find(a[end]) != mp.end()) {
				start = max(start, mp[a[end]]);
				mp[a[end]] = end + 1;
			} else
				mp.insert(pair<int, int>(a[end], end + 1));
			ans = max(end - start + 1, ans);
		}
		printf("%d\n", ans);
	}
	return 0;
}