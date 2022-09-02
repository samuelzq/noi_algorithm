/**
 * Jill Rides Again UVA - 507
 * https://vjudge.net/problem/UVA-507
 *
 * 贪心法。累计总和，遇到负值就重新计数。
 *
 * @File:   uva507.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-08-29
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int S = 20005;
int a[S];

// 找出其中一個Maximum Sum Subarray的位置（最左邊的）
int maximum_sum_subarray(int r, int l)
{
	int max_sum = 0, sum = 0;
	int start = 1, end = 0, temp_start = 2;

	for (int i = 2; i <= l; ++i) {
		sum += a[i];

		if (sum < 0) {
			sum = 0;
			temp_start = i+1;   // 重新設定起點是下一個數字
			continue;
		}

		if (sum > max_sum) {
			max_sum = sum;
			start = temp_start - 1;
			end = i;
		} else if (sum == max_sum) {
			if (i - temp_start + 1 > end - start) {
				start = temp_start - 1;
				end = i;
			}
		}
	}

	if (start >= end)
		printf("Route %d has no nice parts\n", r);
	else
		printf("The nicest part of route %d is between stops %d and %d\n",
			r, start, end);

	return max_sum;
}

int main(void)
{
	int t;

	scanf("%d", &t);
	for (int j = 1; j <= t; j++) {
		int s;
		scanf("%d", &s);

		a[0]= a[1] = 0;
		for (int i = 2; i <= s; i++)
			scanf("%d", &a[i]);

		maximum_sum_subarray(j, s);
	}
	return 0;
}
