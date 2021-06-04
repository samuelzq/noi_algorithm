#include <iostream>
#include <cstring>

using namespace std;

char btree[1100000] = {0, };

int main(void)
{
	int d, i, j, k;
	bool l = false;

	while (cin >> d >> i && d != 0) {
		int idx, lidx;
		while (i--) {
		idx = 1;
		for (j = 0; j < d; j++) {
			btree[idx - 1] ^= 1;
			lidx = idx;
			if (btree[idx - 1])
				idx = 2 * idx;
			else
				idx = 2 * idx + 1;
		}
		}
		cout << lidx << '\n';
		memset(btree, 0, 1100000);
	}
}
