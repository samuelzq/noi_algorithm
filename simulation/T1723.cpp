#include <iostream>

using namespace std;

int yue[100] = {0, };

int main(void)
{
	int n, m, idx, d;

	cin >> n >> m;

	idx = 0;
	d = n;
	while (d--) {
		int j, i, k = 0;
		i = 0;
		do {
			j = (idx + k + i) % n;
			if (yue[j]) {
				i++;
			} else {
				k++;
			}

		} while (k < m);
		idx = j;
		yue[j] = 1;
		cout << idx + 1 << ' ';
		idx = (idx + 1) % n;
	}
	return 0;
}
