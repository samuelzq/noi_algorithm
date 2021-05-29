#include <iostream>

using namespace std;

int ra[105] = {0, };
int vb[105] = {0, };

int main(void)
{
	int n, m, max = 0;
	int r, v, ans;

	cin >> n >> m;

	while (n--) {
		cin >> r;
		ra[r]++;
		if (max < r)
			max = r;
	}

	while (m--) {
		cin >> r >> v;
		if (vb[r] < v)
			vb[r] = v;
	}

	ans = 0;
	for (int i = 1; i <= max; i++) {
		if (ra[i] != 0) {
			int maxv = 0;
			for (int j = 1; j < i; j++) {
				if (maxv < vb[j])
					maxv = vb[j];
			}
			ans += maxv * ra[i];
		}
	}
	cout << ans;
	return 0;
}
