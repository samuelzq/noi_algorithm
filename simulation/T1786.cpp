#include <iostream>

using namespace std;

int a[100005];

int main(void)
{
	int n, m, op, k, x;
	bool rev = false;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	while (m--) {
		cin >> op;

		if (op == 1) {
			cin >> k;
			if (rev == false)
				cout << a[k - 1] << '\n';
			else
				cout << a[n - k] << '\n';
		} else if (op == 2) {
			cin >> k >> x;
			if (rev == false)
				a[k - 1] = x;
			else
				a[n - k] = x;
		} else if (op == 3) {
			if (rev == false)
				rev = true;
			else
				rev = false;
		}
	}
	return 0;
}
