/**
 * ShellSort UVA - 10152
 * https://vjudge.net/problem/UVA-10152
 *
 * 对比两组字符串。原始字符串组中，上下顺序满足要求的不需要交换位置。
 * 位置发生变化的字符串都处于目标组的头部。
 *
 * 从两组字符串的尾部开始对比，如果字符串相同，则索引同时向头部移动；
 * 否则仅移动原始字符串数组的索引。最终目标索引之上的字符串即为需要
 * 调整的字符串。
 *
 * @File:   uva10152.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-09-14
 *
 **/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int t;
	vector<string> src, tgt;

	cin >> t;
	while (t--) {
		int n;
		string str;

		src.clear();
		tgt.clear();
		cin >> n;
		getline(cin, str);
		for (int i = 0; i < n; i++) {
			getline(cin, str);
			src.push_back(str);
		}
		for (int i = 0; i < n; i++) {
			getline(cin, str);
			tgt.push_back(str);
		}

		int i, j;
		j = i = n - 1;
		while (i >= 0) {
			if (src[i] == tgt[j])
				j--;
			i--;
		}

		while (j >= 0)
			cout << tgt[j--] << '\n';
		cout << '\n';
	}
	return 0;
}
