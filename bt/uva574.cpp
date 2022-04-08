/**
 * https://vjudge.net/problem/UVA-574
 *
 * 本题的难点是排除重复的结果。
 * 只要在一个输出结果中保证数据是从大到小排列即可。
 * 总体输出不需要保证每一项都是从大到小。
 *
 * @File:   uva574.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-04-30
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 13;
int a[N];
int sum, n;
vector<string> ans;

bool cmp(int a, int b)
{
	return a > b;
}

void dfs(int sm, int pos, int used)
{
	if (sm > sum)
		return;

	if (sm == sum) {
		stringstream out;
		int r = 0;
		for (int i = 0; i < n; i++) {
			if (used & (1 << i)) {
				if (r)
					out << "+";
				out << a[i];
				r = 1;
			}
		}
		ans.push_back(out.str());
		return;
	}

	for (int i = pos + 1; i < n; i++)
		dfs(sm + a[i], i, used | (1 << i));
	return;
}

int main(void)
{
	while (cin >> sum >> n) {
		if (sum == 0 && n == 0)
			break;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n, cmp);
		ans.clear();
		cout << "Sums of " << sum << ":\n";
		dfs(0, -1, 0);
		if (ans.empty())
			cout << "NONE\n";
		else {
			sort(ans.begin(), ans.end());
			cout << ans[ans.size() - 1] << '\n';
			for (int i = ans.size() - 2; i >= 0; i--) {
				if (ans[i] == ans[i + 1])
					continue;
				else
					cout << ans[i] << '\n';
			}
		}
	}
	return 0;
}
