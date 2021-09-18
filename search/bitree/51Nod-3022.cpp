// 平衡二叉查找树：简称平衡二叉树。由前苏联的数学家 Adelse-Velskil 和 Landis
// 在 1962 年提出的高度平衡的二叉树，根据科学家的英文名也称为 AVL 树。它具有如下几个性质：
//
// 1. 可以是空树。
// 2. 假如不是空树，任何一个结点的左子树与右子树都是平衡二叉树，并且高度之差的绝对值不超过 1。
#include <bits/stdc++.h>

using namespace std;

const int N = 5e4+5;
int Nodes[N][2];
int l = 1;

// 返回值：
// -1 不是平衡二叉树
// >0 平衡二叉树的高度
int dfs(int root)
{
	int l, r;
	if (root == 0)
		return 0;

	l = dfs(Nodes[root][0]);
	r = dfs(Nodes[root][1]);

	if (l == -1 || r == -1 || abs(l - r) > 1)
		return -1;
	return max(l, r) + 1;
}

int main(void)
{
	int n;

	cin >> n;
	while (n--) {
		int k, i;
		cin >> k;
		for (i = 1; i <= k; i++) {
			cin >> Nodes[i][0] >> Nodes[i][1];
		}
		if (dfs(1) == -1)
			cout << "No\n";
		else
			cout << "Yes\n";
	}
	return 0;
}