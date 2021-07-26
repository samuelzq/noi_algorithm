#include <iostream>

using namespace std;

int main(void)
{
	int n, i;

	cin >> n;

	for (i = 2; i * i < n; i++) {
		if (n % i == 0) {
			n = n / i;
			break;
		}
	}
	cout << n;
	return 0;
}
