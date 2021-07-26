#include <iostream>

using namespace std;

int main(void)
{
	long long f, f1, f2, n, p;

	cin >> n >> p;

	f = f1 = f2 = 1;
	for (int i = 3; i <= n; i++) {
		f = (f2 * f2 % p + f1) % p;
		f1 = f2;
		f2 = f;
	}
	cout << f;
	return 0;
}
