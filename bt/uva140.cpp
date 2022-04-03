/**
 * https://vjudge.net/problem/UVA-140
 *
 * 按照字典序生成节点的全排列，然后分别计算最大带宽
 *
 * @File:   uva140.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-03-10
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 9;
char node[N];
char v[N];
char out[27];
char cc[27];
int used[N];
int mp[27][27];
int max_d = 0;
int ans = 9;

int get_bandwidth(void)
{
	int len = 1;
	for (int i = 0; i < max_d - 1; i++) {
		for (int j = i + 1; j < max_d; j++) {
			int x, y;
			x = v[i] - 'A';
			y = v[j] - 'A';
			if (mp[x][y])
				len = max(j - i, len);
		}
	}
	return len;
}

void backtrack(int d)
{
	if (d == max_d) {
		int t = get_bandwidth();
		if (ans > t) {
			ans = t;
			memcpy(out, v, max_d);
//			cout << out << ' ' << ans << '\n';
		}
		return;
	}

	for (int i = 0; i < max_d; i++) {
		int idx = node[i] - 'A';
		if (!used[i]) {
			used[i] = 1;
			v[d] = node[i];
			backtrack(d + 1);
			used[i] = 0;
		}
	}
}

int main(void)
{
	string str;
	while (cin >> str && str[0] != '#') {
		int s = 0;
		int x, y;
		memset(mp, 0, sizeof(mp));
		memset(out, 0, sizeof(out));
		memset(cc, 0, sizeof(out));
		memset(v, 0, sizeof(v));
		memset(node, 0, sizeof(node));
		memset(used, 0, sizeof(used));
		max_d = 0;
		ans = 9;
		for (int i = 0; i < str.length(); i++) {
			char c = str[i];
			if (c >= 'A' && c <= 'Z') {
				if (cc[c - 'A'] == 0) {
					cc[c - 'A'] = 1;
					node[max_d++] = c;
				}
			}

			if (s == 0) {
				s = 1;
				x = c - 'A';
				i++;
			} else {
				if (c != ';') {
					y = c - 'A';
					mp[y][x] = mp[x][y] = 1;
				} else {
					s = 0;
				}
			}
		}
		sort(node, node + max_d);
		backtrack(0);
		for (int i = 0; i < max_d; i++)
			cout << out[i] << ' ';
		cout << "-> " << ans << endl;
	}
}
