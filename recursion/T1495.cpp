#include <iostream>

using namespace std;

int n, p;

void dfs(int k, int s)
{
	for (int i = 1; i <= p; i++) {
		if (k == n + 1) {
			cout << s << '\n';
			return;
		}
		s = s * 10 + i;
		dfs(k + 1, s);
		s = (s - i) / 10;
	}
}

int main(void)
{
	cin >> n >> p;
	dfs(1, 0);
}
