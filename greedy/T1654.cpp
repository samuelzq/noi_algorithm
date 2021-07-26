#include <iostream>

using namespace std;

int main(void)
{
	int n, m, a, sum;
	int ans = 1;

	cin >> n >> m;
	sum = 0;
	while (n--) {
		cin >> a;
		sum += a;
		if (sum > m) {
			ans++;
			sum = a;
		}
	}
	cout << ans;
	return 0;
}
