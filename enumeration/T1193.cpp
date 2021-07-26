#include <iostream>

using namespace std;

int main(void)
{
	int n;

	cin >> n;

	for (int a = 6; a <= n; a++) {
		for (int b = 2; b <= n; b++) {
			for (int c = b; c <= n; c++) {
				for (int d = c; d <= n; d++) {
					if ((b*b*b+c*c*c+d*d*d) == a*a*a)
						cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")\n";
				}
			}
		}
	}
	return 0;
}
