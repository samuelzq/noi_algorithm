#include <iostream>

using namespace std;

int s[12][12] = {0, };

int main(void)
{
	int n;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> s[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << s[i - 1][j - 1] + s[i - 1][j] + s[i - 1][j + 1]
				+ s[i][j - 1] + s[i][j] + s[i][j + 1]
				+ s[i + 1][j - 1] + s[i + 1][j] + s[i + 1][j + 1] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
