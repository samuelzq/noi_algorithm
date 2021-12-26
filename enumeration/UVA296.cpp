#include <bits/stdc++.h>

using namespace std;

const int G = 11;
int num[G];
int f1[G];
int f2[G];

int main(void)
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m, ans;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d %d/%d", &num[i], &f1[i], &f2[i]);
		m = ans = 0;

		for (int i = 0; i < 10000; i++) {
			int j;
			for (j = 0; j < n; j++) {
				int bp = 0, st = 0;
				int temp = i;
				int p = 0;
				int a = num[j];
				// 检查位置匹配的数字个数
				for (int k = 0; k < 4; k++) {
					int c = temp % 10;
					int b = a % 10;
					if (c == b) {
						p++;
						st |= 1 << k;
					}
					temp /= 10;
					a /= 10;
				}
				if (p != f1[j])
					break;

				// 检查位置不匹配的数字个数
				p = 0;
				temp = i;
				bp = 0;
				for (int k = 0; k < 4; k++) {
					// 依次取i的每一位，和提示中不同的位比较
					int c = temp % 10;
					a = num[j];
					temp /= 10;

					// 跳过完美匹配位
					if (st & (1 << k))
						continue;
					for (int r = 0; r < 4; r++) {
						int b = a % 10;
						a /= 10;
						if (r == k || bp & (1 << r) || st & (1 << r))
							continue;
						if (c == b) {
							p++;
							bp |= 1 << r;
							break;
						}
					}
				}
				if (p != f2[j])
					break;
			}
			if (j == n) {
				//printf("%d\n", i);
				ans = i;
				m++;
			}
		}
		if (m == 0)
			printf("impossible\n");
		else if (m == 1)
			printf("%04d\n", ans);
		else
			printf("indeterminate\n");
	}
	return 0;
}