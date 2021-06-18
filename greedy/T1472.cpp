#include <iostream>
#include <algorithm>

using namespace std;

int a[1000006] = {0, };
int main(void)
{
	int n, m, ans, b;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a+n);
	b = a[0];
	ans = 0;
	for (int i = 1; i < n - 1; i++) {
		if ((a[i+1] - b) <= m)
			ans++;
		else
			b = a[i];
	}
	cout << ans;
	return 0;
}
