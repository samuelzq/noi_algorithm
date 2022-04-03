/**
 * https://vjudge.net/problem/51Nod-3414
 *
 * 按字典生序排列，先将所有字符转换成大写，然后转换成小写
 *
 * @File:   51Nod3414.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-03-07
 *
 **/
#include <bits/stdc++.h>

using namespace std;

string str;
string bt;
int len;

int dfs(int n)
{
	if (n == len) {
		cout << bt << '\n';
		return 0;
	}

	if (str[n] >= '0' && str[n] <= '9') {
		bt += str[n];
		dfs(n + 1);
	} else if (str[n] >= 'A' && str[n] <= 'Z') {
		bt += str[n];
		dfs(n + 1);
		bt[n] = str[n] - 'A' + 'a';
		dfs(n + 1);
	} else {
		bt += str[n] - 'a' + 'A';
		dfs(n + 1);
		bt[n] = str[n];
		dfs(n + 1);
	}
	bt.pop_back();
	return 0;
}

int main(void)
{
	cin >> str;
	len = str.length();
	dfs(0);
	return 0;
}
