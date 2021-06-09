#include <iostream>

using namespace std;

int main(void)
{
	int n, d1, d2;
	long long ans = 0;
	cin >> n;
	cin >> d1;
	for (int i = 1; i < n; i++) {
		cin >> d2;
		ans += d2 > d1 ? d2 : d1;
		d1 = d2;
	}
	cout << ans;
	return 0;
}
