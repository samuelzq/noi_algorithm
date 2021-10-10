#include <bits/stdc++.h>

using namespace std;

const int N = 10005;
int a[N];

int main(void)
{
	int c, cnt;

	cnt = 0;
	while (cin >> c) {
		a[cnt++] = c;
		sort(a, a + cnt);

		if (cnt & 1) {
			cout << a[cnt / 2] << '\n';
		} else {
			cout << (a[cnt / 2 - 1] + a[cnt / 2]) / 2 << '\n';
		}
	}
	return 0;
}