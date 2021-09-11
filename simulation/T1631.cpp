#include <iostream>

using namespace std;

int main(void)
{
	int n, j, l = 0;

	cin >> n;

	j = 0;
	for (int i = 0; i < n;) {
		int o, m;
		o = l % 2;
		cin >> m;
		l++;
		for (int k = 0; k < m; k++) {
			cout << o;
			j++;
			if (j % n == 0) {
				cout << '\n';
				i++;
			}
		}
	}
	return 0;
}
