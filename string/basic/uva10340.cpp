/**
 * All in All UVA - 10340
 * https://vjudge.net/problem/UVA-10340
 *
 * 暴力枚举。
 * 在第二个字符串中依次枚举第一个字符串中的每一个字符。
 *
 * @File:   uva10340.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-09-07
 *
 **/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	bool ans = true;
	string str1, str2;

	while (cin >> str1 >> str2) {
		if (str1.length() > str2.length()) {
			ans = false;
		} else {
			int m = 0, j = 0, i = 0;
			for (; i < str1.length(); i++) {
				for (; j < str2.length(); j++) {
					if (str1[i] == str2[j]) {
						m++;
						j++;
						break;
					}
				}
			}
			if (m == str1.length())
				ans = true;
			else
				ans = false;
		}
		if (ans)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}
