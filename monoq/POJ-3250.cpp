// 转换为统计每一头牛可以被其左侧的多少头牛看到。

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

int n;
long long ans;
stack <int> sta;

int main(void)
{
	cin >> n;

	// 单调栈解题框架
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		// 移除左侧所有比自己矮的， 然后统计剩余
		while (!sta.empty() && x >= sta.top()){
			sta.pop();
		}
		ans += sta.size();

		// 自身入栈
		sta.push(x);
	}

	cout << ans;
	return 0;
}