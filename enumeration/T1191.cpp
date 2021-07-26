#include <iostream>

using namespace std;
int main(void)
{
	int n = 0;
	int a, c, r;
	int max=0, min=0x7ffffff;

	cin >> n;

	a = n >> 2;

	for (c = 0; c <= n / 2; c++) {
		// 先枚举鸡的数量
		for (r = 0; r <= (n-c*2) / 4; r++) {
			// 再枚举兔子的数量
			if (c*2+r*4 != n)
				continue;
			if (c + r < min)
				min = c + r;
			if (c + r > max)
				max = c + r;
		}
	}

	if (max != 0)
		cout << min << ' ' << max;
	else
		cout << 0 << ' ' << 0;

	return 0;
}
