#include <bits/stdc++.h>

using namespace std;

const int N = 2e6+10;

int a[N];		// 原始数据
int monoq[N];    // 单调队列，记录原队列中的序号
int n, k;

// 得到这个队列里的最小值
// 往队列添加数据之前，需要将前面比自己大的数据剔除
void getmin(void)
{
	int head = 0, tail = 0, mina = a[1];

	// 第一个输出肯定是0
	printf("%d\n", 0);

	// 先填满窗口的前k - 1
	for (int i = 1; i < k; i++) {
		// 将元素入队，需要剔除单调队列中大于当前数值的元素
		while (head <= tail && a[monoq[tail]] >= a[i])
			tail--;
		monoq[++tail] = i;

		// 输出前k个中满足要求的值
		mina = min(mina, a[i]);
		printf("%d\n", mina);
	}

	// 滑动窗口，填入新元素，滑动窗口在最后一个元素前停止滑动
	for (int i = k; i < n; i++) {
		while (head <= tail && a[monoq[tail]] >= a[i])
			tail--;
		monoq[++tail] = i;
		while (monoq[head] <= i - k)  // 需要向后滑动窗口
			head++;
		printf("%d\n", a[monoq[head]]);
	}
}

int main(void)
{
	scanf("%d%d", &n, &k);
	a[0] = 0;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	getmin();
	return 0;
}