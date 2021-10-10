// 扫描线

#include <bits/stdc++.h>

using namespace std;

struct func {
	double x, val;
};
const int N = 105;
const double EPS = 1e-6;
struct func f[N], g[N];

void input(struct func fc[], int n)
{
	int i;
	double cnt = 0.0;
	for (i = 0; i < n; i++) {
		scanf("%lf %lf", &fc[i].val, &fc[i].x);
		fc[i].x += cnt;
		cnt = fc[i].x;
	}
}

int main()
{
	int fn,gn;
	while (scanf("%d", &fn) != EOF)	{
		input(f, fn);
		scanf("%d", &gn);
		input(g, gn);
		int i = 0, j = 0;
		double ans = max(g[0].val, f[0].val);
		double pos = 0.0;

		// 扫描线一段一段找
		while (i < fn && j < gn) {
			ans = min(ans, max(f[i].val, g[j].val));
			if (g[j].x - f[i].x > EPS)
				i++;
			else
				j++;
		}
		printf("%.3f\n",ans);
	}
	return 0;
}