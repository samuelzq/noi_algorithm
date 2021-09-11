#include <iostream>

using namespace std;

int g[100005] = {0, };
int r[100005] = {0, };
int d[100005] = {0, };

int main(void)
{
	int i, n, m;
	long long l = 0;
	cin >> n >> m;

	for (i = 0; i < n - 1; i++)
		cin >> d[i];
	for (i = 0; i < n; i++)
		cin >> r[i];
	for (i = 0; i < n; i++)
		cin >> g[i];

	l = m;
	for (i = 0; i < n; i++) {
		long long a = l % (r[i] + g[i]);

		if (a > g[i])
			l += (g[i] + r[i] - a);
		cout << l << '\n';
		l += d[i];
	}
	return 0;
}
