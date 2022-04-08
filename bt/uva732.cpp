/**
 * https://vjudge.net/problem/UVA-732
 *
 * @File:   uva732.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-05-05
 *
 **/
#include <bits/stdc++.h>

using namespace std;

vector<char> ops;
int num_i, num_o;
string str1, str2;
stack<char> st;

void dfs(int d)
{
	if (d == 2 * str1.size()) {
		int i;
		for (i = 0; i < ops.size() - 1; i++)
			cout << ops[i] << ' ';
		cout << ops[i] << '\n';
		return;
	}

	if (num_i < str1.size()) {
		st.push(str1[num_i]);
		ops.push_back('i');
		num_i++;
		dfs(d + 1);
		num_i--;
		ops.pop_back();
		st.pop();
	}

	if (st.empty())
		return;

	char c = st.top();
	if (c != str2[num_o])
		return;
	st.pop();
	ops.push_back('o');
	num_o++;
	dfs(d + 1);
	num_o--;
	ops.pop_back();
	st.push(c);
}

int main(void)
{
	while (cin >> str1 >> str2) {
		ops.clear();
		while (!st.empty())
			st.pop();
		num_i = num_o = 0;
		cout << "[\n";
		if (str2.size() == str1.size())
			dfs(0);
		cout << "]\n";
	}
	return 0;
}
