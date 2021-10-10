#include <bits/stdc++.h>

using namespace std;
const int N = 10004;

int x[N], y[N];

bool check(int xy[], int l)
{
	int mid, i, t = (l - 1) / 2;

	if (l & 1)
		mid = 2 * xy[t];
	else
		mid = xy[t] + xy[t + 1];

	for (i = 0; i < t; i++) {
		if (mid != xy[i] + xy[l - i - 1])
			break;
	}

	if (i == t)
		return true;
	else
		return false;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	while (n--) {
		int t;
		scanf("%d", &t);
		for (int i = 0; i < t; i++) {
			scanf("%d %d", &x[i], &y[i]);
		}
		sort(x, x + t);
		sort(y, y + t);
		if (check(x, t) && check(y, t))
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}