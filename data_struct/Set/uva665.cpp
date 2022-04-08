/**
 * False coin UVA - 665
 * https://vjudge.net/problem/UVA-665
 *
 * 由于只有一个伪币，它肯定出现在每一个失衡的结果中。
 * 建立两个集合：
 * 1、使天平平衡的硬币。
 * 2、使天平失衡的硬币。失衡时，假设每一个未出现在集合1中的硬币都是伪造的。
 *    每在失衡结果中出现一次，则记一次数（轻-1，重+1）。
 * 最后查询集合2中哪个硬币计数的绝对值等于失衡的次数，如果计数为负则轻，反之重。
 *
 * @File:   uva665.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-01-01
 *
 **/

#include <bits/stdc++.h>

using namespace std;
const int N = 101;
int g[N];    // golden
int f[N];    // false
string str;
stringstream ss;
int main(void)
{
	int t;
	getline(cin, str);
	ss << str;
	ss >> t;
	while (t--) {
		int n, k, cmp;
		memset(g, 0, sizeof(g));
		memset(f, 0, sizeof(f));
		getline(cin, str);
		getline(cin, str);
		ss.clear();
		ss << str;
		ss >> n >> k;
		cmp = 0;
		for (int i = 0; i < k; i++) {
			int p;
			getline(cin, str);
			ss.clear();
			ss << str;
			ss >> p;
			getline(cin, str);
			if (str[0] == '=') {
				for (int j = 0; j < 2 * p; j++) {
					int q;
					ss >> q;
					g[q] = 1;
					f[q] = 0;
				}
			} else if (str[0] = '<') {
				for (int j = 0; j < p; j++) {
					int q;
					ss >> q;
					if (g[q] != 1)
						f[q]--;
				}
				for (int j = 0; j < p; j++) {
					int q;
					ss >> q;
					if (g[q] != 1)
						f[q]++;
				}
				cmp++;
			} else {
				for (int j = 0; j < p; j++) {
					int q;
					ss >> q;
					if (g[q] != 1)
						f[q]++;
				}
				for (int j = 0; j < p; j++) {
					int q;
					ss >> q;
					if (g[q] != 1)
						f[q]--;
				}
				cmp++;
			}
		}
		int cc = 0, ff = 0;

		// 特殊情况：输入中只有平衡的结果
		for (int i = 1; i <= n; i++) {
			if (!g[i]) {
				cc++;
				ff = i;
			}
		}
		if (cc != 1) {
			cc = 0;
			for (int i = 1; i <= n; i++) {
				if (abs(f[i]) == cmp) {
					ff = i;
					cc++;
				}
			}
		}
		if (cc == 1)
			cout << ff << '\n';
		else
			cout << "0\n";
		if (t != 0)
			cout << '\n';
	}
	return 0;
}