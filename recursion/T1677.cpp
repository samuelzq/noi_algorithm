#include <iostream>

using namespace std;

int ans = 1;

void dfs(int x, int k)
{
	if (x < 2 + k || (x -k) % 2)
		return;
	ans++;
	dfs((x - k) / 2, k);
	dfs((x + k)  /2, k);
}

int main(void)
{
	int n, k;

	cin >> n >> k;
	dfs(n, k);
	cout << ans;
	return 0;
}
