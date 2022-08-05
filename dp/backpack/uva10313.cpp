/**
 * Pay the Price UVA - 10313
 * https://vjudge.net/problem/UVA-10313
 *
 * 这个题目涉及到一个结论，用不超过j个硬币凑出面值i的方案种数，是和用面值不超过j
 * 的硬币凑出面值i的方案种数是相同的。说得再数学一点，就是整数i拆分成不超过j个整
 * 数的拆分数，是和整数i拆成若干个值不超过j的整数的拆分数是相同的。具体的证明用到
 * 了Ferrers图像的性质。
 *
 * 这样的话我们就可以取一个二维数组f[i][j]表示用面值不超过j的硬币凑出面值i的方案
 * 的种数，那么如果我使用了面值j，对应方案种数就应该加上f[i-j][j]，如果我们不使用
 * 面值j，那么对应的方案种数就应该加上f[i][j-1]。也就是说状态转移方程为
 * f[i][j]= f[i-j][j]+ f[i][j-1]。
 *
 * @File:   uva10313.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-07-26
 *
 **/
#include <bits/stdc++.h>

using namespace std;
long long dp[305][305];
char buf[512];

int get_line(void)
{
	int i = 0;
	char c = getchar();
	while ((c != '\n') && c != EOF) {
		buf[i++] = c;
		c = getchar();
	}
	buf[i] = 0;
	return i;
}

int main(void)
{
	long long ans;

	dp[0][0] = 1;
	for (int i = 0; i <= 300; i++) {
		for (int j = 1; j <= 300; j++) {
			if (j <= i)
				dp[i][j] = dp[i - j][j] + dp[i][j - 1];
			else
				dp[i][j] = dp[i][j - 1];

		}
	}

	while (get_line()) {
		int l[3], i;
		char *p;
		p = strtok(buf, " ");
		i = 0;
		while (p) {
			l[i] = atoi(p);
			p = strtok(NULL, " ");
			i++;
		}
		l[1] = l[1] > 300 ? 300 : l[1];
		l[2] = l[2] > 300 ? 300 : l[2];
		ans = 0;
		if (i == 1)
			ans = dp[l[0]][l[0]];
		else if (i == 2) {
			ans = dp[l[0]][l[1]];
		} else {
			ans = dp[l[0]][l[2]] - dp[l[0]][l[1] - 1];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
