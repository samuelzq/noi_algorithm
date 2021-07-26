#include <iostream>

using namespace std;

int cn[10] = {0};

int main(void)
{
	int n;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		int t = i;

		while (t) {
			int d = t % 10;
			cn[d]++;
			t /= 10;
		}
	}

	for (int i = 0; i < 9; i++)
		cout << cn[i] << '\n';
	cout << cn[9];
	return 0;
}
