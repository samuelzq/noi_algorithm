#include <iostream>

using namespace std;

int main(void)
{
	long long n, f1, f2, f;

	f = f1 = 2;
	cin >> n;

	for (int i = 2; i <= n; i++) {
		f = f1 + i;
		f1 = f;
	}
	cout << f;
	return 0;
}
