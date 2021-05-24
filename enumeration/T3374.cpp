#include <iostream>

using namespace std;
int f[2003] = {0};
int main(void)
{
	int x, y, ans = 0;

	cin >> x >> y;

	for (int i = 0; i < 1000 / x + 1; i++) {
		for (int j = 0; j < (1000 - x * i) / y + 1; j++) {
			f[i * x + y * j] = 1;
		}
	}

	for (int i = 1000; i > 0; i--) {
		if (f[i] == 0) {
			cout << i;
			break;
		}
	}
	return 0;
}
