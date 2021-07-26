#include <iostream>
int num[10005];
using namespace std;
int main(void)
{
	int n, d;

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> num[i];

	cin >> d;

	for (int i = 1; i <= n; i++) {
		if (d == num[i]) {
			cout << i << '\n';
			return 0;
		}
	}
	cout << -1 << '\n';
	return 0;
}

