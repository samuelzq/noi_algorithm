/**
 * 砝码称重 计蒜客 - T2178
 * https://vjudge.net/problem/%E8%AE%A1%E8%92%9C%E5%AE%A2-T2178
 *
 * 多重背包问题。背包总负重量是砝码可以组成的最大重量。
 * 将多重背包转换成0-1背包，记录可以装入的所有可能重量，然后统计种类。
 *
 * @File:   T2178.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-07-06
 *
 **/
#include <iostream>

using namespace std;

int dp[1005];
int w[7] = {0, 1, 2, 3, 5, 10, 20};
int num[7];

// 遍历每一类物品中的每一个
void knapsack(int t)
{
	dp[0] = 1;
	for (int i = 1; i<= 6; i++) {
		for (int k = 1; k <= num[i]; k++)
			for (int j = t; j >= w[i]; j--)
				if (dp[j - w[i]])
					dp[j] = 1;
	}
}

// 将同类物品按1、2、4、8、…… 、2^k、M-2^k打包。它们之间按0-1组合，可以
// 组合出各种数量的物品。
void knapsack2(int t)
{
	dp[0] = 1;
	for (int i = 1; i<= 6; i++) {
		int n = min(num[i], t / w[i]);
		for (int k = 1; n > 0; k *= 2) {
			if (k > n)
				k = n;
			n -= k;
			for (int j = t; j >= k * w[i]; j--)
				if (dp[j - k*w[i]])
					dp[j] = 1;
		}
	}
}

int main(void)
{
	int t, sum = 0;
	for (int i = 1; i <= 6; i++) {
		cin >> num[i];
		sum += num[i] * w[i];
	}

	knapsack2(sum);

	t = 0;
	for (int i = 1; i <= sum; i++)
		if (dp[i])
			t++;
	cout << "Total=" << t;
	return 0;
}
