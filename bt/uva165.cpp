/**
 * https://vjudge.net/problem/UVA-165
 *
 * 暴力枚举。
 * 设stamp[i]为第i张邮票面额，maxstamp[i]为这i张邮票可以组成的最大连续值。
 * 则stamp[i]的取值范围是stamp[i-1]+1 ~ maxstamp[i-1]+1。
 * 因此首先枚举出stamp[i]的范围，然后在该范围内枚举可能的最大连续值。
 *
 * @File:   uva165.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-05-10
 *
 **/
#include <bits/stdc++.h>

using namespace std;

int h, k, maxval;
int stamp[10];
int maxstamp[10];
int ans[10];
vector<bool> check;

// 枚举stamp[i]可能的最大值
void dfs(int cur, int index, int sum)
{
	if (cur == h) {
		check[sum] = true;
		return;
	}

	check[sum] = true;
	for (int i = 0; i <= index; ++i)
		dfs(cur + 1, index, sum + stamp[i]);
}

// 枚举可能的最大连续值
void search(int index)
{
	if (index == k) {
		if (maxstamp[index - 1] > maxval) {
			maxval = maxstamp[index - 1];
			for (int i = 0; i < k; i++)
				ans[i] = stamp[i];
		}
		return;
	}

	for (int i = stamp[index - 1] + 1; i <= maxstamp[index - 1] + 1; ++i) {
		check.assign(200, false);
		stamp[index] = i;

		dfs(0, index, 0);

		int j = 0, num = 0;
		while (check[++j])
			++num;
		maxstamp[index] = num;

		search(index + 1);
	}
}

int main()
{
	while (scanf("%d %d", &h, &k) != EOF && h && k) {
		memset(stamp, 0, sizeof(stamp));
		memset(maxstamp, 0, sizeof(maxstamp));
		maxval = 0;
		stamp[0] = 1;
		maxstamp[0] = h;

		search(1);

		for (int i = 0; i < k; i ++)
			printf("%3d", ans[i]);
		printf(" ->%3d\n", maxval);
	}

	return 0;
}
