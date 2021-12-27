/**
 * Simply Syntax UVA - 271
 * https://vjudge.net/problem/UVA-271
 *
 * 后向统计基本语句出现的个数。每遇到一个特殊字符，就缩减相应的基本语句个数。
 *
 * @File:   uva673.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2021-12-27
 *
 **/

#include <bits/stdc++.h>

using namespace std;
string str;
stack<char> comb;

// 后向统计
bool check(int r)
{
	int cnt = 0;  // 语句数量

	while (r >= 0) {
		char c = str[r];

		if (c >= 'p' && c <= 'z') {
			cnt++; // 连续基本句子的数目
		} else if (c == 'C' ||
				   c == 'D' ||
				   c == 'E' ||
				   c == 'I' ||
				   c == 'N') { // 这个5个字符合并句子
			if (c != 'N') // 其余4个二合一
				cnt--;
		} else
			cnt = -1;

		if (cnt <= 0)
			break;
		r--;
	}

	if (cnt == 1)  // 语句数只能够是1
		return true;
	else
		return false;
}

int main(void)
{
	while (cin >> str) {
		if (false == check(str.length() - 1))
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	return 0;
}