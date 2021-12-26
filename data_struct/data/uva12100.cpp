/**
 * Printer Queue UVA - 12100
 * https://vjudge.net/problem/UVA-12100
 *
 * 本题使用两个队列来模拟整个操作过程。
 * queue来模拟等待任务队列；priority_queue模拟下一个任务的优先级。
 *
 * @File:   uva12100.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2021-12-25
 *
 **/

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int k;

	cin >> k;
	while (k--) {
		int n, p, t;  // t用来检索当前任务是否为目标任务的游标
		cin >> n >> p;

		queue<int> q;
		priority_queue<int> pq;
		for (int i = 0; i <  n; i ++) {
			int j;
			cin >> j;
			q.push(j);
			pq.push(j);
		}
		t = 0;
		while (1) {
			if (q.front() == pq.top()) { // 当前任务是最高优先级任务，执行
				if (t == p) // 当前任务是目标任务
					break;
				pq.pop();
				q.pop();
				t++;
			} else { // 当前任务不是目标任务，将其移至队尾
				int	tmp = q.front();
				q.pop();
				q.push(tmp);

				if (t == p) { // 当前任务是目标任务，更新它在队列中的位置
					t = 0;
					p = q.size() - 1;
				} else {
					t++;
				}
			}
		}
		cout << n - q.size() + 1 << '\n';
	}
	return 0;
}