/**
 * Dollars UVA - 147
 * https://vjudge.net/problem/UVA-147
 *
 * 完全背包，求零钱凑整方案。
 * 将300以内所有方案一次性推出，然后依次输出答案。
 *
 * @File:   uva147.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-07-25
 *
 **/
#include <bits/stdc++.h>

using namespace std;
const int N = 30003;
int price[11] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
long long c[N];

void change(int m)
{
	memset(c, 0, sizeof(c));
	c[0] = 1;

	for (int i = 0; i < 11; ++i)
		for (int j = price[i]; j <= m; ++j)
			c[j] += c[j-price[i]];

	// cout << "湊得價位" << m;
	// cout << "湊法總共" << c[m] << "種";
}

int main(void)
{
	int a, b;
	c[0] = 1;
	change(30000);

	while (scanf("%d.%d", &a, &b)) {
		int m = a * 100 + b;
		if (m == 0)
			break;
		printf("%3d.%02d%17lld\n", a, b, c[m]);
	}
	return 0;
}
