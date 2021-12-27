/**
 * Simply Syntax UVA - 12207
 * https://vjudge.net/problem/UVA-12207
 *
 * 利用deque模拟候诊队列。
 * 首先创建一个初始化等候队列，队列中数据类型由人口总数P的上限决定。队列长度取P和C的最小值。
 * 接下来按照输入指令对队列进行操作：
 *       N: 从队列头取一个名单
 *       E: 插到队列头部，需要删除队列中已有的元素
 *
 * @File:   uva12207.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2021-12-27
 *
 **/

#include <bits/stdc++.h>

using namespace std;

deque<int> srv;

int main(void)
{
	int k, p, c;

	k = 1;
	while (cin >> p >> c && p && c) {
		char op;
		int idx;
		while (!srv.empty())
			srv.pop_front();
		for (int i = 1; i <= min(p, c); i++)
			srv.push_back(i);

		cout << "Case " << k++ << ":\n";
		while (c--) {
			cin >> op;
			if (op == 'E') {
				cin >> idx;
				for (deque<int>::iterator it = srv.begin(); it != srv.end(); ++it) {
					if (*it == idx) {
						srv.erase(it);
						break;
					}
				}
				srv.push_front(idx);
			} else {
				idx = srv.front();
				cout << idx << '\n';
				srv.pop_front();
				srv.push_back(idx);
			}
		}
	}
	return 0;
}