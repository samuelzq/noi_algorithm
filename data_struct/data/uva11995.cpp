/**
 * I Can Guess the Data Structure! UVA - 11995
 * https://vjudge.net/problem/UVA-11995
 *
 * 本题模拟整个操作过程。
 *
 * @File:   uva10935.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2021-12-25
 *
 **/

#include <bits/stdc++.h>

using namespace std;

stack<int> st;
queue<int> q;
priority_queue<int> pq;

int main(void)
{
	int n;
	int check = 0;   // bit0：stack、bit1：queue、bit3：pri_queue、bit4：有多余的pop操作

	while (cin >> n) {
		bool no_pop = true, first_pop = true;
		check = 0;
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			if (x == 1) {
				st.push(y);
				q.push(y);
				pq.push(y);
			}

			if (x == 2) {
				no_pop = false;
				if (st.empty() || q.empty() || pq.empty())
					check |= 8;
				else {
					if (y == st.top()) {
						if (first_pop)
						check |= 1;
					} else
						check &= ~1;
					if (y == q.front()) {
						if (first_pop)
						check |= 2;
					} else
						check &= ~2;
					if (y == pq.top()) {
						if (first_pop)
							check |= 4;
					} else
						check &= ~4;
					st.pop();
					q.pop();
					pq.pop();
					first_pop = false;
				}
			}
		}
		while (!st.empty())
			st.pop();
		while (!q.empty())
			q.pop();
		while (!pq.empty())
			pq.pop();

		if (no_pop) {
			cout << "not sure\n";
			continue;
		}
		if (check == 0 || check >= 8)
			cout << "impossible\n";
		else if (check == 1)
			cout << "stack\n";
		else if (check == 2)
			cout << "queue\n";
		else if (check == 4)
			cout << "priority queue\n";
		else
			cout << "not sure\n";
	}
	return 0;
}