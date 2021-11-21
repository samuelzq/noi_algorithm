#include <iostream>

using namespace std;

int main(void)
{
	long long a, b;

	while (cin >> a >> b) {
		long long  c;
		if (b >= a)
			c = b - a;
		else
			c = a - b;
		cout << c << '\n';
	}
	return 0;
}