#include <iostream>

using namespace std;

//int m[50005];

int main(void)
{
	int k, m, n, l;

	cin >> k >> m >> n;
	l = 1;
	while (m--) {
		int a, b;
		cin >> a >> b;
		if (k / a * b >= n) {
			cout << l << ' ';
		}
		l++;
	}
	return 0;
}
