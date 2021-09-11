#include <iostream>

using namespace std;

int main(void)
{
	int n, ans = 0;

	cin >> n;

	for (int i = 0; i <= n; i++) {
		if ((i ^ (2 * i) ^ (3 * i)) == 0)
			ans++;
	}
	cout << ans << endl;
	return 0;
}
