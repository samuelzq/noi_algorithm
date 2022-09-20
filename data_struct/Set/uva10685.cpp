/**
 * Nature UVA - 10685
 * https://vjudge.net/problem/UVA-10685
 *
 * 并查集。
 * 使用map将字符串和编号对应起来。
 *
 * @File:   uva10685.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-09-15
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

int p[N];
int size[N];
int ans;
map<string, int> mp;

int find(int x)
{
	if (x == p[x])
		return x;
	else
		return p[x] = find(p[x]);
}

void merge(int x, int y)
{
	int px, py;

	px = find(x);
	py = find(y);

	if (px == py)
		return;
	size[py] += size[px];
	size[px] = 0;
	p[px] = py;
	ans = max(ans, size[py]);
}

int main(void)
{
	int c, r;

	while (cin >> c >> r && c) {
		string str, str2;
		mp.clear();
		for (int i = 1; i <= c; i++) {
			cin >> str;
			mp[str] = i;
			p[i] = i;
			size[i] = 1;
		}
		ans = 1;
		for (int i = 0; i < r; i++) {
			cin >> str >> str2;
			merge(mp[str], mp[str2]);
		}
		cout << ans << '\n';
	}
	return 0;
}
