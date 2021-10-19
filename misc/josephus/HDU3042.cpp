#include <bits/stdc++.h>

using namespace std;

// n：初始个数 h：添加了几轮(也是高度) q：询问点
// 第一个循环节: n ∗ 2^(hh − 1) + 1 + ll
// hh在每次移到左右子树的时候加1，
// 走到左子树的时候 ll ∗ = 2 ，
// 走到右子树的时候 ll = ll * 2 + 1。
//后续循环节加上2的幂乘上循环节的个数来解决
int cal(int n, int h, int q)
{
	int ans = 0;
	int loop, k, b;

	if (h == 0)
		return q;

	loop = 1 << h;
	k = (q - 1 + loop) / loop;
	b = q % loop;

	// search_tree
	if (b == 1)
		return k;

	if (b == 0)
		b = loop;
	b--;   // [1, loop-1]
	int al = loop - 1;
	int hh, ll = 0, hh = 1;
	//在左边的是al个，需要找到第b个
	for (hh = 1; hh <= h; hh++) {
		al--;
		al /= 2;
		if (b < al + 1) { // 左子树
			ll *= 2;
		} else if (b > al + 1) { // 右子树
			b -= al + 1;
			ll = ll * 2 + 1;
		} else {   // 找到
			break;
		}
	}
	int p2 = 1 << (i - 1);
	return p2 * n + ll + 1 + (k - 1) * p2;
	
}

int main(void)
{
	int n, k, q;

	while (scanf("%d %d %d", &n, &k, &q) != EOF) {
		int base = 1;  //用int也A了
		int r = 0;

		while (n * base < k) {
			r++;
			base *= 2;
		}
		int qq, ans;
		while (q--) {
			scanf("%d", &qq);
			int temp = k % (n * base / 2);
			if (temp == 0 || qq <= temp * 2) {
				ans = cal(n, r, qq);
			} else {
				ans = cal(n, r - 1, qq - temp);
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
