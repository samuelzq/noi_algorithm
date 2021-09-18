#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
int Nodes[N][2];

void postorder(int idx)
{
	if (Nodes[idx][0])
		postorder(Nodes[idx][0]);
	if (Nodes[idx][1])
		postorder(Nodes[idx][1]);
	cout << idx << '\n';
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
	postorder(1);
}