#include <iostream>

using namespace std;

int main(void)
{
	int a, b, c, ans = 0;
	int x, y, z;

	cin >> a >> b >> c;

	x = 0;
	z = x * a + y * b;

	while (x < c/a + 1) {
		y = 0;
		while (y < c/b + 1) {
			z = x * a + y * b;
			if (z == c)
				ans++;
			y++;
		}
		x++;
	}
	cout << ans;
	return 0;
}
