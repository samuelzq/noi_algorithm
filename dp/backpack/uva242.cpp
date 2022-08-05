/**
 * Stamps and Envelope Size UVA - 242
 * https://vjudge.net/problem/UVA-242
 *
 * 设bs[i]为用不超过i枚邮票能凑成的面值集合，正在放进的邮票面值为j，
 * 则有状态更新公式：bs[i+1]=bs[i]|(bs[i]<<j)
 *
 * @File:   uva242.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-07-26
 *
 **/
#include <bits/stdc++.h>

using namespace std;
bitset<1010>  c[11];

bool cmp(vector<int> &v1, vector<int> &v2)
{
	if (v1.size() == v2.size()) {
		for (int i = v1.size() - 1; i >= 0; i--) {
			if (v1[i] == v2[i])
				continue;
			return v1[i] > v2[i];
		}
		return true;
	} else {
		return v1.size() > v2.size();
	}
}

int coverage(int k, vector<int> &v)
{
	int n = v.size();

	for (int i = 1; i <= k; i++)
		c[i].reset();

	for (int i = 0; i < n; i++)
		c[1].set(v[i], 1);

	for (int i = 0; i < n; i++) {
		for (int j = 2; j <= k; j++)
			c[j] |= c[j - 1] | c[j - 1] << v[i];
	}

	int i = 1;
	while (c[k].test(i))
		i++;

	return i - 1;
}

int main(void)
{
	int s;

	while (scanf("%d", &s) != EOF && s) {
		int n;
		scanf("%d", &n);
		vector<vector<int>> stamps;
		stamps.clear();
		for (int i = 0; i < n; i++) {
			int g;
			scanf("%d", &g);
			vector<int> stamp(g);
			for (int j = 0; j < g; j++) {
				int t;
				scanf("%d", &t);
				stamp[j] = t;
			}
			sort(stamp.begin(), stamp.end());
			stamps.push_back(stamp);
		}
		sort(stamps.begin(), stamps.end(), cmp);

		int k, ans = 0;
		for (int i = 0; i < stamps.size(); i++) {
			int tmp;
			tmp = coverage(s, stamps[i]);
			if (tmp >= ans) {
				ans = tmp;
				k = i;
			}
		}
		printf("max coverage = %3d :", ans);

		for (int i = 0; i < stamps[k].size(); i++)
			printf("%3d", stamps[k][i]);
		printf("\n");
	}
	return 0;
}
