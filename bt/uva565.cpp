/**
 * https://vjudge.net/problem/UVA-565
 *
 * 注意：本题具有多个解。
 * 遍历所有可能的组合（什么都不选也是一种组合），然后判断该组合是否满足所有人的需求。
 *
 * @File:   uva565.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-04-30
 *
 **/
#include <bits/stdc++.h>

using namespace std;

int a[30][2];
string str;
string ans;
bool s = false;
int mask;

bool check(int d, int bit)
{
	if (d == 16) {
		if (bit == mask) {
			cout << "Toppings: " << ans << '\n';
			return true;
		} else
			return false;
	}

	for (int i = 0; i < 2; i++) {
		if (i)
			ans.push_back('A' + d);
		if (check(d + 1, bit | a[d][i]))
			return true;
		if (i)
			ans.pop_back();
	}
	return false;
}

int main(void)
{
	int l = 0;
	memset(a, 0, sizeof(a));
	while (cin >> str) {
		if (str[0] == '.') {
			mask = (1 << l) - 1;
			ans.clear();
			l = 0;
			if (false == check(0, 0))
				cout << "No pizza can satisfy these requests.\n";
			memset(a, 0, sizeof(a));
		} else {
			for (int i = 0; i < str.length(); i += 2) {
				int t = str[i + 1] - 'A';
				if (str[i] == '+')
					a[t][1] |= 1 << l;
				else
					a[t][0] |= 1 << l;
			}
			l++;
		}
	}
	return 0;
}
