/**
 * The jackpot UVA - 10684
 * https://vjudge.net/problem/UVA-10684
 *
 * 求最大连续子区间的和。
 *
 * @File:   uva10684.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-08-30
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 10005;
int a[N];

int largest_sum(int l)
{
	int sum = 0, max_sum = 0;

	for (int i = 0; i < l; i++) {
		sum += a[i];

		if (sum < 0)
			sum = 0;

		if (sum > max_sum)
			max_sum = sum;
	}
	return max_sum;
}

int main(void)
{
	int n, sum;

	while (1) {
		scanf("%d", &n);
		if (!n)
			break;

		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);

		sum = largest_sum(n);
		if (sum > 0)
			printf("The maximum winning streak is %d.\n",  sum);
		else
			printf("Losing streak.\n");

	}
	return 0;
}
