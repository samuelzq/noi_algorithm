#include <iostream>

using namespace std;

int main(void)
{
	int n;
	long long a[3], ans = 0;
	a[0] = 3;
	a[1] = 4;
	a[2] = 5;

	cin  >> n;

	for (int i = 1; i < n; i++) {
		ans = a[0] + a[1] + a[2];
		a[0] = a[1];
		a[1] = a[2];
		a[2] = ans;
	}
	cout << a[0];
	return 0;
}