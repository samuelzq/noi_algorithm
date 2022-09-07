/**
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
	while (cin >> str1 >> str2) {
		memset(cnt1, 0, sizeof(cnt1));
		memset(cnt2, 0, sizeof(cnt2));
		for (int i = 0; i < str1.length(); i++)
			cnt1[str1[i] - 'a']++;
		for (int i = 0; i < str2.length(); i++)
			cnt2[str2[i] - 'a']++;

		for (int i = 0; i < 26; i++)
			cnt1[i] = min(cnt1[i], cnt2[i]);

		stack<char> st;
		for (int i = 0; i < str1.length(); i++) {
			if (cnt1[str1[i] - 'a'])
				st.push(str1[i]);
		}

		while (!st.empty()) {
			char c = st.top();
			cout << c;
			st.pop();
		}
		cout << '\n';
	}
	return 0;
}
