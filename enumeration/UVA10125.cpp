// 依次选取最大的数和a，
// 利用二分法查找b、c

#include <bits/stdc++.h>

using namespace std;

#define LL long long
const int N = 1002;
LL d[N];

int main(void)
{
	bool f = false;
	int t;

	while (scanf("%d", &t) && t) {
		for (int i = 0; i < t; i++)
			scanf("%lld", &d[i]);
		sort(d, d + t);
		f = false;
		for (int i = t - 1; i >= 0 && f == false; i--) {
			for (int j = t - 1; j >= 0 && f == false; j--) {
				if (j == i)
					continue;
				LL m = d[i] - d[j];
				int l, r;
				// 二分法查找
				l = 0;
				r = j - 1;
				while (l < r) {
					if (m ==  d[l] + d[r]) {
						printf("%lld\n", d[i]);
						f = true;
						break;
					} else if (m < d[l] + d[r]) {
						r--;
					} else {
						l++;
					}
				}
			}
		}
		if (f == false)
			printf("no solution\n");
	}
	return 0;
}