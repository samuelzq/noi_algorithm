#include <iostream>

using namespace std;

int main(void)
{
	int ans = 0;

	for (int i = 1; i < 8; i++) {
		int d, o;
		cin >> d >> o;
		if (!ans && d + o > 8)
			ans = i;
	}
	cout << ans;
	return 0;
}
