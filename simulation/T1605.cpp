#include <iostream>

using namespace std;

int rem[42] = {0, };

int main(void)
{
	int i, ans=0;

	for (i = 0; i < 10; i++) {
		int t;
		cin >> t;
		if (!rem[t % 42])
			ans++;
		rem[t % 42]++;
	}
	cout << ans;
	return 0;
}
