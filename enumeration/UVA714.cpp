// 先利用二分法找到一个合适的分组总量。
// 然后再根据这个值进行分组。

#include <bits/stdc++.h>

using namespace std;

const int M = 505;
int b[M];
int last[M];

// 统计分组总量为pages时，分组的数量
int devide_book(int n, long long pages)
{
	int ans = 1;
	long long total = 0;
	for (int i = 0; i < n; i++) {
		if (total + b[i] <= pages) {
			total += b[i];
		} else {
			total = b[i];
			ans++;
		}
	}
	return ans;
}

void output(int n, int k, long long pages)
{
	long long total = 0;

	for (int i = n - 1; i >= 0 && k > 0; i--) {
		if (total + b[i] <= pages && i >= k) {
			total += b[i];
		} else {
			total = b[i];
			last[i] = 1;
			k--;
		}
	}

	for (int i = 0; i < n - 1; i++) {
		printf("%d ", b[i]);
		if (last[i]) {
			printf("/ ");
			last[i] = 0;
		}
	}
	printf("%d", b[n - 1]);
}

int main(void)
{
	int t;

	scanf("%d", &t);
	while (t--) {
		int m, k, maxp;
		long long total;
		scanf("%d %d", &m, &k);

		maxp = 0;
		total = 0;
		for (int i = 0; i < m; i++) {
			scanf("%d", &b[i]);
			total += b[i];
			maxp = max(maxp, b[i]);
		}

		long long l, r, mid;
		l = maxp;
		r = total;
		while (l < r) {
			mid = l + (r - l) / 2;
			if (devide_book(m, mid) <= k)
				r = mid;
			else
				l = mid + 1;
		}
		//printf("%d\n", l);
		output(m, k - 1, l);
		printf("\n");
	}
	return 0;
}