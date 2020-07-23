#include "stdlib.h"
#include "stdio.h"

int m, arr[103];  // arr 用于记录方案

// n 剩下的数值
// i 当前算到了级数
// a 当前的起始数值
void dfs(int n, int i, int a)
{
	if (n == 0) {
		for (int j = 1; j <= i - 1; ++j)
			printf("%d ", arr[j]);
		printf("\n");
		return;
	}

	if (i > m)
		return;

	for (int j = a; j <= n; j++) {
		arr[i] = j;
		// 如果输出限定为互不相同的数，则第三个参数需要+1
		dfs(n - j, i + 1, j);
	}
}

// 主函数
int main()
{
	int n;
	scanf("%d%d", &n, &m);
	dfs(n, 1, 1);
	return 0;
}
