#include <iostream>

using namespace std;
int bit[10005] = {0, };

int main(void)
{
	int n, m, ans, b, t;

	cin >> n >> m;
	ans = 1;
	t = 0;
	while (m--) {
		cin >> b;
		if (bit[b] < ans) {
			bit[b]++;
			t++;
		}
		if (t == n) {
			cout << 1;
			t = 0;
			ans++;
		}
		else
			cout << 0;
	}
	return 0;
}
