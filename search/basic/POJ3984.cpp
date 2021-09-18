#include <iostream>

using namespace std;

int maze[7][7] = {0, };
int a[17];
int b[17];
int dep = 0;

bool dfs(int x, int y)
{
	if (x == 5 && y == 5)
		return true;
	if (!maze[x][y])
		return false;
	if (dfs(x + 1, y) || dfs(x, y + 1)) {
		a[dep] = x - 1;
		b[dep] = y - 1;
		dep++;
		return true;
	} else
		return false;
}

int main(void)
{
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			int t;
			cin >> t;
			if (t)
				maze[i][j] = 0;
			else
				maze[i][j] = 1;
		}
	}
	dfs(1, 1);
	for (int i = dep - 1; i >= 0; i--)
		cout << '(' << a[i] << ", " << b[i] << ")\n";
	cout << "(4, 4)";
	return 0;
}
