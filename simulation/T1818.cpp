#include <iostream>

using namespace std;

int main(void)
{
	int n, ans;

	cin >> n;
	ans = 0;
	while (n > 1) {
		if (n % 2 == 1)
			n = n * 3 + 1;
		else
			n /= 2;
		ans++;
	}
	cout << ans;
	return 0;
}
