/**
 *
 * @File:   uva437.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-09-06
 *
 **/
#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<int> &a, vector<int> &b)
{
	if (b[0] > a[0])
		return true;
	else if (b[0] == a[0])
		return b[1] > a[1];
	else
		return false;
}

bool cmp2(vector<int> &a, vector<int> &b)
{
	if (b[0] > a[0] && b[1] > a[1])
		return true;
	return false;
}

int LIS(vector<vector <int>> &a)
{
	int ans = 0;
	vector<int> l(a.size());

	for (int i = 0; i < a.size(); i++)
		l[i] = a[i][2];
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < i; j++)
			if (cmp2(a[j], a[i]))
				l[i] = max(l[i], l[j] + a[i][2]);
	for (int i = 0; i < l.size(); i++)
		ans = max(ans, l[i]);
	return ans;
}

int main(void)
{
	vector<int> block(3, 0);
	vector<vector<int>> blocks;
	int cnt, k = 1;

	while (1) {
		blocks.clear();
		cin >> cnt;
		if (cnt == 0)
			break;
		int a, b, c;
		for (int i = 0; i < cnt; i++) {
			cin >> a >> b >> c;
			block[0] = a;
			block[1] = b;
			block[2] = c;
			blocks.push_back(block);
			block[0] = a;
			block[1] = c;
			block[2] = b;
			blocks.push_back(block);
			block[0] = b;
			block[1] = a;
			block[2] = c;
			blocks.push_back(block);
			block[0] = b;
			block[1] = c;
			block[2] = a;
			blocks.push_back(block);
			block[0] = c;
			block[1] = b;
			block[2] = a;
			blocks.push_back(block);
			block[0] = c;
			block[1] = a;
			block[2] = b;
			blocks.push_back(block);
		}
		sort(blocks.begin(), blocks.begin() + 6 * cnt, cmp);
		auto it = unique(blocks.begin(), blocks.end());
		blocks.erase(it, blocks.end());

		cout << "Case " << k++ << ": maximum height = " << LIS(blocks) << '\n';
	}
	return 0;
}
