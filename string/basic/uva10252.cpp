/**
 * Common Permutation UVA - 10252
 * https://vjudge.net/problem/UVA-10252
 *
 * 分别统计26个小写字符在每个字符串中出现的次数。
 * 然后取每个字符出现次数的最小值。最后依次输出每个字符。
 *
 * @File:   uva10252.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-09-07
 *
 **/
#include <bits/stdc++.h>

using namespace std;

int cnt1[27];
int cnt2[27];

int main(void)
{
	string str1, str2;
	while (getline(cin, str1)) {
		getline(cin, str2);
		memset(cnt1, 0, sizeof(cnt1));
		memset(cnt2, 0, sizeof(cnt2));
		for (int i = 0; i < str1.length(); i++)
			cnt1[str1[i] - 'a']++;
		for (int i = 0; i < str2.length(); i++)
			cnt2[str2[i] - 'a']++;

		for (int i = 0; i < 26; i++)
			cnt1[i] = min(cnt1[i], cnt2[i]);

		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < cnt1[i]; j++)
				cout << (char)(i + 'a');
		}

		cout << '\n';
	}
	return 0;
}
