// 平均值一定在序列最大值和最小值之间。
// 如果序列中存在一段 ai+...+aj 的平均值大于等于A，就相当于 (ai-A)+...+(aj-A) 的平均值大于等于0，
// 则说明当前选的平均值小了。反之则选取的平均值大了。
// 因此可利用折半查找，查询合适的平均值。
// 由于区间长度是在是[S，T]之间，因此需要使用单调队列。

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int n, t, s;
int a[N];
int mq[N];
double sum[N];

bool check(double mid)
{
	int head = 1, tail = 0;
	sum[0] = 0;
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + (double)a[i] - mid;

	for (int i = 1; i <= n; i++) {
		if (i >= s) {
			while (tail >= head && sum[i - s] < sum[mq[tail]])
				tail--;
			mq[++tail] = i - s;
		}
		if (head <= tail) {
			if (i - mq[head] > t)
				head++;
			if (sum[i] - sum[mq[head]] >= 0)
				return true;
		}
	}
	// 实际的平均值应该小于mid
	return false;
}

int main(void)
{
	double mid, l, r;
	scanf("%d %d %d", &n, &s, &t);

	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	l = -10000;
	r = 10000;
	while (r - l > 1e-6) {
		mid = (l + r)/2;
		if (check(mid))
			l = mid;//平均值小了扩大
		else
			r = mid;//平均值大了缩小
	}
	printf("%.3lf\n",l);
	return 0;
}