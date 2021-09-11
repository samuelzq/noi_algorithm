#include <iostream>

using namespace std;

int l[1001] = {0};

int main(void)
{
	int i, n, ans;

	cin >> n;

	for (i = 3; i <= n; i += 3)
		l[i] = 1;

	for (i = 5; i <= n; i+= 5) {
		if (l[i] == 1)
			l[i] = 0;
		else
			l[i] = 1;
	}

	for (i = 7; i <= n; i+= 7) {
		if (l[i] == 1)
			l[i] = 0;
		else
			l[i]++;
	}

	ans = 0;
	for (i = 1; i <= n; i++) {
		if (l[i] == 0)
			ans++;
	}
	cout << ans;
	return 0;
}
