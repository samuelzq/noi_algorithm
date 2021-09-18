#include <bits/stdc++.h>

using namespace std;

const int N = 1034;

typedef struct BiTNode
{
	char data;
	struct BiTNode *lchild,*rchild;
} BiTNode, * BITree;
BiTNode Nodes[N];
int idx = 0;      // 叶子结点索引
int cur = 0;      // 父节点索引，新的父节点肯定在当前父节点之后
int n;

void postOrder(BiTNode *root)
{
	if (root == NULL)
		return;
	postOrder(root->lchild);
	postOrder(root->rchild);
	cout << root->data;
	if (n--)
		printf(" ");
}

int main(void)
{
	string str;
	int lr;
	BiTNode *node, *pnode;

	n = 0;
	idx = 0;
	cin >> str;
	node = &Nodes[idx++];
	node->data = str[0];
	while (cin >> str) {
		n++;
		pnode = &Nodes[cur];
		node = &Nodes[idx++];
		node->data = str[0];
		while (pnode->data != str[2]) {
			// 查找父节点
			cur++;
			pnode = &Nodes[cur];
		}
		// 将新结点挂载到父节点
		if (str[4] == '1')
			pnode->lchild = node;
		else
			pnode->rchild = node;
	}
	postOrder(&Nodes[0]);
	return 0;
}