/**
 * https://vjudge.net/problem/UVA-656
 *
 * 算法很简单，遍历所有可能的计算组合，找到最短的一组。
 * 在计算的过程中需要：
 * 	排除不合适的结果—————绝对值超过30000。
 * 	避免除0。
 * 输入绝对值超过30000是允许的。
 *
 * @File:   uva656.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-05-02
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 12;
stack<int> in[N];
int res[N];
vector<string> ops;
int n;
vector<string> sta;
bool f = false;

bool check(void)
{
	for (int i = 0; i < n; i++) {
		if (in[i].size() > 1)
			return false;
		if (in[i].top() != res[i])
			return false;
	}
	return true;
}

bool overflow(void)
{
	for (int i = 0; i < n; i++) {
		if (abs(in[i].top()) > 30000)
			return true;
	}
	return false;
}

void dfs(int d)
{
	if (d > 10) {
		return;
	}

	if (check()) {
		if (sta.size() > ops.size())
			sta = ops;
		f = true;
		return;
	}

	if (in[0].size() == 1) {
		int a[N];
		for (int i = 0; i < n; i++) {
			a[i] = in[i].top();
			in[i].push(a[i]);
		}
		ops.push_back(string("DUP"));
		dfs(d + 1);
		ops.pop_back();
		for (int i = 0; i < n; i++)
			in[i].pop();
	} else {
		int ab[N][2];
		int dd[N];
		for (int i = 0; i < n; i++) {
			ab[i][0] = in[i].top();
			in[i].pop();
			ab[i][1] = in[i].top();
			in[i].pop();

		}
		for (int i = 0; i < n; i++){
			dd[i] = ab[i][0] + ab[i][1];
			if (abs(dd[i]) > 30000)
				goto div;
		}
		for (int i = 0; i < n; i++)
			in[i].push(dd[i]);
		ops.push_back(string("ADD"));
		dfs(d + 1);
		ops.pop_back();
		for (int i = 0; i < n; i++)
			in[i].pop();
div:
		for (int i = 0; i < n; i++) {
			if (ab[i][0] == 0)
				goto skip;
			else
				dd[i] = ab[i][1] / ab[i][0];
		}
		for (int i = 0; i < n; i++){
			int t = dd[i];
			if (abs(t) > 30000)
				goto dup;
		}
		for (int i = 0; i < n; i++)
			in[i].push(dd[i]);
		ops.push_back(string("DIV"));
		dfs(d + 1);
		ops.pop_back();
		for (int i = 0; i < n; i++)
			in[i].pop();

skip:
dup:
		for (int i = 0; i < n; i++) {
			in[i].push(ab[i][1]);
			in[i].push(ab[i][0]);
			in[i].push(ab[i][0]);
		}
		ops.push_back(string("DUP"));
		dfs(d + 1);
		ops.pop_back();
		for (int i = 0; i < n; i++) {
			in[i].pop();
			in[i].pop();
			in[i].pop();
		}

		for (int i = 0; i < n; i++) {
			dd[i] = ab[i][0] * ab[i][1];
			if (abs(dd[i]) > 30000)
				goto sub;
		}
		for (int i = 0; i < n; i++)
			in[i].push(dd[i]);
		ops.push_back(string("MUL"));
		dfs(d + 1);
		ops.pop_back();
		for (int i = 0; i < n; i++)
			in[i].pop();
sub:
		for (int i = 0; i < n; i++) {
			dd[i] = ab[i][1] - ab[i][0];
			if (abs(dd[i]) > 30000)
				goto exit;
		}
		for (int i = 0; i < n; i++)
			in[i].push(dd[i]);
		ops.push_back(string("SUB"));
		dfs(d + 1);
		ops.pop_back();
		for (int i = 0; i < n; i++)
			in[i].pop();
exit:
		for (int i = 0; i < n; i++) {
			in[i].push(ab[i][1]);
			in[i].push(ab[i][0]);
		}
	}
}

int main(void)
{
	int t, k = 1;

	while (cin >> t && t) {
		n = t;
		for (int i = 0; i < N; i++) {
			while (!in[i].empty())
				in[i].pop();
		}
		for (int i = 0; i < t; i++) {
			int a;
			cin >> a;
			in[i].push(a);
		}

		for (int i = 0; i< t; i++)
			cin >> res[i];

		ops.clear();
		sta.resize(12);
		cout << "Program " << k++ << '\n';
		f = false;
		dfs(0);
		if (f) {
			if (sta.empty())
				cout << "Empty sequence\n";
			else {
				int r = 0;
				for (int i = 0; i < sta.size(); i++) {
					if (r)
						cout << ' ' << sta[i];
					else
						cout << sta[i];
					r = 1;
				}
				cout << "\n";
			}
		} else {
			cout << "Impossible\n";
		}
		cout << "\n";
	}
	return 0;
}
