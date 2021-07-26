#include <iostream>
#include <algorithm>

using namespace std;
typedef struct {
	int p;
	int c;
} GOOD;

GOOD g[102] = {0, };

bool cmp(GOOD g1, GOOD g2)
{
	return g1.p < g2.p;
}

int main(void)
{
	int n, m, ans;
	cin >> m >> n;

	for (int i = 0; i < n; i++)
		cin >> g[i].p >> g[i].c;
	sort(g, g + n, cmp);
	ans = 0;
	for (int i = 0; i < n; i++) {
		if (m > g[i].p * g[i].c) {
			ans += g[i].c;
			m -= g[i].p * g[i].c;
		} else {
			ans += m / g[i].p;
			break;
		}
	}
	cout << ans;
	return 0;
}
