#include <iostream>

using namespace std;

int cc[10] = {0, };

int main(void)
{
	long long n, m;

	cin >> n >> m;
	for (long long i = n; i <= m; i++) {
		long long t = i;
		while (t) {
			cc[t % 10]++;
			t /= 10;
		}
	}
	for (int i = 0; i < 9; i++)
		cout << cc[i] << ' ';
	cout << cc[9];
	return 0;
}
