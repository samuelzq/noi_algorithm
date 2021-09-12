#include <bits/stdc++.h>

using namespace std;
const int N = 103;

typedef struct BiTNode
{
	char data;
	struct BiTNode *lchild,*rchild;
} BiTNode, * BITree;
BiTNode Nodes[N];
int idx = 0;

//先序遍历
void preOrder(BiTNode*root)
{
	if (root == NULL)
		return;
	printf("%c ", root->data);
	preOrder(root->lchild);
	preOrder(root->rchild);
}
//中序遍历
void inOrder(BiTNode*root)
{
	if (root == NULL)
		return;
	inOrder(root->lchild);
	printf("%c ", root->data);
	inOrder(root->rchild);
}


void postOrder(BiTNode *root)
{
	if (root == NULL)
		return;
	postOrder(root->lchild);
	postOrder(root->rchild);
	printf("%d ", root->data);
}

/************************************************************************/
/* 算法
1、通过先序遍历找到根结点A，再通过A在中序遍历的位置找出左子树，右子树
2、在A的左子树中，找左子树的根结点（在先序中找），转步骤1
3、在A的右子树中，找右子树的根结点（在先序中找），转步骤1                                                                     */
/************************************************************************/

//找到中序序列中的根节点
int FindIs(char* Is, int n, char val)
{
	int pos = -1;
	for (int i = 0; i < n; i++)
	{
		if (Is[i] == val)
		{
			pos = i;
			break;
		}
	}
	return pos;
}

//根据先序遍历和中序遍历创建二叉树
BiTNode* createBiTree(char *pre, char *in, int n)
{
	int i = 0;
	int pos = 0;
	BiTNode*node = NULL;

	if (n == 0)
		return NULL;

	node = &Nodes[idx++];
	memset(node,0,sizeof(BiTNode));
	//先序序列的第一个元素必为根结点
	node->data = pre[0];

	pos = FindIs(in, n, pre[0]);
	node->lchild = createBiTree(pre + 1, in, pos);
	node->rchild = createBiTree(pre + 1 + pos, in + 1 + pos, n - pos - 1);

	return node;
}

int main()
{
	char preNode[N];
	char inNode[N];
	int n = 0;
	char ch;
	BiTNode* root = NULL;

	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++)
			scanf("%d", &inNode[i]);

		for (int i = 0; i < n; i++)
			scanf("%d", &preNode[i]);

		idx = 0;
		root = createBiTree(preNode, inNode, n);
		postOrder(root);
		cout << '\n';
	}
	return 0;
}