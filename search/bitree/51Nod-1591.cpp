#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
int Nodes[N][2];

void preorder(int idx)
{
	cout << idx << '\n';
	if (Nodes[idx][0])
		preorder(Nodes[idx][0]);
	if (Nodes[idx][1])
		preorder(Nodes[idx][1]);
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
	preorder(1);
}