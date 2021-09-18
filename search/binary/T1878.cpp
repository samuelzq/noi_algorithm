#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

int a, b;
int n[100005];

/*
 * x: 两个瓶盖之间的距离
 * 统计并检测是否能够选取足够多的瓶盖，使它们之间
 * 的距离不小于。
 *
 */
bool check(int x)
{
	int tot = 1; int last = 0;
	for (int i = 1; i < a; i++) {
		if (n[i] - n[last] >= x) {
			tot++;
			last = i;
		}
	}
	if (tot >= b)
		return true;
	else
		return false;
}

int main(void)
{
	int l, r, mid, ans;
	scanf("%d%d", &a, &b);
	for(int i = 0; i < a; i++)
		scanf("%d", &n[i]);

	sort(n, n+a);

	// 折半验证可能的距离值
	r = n[a-1] - n[0];
	l = 0;
	while (l <= r) {
		mid = l + (r - l) / 2;
		if (check(mid)) {
			l = mid + 1;
			ans = mid;
		}
		else
			r = mid - 1;
	}
	printf("%d\n", ans);

	return 0;
}
