#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int n, t, s;
int a[N];
int mq[N];
double sum[N];

double calc(void)
{
	int head = 1, tail = 0;
	double ans = -0x3f3f3f3f;
	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + (double)a[i];
	}

	for (int i = 1; i <= n; i++) {
		if (i >= s) {
			while (tail >= head && sum[i - s] < sum[mq[tail]])
				tail--;
			mq[++tail] = i - s;
		}
		if (head <= tail) {
			if (i - mq[head] > t)
				head++;
			
			ans = max(ans, (sum[i] - sum[mq[head]])/(i - mq[head]));
		} 
	}
	// 实际的平均值应该小于mid
	return ans;
}

int main(void)
{
	double mid, l, r;
	scanf("%d %d %d", &n, &s, &t);

	for(int i = 1; i <= n; i++)
		scanf("%d",&a[i]);

	printf("%.3lf\n", calc());
	return 0;
}