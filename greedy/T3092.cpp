#include <iostream>

using namespace std;

int main(void)
{
	int x, i;

	cin >> x;

	while (x > 9) {
		x -= 9;
		i++;
	}
	cout << x;
	while (i--)
		cout << 9;
	return 0;
}
