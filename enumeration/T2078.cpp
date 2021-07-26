#include <iostream>

using namespace std;

int isprm(int a, int b)
{
	int z;

	if (a < b) {
		z = b;
		b = a;
		a = z;
	}

	z = a % b;
	while (z) {
		a = b;
		b = z;
		z = a % b;
	}
	return b;
}

int main(void)
{
	int a, b, l;
	double r1, r2, det, r;

	cin >> a >> b >> l;
	det = a > b ? a : b;

	if (l == 1) {    // 注意：极端情况，否则不能AC。
		cout << 1 << ' ' << 1;
		return 0;
	}

	r1 = (double)a / (double)b;

	for (int i = 1; i <= l; i++) {
		for (int j = 1; j <= l; j++) {
			if (isprm(j, i) != 1)
				continue;
			r2 = (double)j / (double)i;
			if (r2 >= r1 && (r2 - r1) < det) {
				det = r2 - r1;
				b = i;
				a = j;
			}
		}
	}
	cout << a << ' ' << b;
	return 0;
}
