/**
 * Simply Syntax UVA - 496
 * https://vjudge.net/problem/UVA-496
 *
 * 利用vector模拟集合，需要排除除重复的数据。
 * 比较两个集合中相同的元素个数：
 *       1、相同元素个数与两个集合元素个数相等则完全匹配
 *       2、没有相同元素则无交集
 *       3、相同元素个数小于两个集合，则无法判断
 *       4、两个集合不等长，相同元素个数等于小的集合，则小的集合是另一个的子集
 *
 * @File:   uva496.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2021-12-28
 *
 **/

#include <bits/stdc++.h>

using namespace std;

vector<int> set1;
vector<int> set2;

int init_set(vector<int> &ss)
{
	int d, len = 0;
	string s;
	vector<int>::iterator it;

	if (getline(cin, s)) {
		stringstream xx(s);
		while (!ss.empty())
			ss.clear();
		while (xx >> d) {
			ss.push_back(d);
			len++;
		}
		sort(ss.begin(), ss.end());
		it = unique(ss.begin(), ss.end());
		ss.resize(distance(ss.begin(), it));
	}
	return len;
}

int check(vector<int> &ss1, vector<int> &ss2)
{
	int l1 = ss1.size();
	int l2 = ss2.size();
	int i, j, diffs;
	i = j = diffs = 0;
	while (i != l1 && j != l2) {
		if (ss1[i] < ss2[j]) {
			i++;
		} else if (ss2[j] < ss1[i]) {
			j++;
		} else {
			i++;
			j++;
			diffs++;
		}
	}
	return diffs;
}

int main(void)
{
	int diff;
	int result = 0;
	while (init_set(set1) && init_set(set2)) {
		diff = check(set2, set1);
		//cout << diff << '\n';

		if (diff == 0) {
			cout << "A and B are disjoint\n";
		} else {// if (diff < set1.size() && diff < set2.size()) {
			if (set1.size() == set2.size()) {
				if (diff == set1.size())
					cout << "A equals B\n";
				else
					cout << "I'm confused!\n";
			} else if (set1.size() > set2.size()) {
				if (diff == set2.size())
					cout << "B is a proper subset of A\n";
				else
					cout << "I'm confused!\n";
			} else {
				if (diff == set1.size())
					cout << "A is a proper subset of B\n";
				else
					cout << "I'm confused!\n";
			}
		}
	}
	return 0;
}