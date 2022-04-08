/**
 * https://vjudge.net/problem/UVA-628
 *
 * 稍微复杂一点的组合问题。
 * 在pattern中遇到0则从0~9中选则输出；遇到'#'则从密码中选取候选项。
 *
 * @File:   uva628.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-05-01
 *
 **/
#include <bits/stdc++.h>

using namespace std;
string pattern;
vector<string> pass;
vector<string> out;

void dfs(int pos, int idx, int j)
{
	if (pos >= pattern.size()) {
		for (int i = 0; i < out.size(); i++)
			cout << out[i];
		cout << '\n';
		return;
	}

	if (pattern[pos] == '#') {
		for (int i = idx + 1; i < pass.size(); i++) {
			out.push_back(pass[i]);
			dfs(pos + 1, -1, -1);
			out.pop_back();
		}
	} else if (pattern[pos] == '0') {
		for (int i = j + 1; i <= 9; i++) {
			stringstream ss;
			ss << i;
			out.push_back(ss.str());
			dfs(pos + 1, -1, -1);
			out.pop_back();
		}
	}
}

int main(void)
{
	int k;

	while (cin >> k) {
		string tmp;
		pass.clear();
		for (int i = 0; i < k; i++) {
			cin >> tmp;
			pass.push_back(tmp);
		}
		int t;
		cin >> t;
		cout << "--\n";
		while (t--) {
			out.clear();
			cin >> pattern;
			dfs(0, -1, -1);
		}
	}
	return 0;
}
