#include <iostream>

using namespace std;

int a[100000] = {0, };
int main(void)
{
	int n, p, i;

	cin >> n;

	if (n <= 3) {
		cout << n;
		return 0;
	}

	a[0] = 2;
	n -= 2;
	for (i = 1; n >= a[i - 1] && n >= i + 2; i++) {
		a[i] = i + 2;
		n -= i + 2;
	}
	while (n) {
		for (int j = i; j > 0 && n; j--, n--) {
			a[j - 1]++;
		}
	}

	cout << a[0];
	for (int j = 1; j < i; j++)
		cout << ' ' << a[j];
	return 0;
}
