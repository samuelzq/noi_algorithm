#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e5 + 10;

stack <int> sta;
int l[MAXN], r[MAXN], h[MAXN];

int n;

int main(void)
{
	while (cin >> n && n){
		for (int i = 1; i <= n; i++)
			cin >> h[i];

		h[0] = h[n + 1] = -1;

		for (int i = 1; i <= n + 1; i++){
			while (!sta.empty() && h[i] < h[sta.top()]) {
				// 找到右边第一个比当前矩形矮的矩形。
				// 最后一个为虚构的矩形，其高度-1。
				// 保持栈内数据递增排放，这样就可以形成面积较大的矩形。
				r[sta.top()] = i - 1;
				sta.pop();   // 由于h[n+1]=-1，所以栈最终仅剩n+1
			}
			sta.push(i);
		}

		// 同样的方式找到左边界点
		// 不同于第一次循环，栈底为n+1。由于h[n+1]=-1，因此不影响最终结果。
		for (int i = n; i >= 0; i--) {
			while (!sta.empty() && h[i] < h[sta.top()]) {
				l[sta.top()] = i + 1;   // 左边界要右移1位。
				sta.pop();
			}
			sta.push(i);
		}

		long long ans = 0;

		for (int i = 1; i <= n; i++)
			ans = max(ans, h[i] * (r[i] - l[i] + 1LL));

		cout << ans << '\n';
	}
	return 0;
}
