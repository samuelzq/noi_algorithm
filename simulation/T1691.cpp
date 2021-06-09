#include <iostream>
#include <cstring>

using namespace std;

char d[22][12] = {0,};
char p[12] = {0, };
int main(void)
{
	int n, m, ans = 0;

	cin >> n >> m;
	cin.getline(p, 11);
	for (int i = 0; i < n; i++)
		cin.getline(d[i], 11);

	ans = 0;
	while (m--) {
		int l;
		cin.getline(p, 11);
		l = strlen(p);
		for (int i = 0; i < n; i++) {
			int j, b = strlen(d[i]);
			if (l != b)
				continue;
			for (j = 0; j < b; j++) {
				if (p[j] != d[i][j])
					break;
			}

			if (j == b)
				ans++;
		}
	}
	cout << ans;
	return 0;
}
