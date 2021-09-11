#include <iostream>

using namespace std;

int main(void)
{
	int a, b, c;
	int n;

	cin >> n;

	while (n--) {
		int i;
		cin >> a >> b >> c;

		for (i = 1000; i <= 9999; i++) {
			if (i % a != 0)
				continue;
			if ((i + 1) % b != 0)
				continue;
			if ((i + 2) % c != 0)
				continue;
			break;
		}
		if (i == 10000)
			cout << "Impossible" << '\n';
		else
			cout << i << '\n';
	}
	cout << endl;
	return 0;
}
