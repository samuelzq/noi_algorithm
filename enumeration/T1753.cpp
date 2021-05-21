#include <iostream>
#include <cmath>

using namespace std;
int bit[6] = {0,};

int main(void)
{
	int m, n, l = 0;
	bool f = false;

	cin >> m >> n;

	for (int i = m; i <= n; i++) {
		int s, t = i;
		l = s = 0;
		while (t) {
			bit[l] = t % 10;
			t /= 10;
			l++;
		}

		for (int j = 0; j < l; j++)
			s += pow(bit[j], l);
		if (s == i) {
			f = true;
			cout << i << '\n';
		}
	}
	if (f == false)
		cout << "No solution!";
	return 0;
}
