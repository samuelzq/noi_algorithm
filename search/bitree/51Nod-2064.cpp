#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
int Nodes[N][2];

void inorder(int idx)
{
	if (Nodes[idx][0])
		inorder(Nodes[idx][0]);
	cout << idx << '\n';
	if (Nodes[idx][1])
		inorder(Nodes[idx][1]);
}

int main(void)
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int l, r;
		cin >> l >> r;
		Nodes[i][0] = l;
		Nodes[i][1] = r;
	}
	inorder(1);
}