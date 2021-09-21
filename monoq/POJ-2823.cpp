#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 1e6+10;

int a[N];		// 原始数据
int monoq[N];    // 单调队列，记录原队列中的序号
int n, k;

// 得到这个队列里的最小值
// 往队列添加数据之前，需要将前面比自己大的数据剔除
void getmin(void)
{
	int head = 0, tail = 0;

	// 先填满窗口的前k - 1
	for (int i = 1; i < k; i++) {
		// 将元素入队，需要剔除单调队列中大于当前数值的元素
		while (head <= tail && a[monoq[tail]] >= a[i])
			tail--;
		monoq[++tail] = i;
	}

	// 滑动窗口，填入新元素
	for (int i = k; i <= n; i++) {
		while (head <= tail && a[monoq[tail]] >= a[i])
			tail--;
		monoq[++tail] = i;
		while (monoq[head] <= i - k)  // 需要向后滑动窗口
			head++;
		printf("%d ", a[monoq[head]]);
	}
}
// 得到这个队列里的最小值
// 往队列添加数据之前，需要将前面比自己小的数据剔除
void getmax(void)
{
	int head = 0, tail = 0;
	for (int i = 1; i < k; i++) {
		while (head <= tail && a[monoq[tail]] <= a[i])
			tail--;
		monoq[++tail] = i;
	}
	for (int i = k; i <= n; i++) {
		while (head <= tail && a[monoq[tail]] <= a[i])
			tail--;
		monoq[++tail] = i;
		while (monoq[head] <= i - k)
			head++;
		printf("%d ", a[monoq[head]]);
	}
}

int main(void)
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	getmin();
	printf("\n");
	getmax();
	printf("\n");
	return 0;
}