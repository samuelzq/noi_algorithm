/**
 * Throwing cards away I UVA - 10935
 * https://vjudge.net/problem/UVA-10935
 *
 * 本题使用队列模拟整个过程。
 *
 * @File:   uva10935.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2021-12-25
 *
 **/

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n;
	queue<int> cards1;

	while (cin >> n && n) {
		for (int i = 1; i <= n; i++)
			cards1.push(i);

		cout << "Discarded cards:";
		while (cards1.size() > 1) {
			int c = cards1.front();

			cards1.pop();
			cout << ' ' << c;
			if (cards1.size() > 1)
				cout << ',';

			c = cards1.front();
			cards1.pop();
			cards1.push(c);
		}
		cout << "\nRemaining card: " << cards1.front() << '\n';
		cards1.pop();
	}
	return 0;
}