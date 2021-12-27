/**
 * The Blocks Problem UVA - 514
 * https://vjudge.net/problem/UVA-514
 *
 * 使用stack模拟车站历史上车厢等候的情况。
 * 车站内等候的车厢编号不能够大于当前车厢编号。
 *
 * @File:   uva514.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2021-12-27
 *
 **/

#include <bits/stdc++.h>

using namespace std;
stack<int> coaches;

int main(void)
{
	int n;
		
	while (cin >> n && n) {
		bool y = true;
		while (1) {
			int a;
			y = true;
			cin >> a;
			if (a == 0) {
				cout << '\n';
				break;
			}
			
			int c = 1; // 未出站车厢编号
			for (int i = 1; i < n; i++) {
				while (c <= a) // a以及有比a小的车厢在站中等候。
					coaches.push(c++);
				if (!coaches.empty() && a == coaches.top()) // 站内当前发车编号必须和发车结果一致
					coaches.pop();
				else {  // 当前站内无车厢或者序号不能够满足要求
					y = false;
					while (++i <= n)
						cin >> a;
					break;
				}
				cin >> a;				
			}

			if (y == true)
				cout << "Yes\n";
			else
				cout << "No\n";			
		}
	}
	return 0;
}