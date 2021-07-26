#include <iostream>

using namespace std;

int main(void)
{
	int n, k;

	cin >> n >> k;
	if (k == 0) {
		cout << 0 << '\n';
		return 0;
	}

	while (n--) {
		int l, r;
		cin >> l >> r;
		if (l == r)
			cout << 1 << '\n';
		else
			cout << r / k - l / k << '\n';
	}
	return 0;
}
