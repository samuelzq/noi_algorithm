/*
 * 这道题就是一个合并类的区间DP。
 * 二叉树的中序遍历是把根节点放在中间，根节点左右两边分别是左右子树。
 * dp[i][j]表示中序遍历结果为(ai到aj)的树的最大加分值。
 * 方程：dp[i,j]:=max(dp[i][k-1]*dp[k+1][j]+dp[k][k]
 * 需要注意因为是相乘，所以初始状态必须为1。
 */

#include <bits/stdc++.h>

using namespace std;

#define LL long long
const int INF = 0x7fffffff;
const int MN = 50;
LL dp[MN][MN];
int root[MN][MN];
int num[MN];
int n;
int flag;

LL dfs(int l, int r)
{
	if(l > r) {
		root[l][r] = 0;
		return dp[l][r]=1;
	}
	if (dp[l][r] != -1)
		return dp[l][r];
	if (l == r)	{
		root[l][r] = l;
		return dp[l][l] = num[l];
	}
	dp[l][r]=0;
	for (int i = l; i <= r; i++) {
		dfs(l, i-1);
		dfs(i+1, r);
		if (dp[l][i - 1] * dp[i + 1][r] + num[i] > dp[l][r]) {
			dp[l][r] = dp[l][i - 1] * dp[i + 1][r] + num[i];
			root[l][r] = i;
		}
	}
	return dp[l][r];
}

void Print(int l, int r)
{
	if (l > r)
		return;

	if (flag)
		printf(" ");
	flag = 1;

	printf("%3d", root[l][r]);
	Print(l, root[l][r] - 1);
	Print(root[l][r] + 1, r);
}

int main(void)
{
	int i, j;
	while (cin >> n) {
		flag = 0;
		memset(dp, -1, sizeof(dp));
		for(i = 1; i <= n; i++)
			cin >> num[i];
		dfs(1, n);
		printf("%lld\n", dp[1][n]);
		Print(1, n);
		printf("\n");
	}
	return 0;
}