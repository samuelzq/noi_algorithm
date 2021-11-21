#include <bits/stdc++.h>

using namespace std;

const int N = 1003;
struct node {
	int x, y;
};
struct node a[N];

int main(void)
{
	int t;

	scanf("%d", &t);
	while (t--) {
		int n, i, l, r;
		scanf("%d", &n);
		l = r = 0;
		for (i = 0; i < n; i++) {
			int x;
			scanf("%d %d", &x, &a[i].y);
			if (x < a[l].x)
				l = i;
			if (x > a[r].x)
				r = i;
			a[i].x = x;
		}
		int m = a[l].x + a[r].x;

		for (i = 0; i < n; i++) {
			int j;
			for (j = 0; j < n; j++) {
				if (a[j].y != a[i].y)
					continue;
				if (a[j].x + a[i].x == m)
					break;
			}
			if (j >= n)
				break;
		}
		if (i >= n)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}