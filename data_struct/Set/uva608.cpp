/**
 * Counterfeit Dollar UVA - 608
 * https://vjudge.net/problem/UVA-608
 *
 * 由于只有一个伪币，它肯定出现在每一个失衡的结果中。
 * 建立两个集合：
 * 1、使天平平衡的硬币。
 * 2、使天平失衡的硬币。失衡时，假设每一个未出现在集合1中的硬币都是伪造的。
 *    每在失衡结果中出现一次，则记一次数（轻-1，重+1）。
 * 最后查询集合2中哪个硬币计数的绝对值等于失衡的次数，如果计数为负则轻，反之重。
 *
 * @File:   uva608.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-01-01
 *
 **/

#include <bits/stdc++.h>

using namespace std;

int golden[26];
int counterfeit[26];

int main(void)
{
	int t;

	cin >> t;
	while (t--) {
		int cmp;
		string lstr, rstr, result;
		memset(golden, 0, sizeof(golden));
		memset(counterfeit, 0, sizeof(counterfeit));
		cmp = 0;
		for (int i = 0; i < 3; i++) {
			cin >> lstr >> rstr >> result;
			if (result == "even") {
				for (auto c:lstr) {
					golden[c - 'A'] = 1;
					counterfeit[c - 'A'] = 0;
				}
				for (auto c:rstr) {
					golden[c - 'A'] = 1;
					counterfeit[c - 'A'] = 0;
				}
			} else if (result == "up") {
				cmp++;
				for (auto c : lstr) {
					if (golden[c - 'A'] != 1)
						counterfeit[c - 'A']++;
				}
				for (auto c : rstr) {
					if (golden[c - 'A'] != 1)
						counterfeit[c - 'A']--;
				}
			} else {
				cmp++;
				for (auto c : lstr) {
					if (golden[c - 'A'] != 1)
						counterfeit[c - 'A']--;
				}
				for (auto c : rstr) {
					if (golden[c - 'A'] != 1)
						counterfeit[c - 'A']++;
				}
			}
		}

		// 找伪币
		char c;
		for (int i = 0; i < 26; i++) {
			if (abs(counterfeit[i]) == cmp) {
				c = 'A' + i;
				break;
			}
		}
		cout << c << " is the counterfeit coin and it is " << ((counterfeit[c - 'A'] > 0) ? "heavy.\n" : "light.\n");
	}
	return 0;
}
