// 直接查找会超时
// 先建立数值和位置的映射位图

#include <bits/stdc++.h>

using namespace std;

map<int, vector<int>> datas;
int main(void)
{
	int n, m;

	while (cin >> n >> m) {
		datas.clear();
		for (int i = 0; i < n; i++) {
			int t;
			cin >> t;
			datas[t].push_back(i);
		}

		while (m--) {
			int k, v, t, i;
			cin >> k >> v;
			
			if (datas.count(v) && datas[v].size() >= k)
				cout << datas[v][k - 1] + 1 << '\n';
			else
				cout << 0 << '\n';
		}
	}
	return 0;
}