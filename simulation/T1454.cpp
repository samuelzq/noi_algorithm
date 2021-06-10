#include <iostream>

using namespace std;

int a[5];

int main(void)
{
	bool l, o = false;
	int m;
	for (int i = 0; i < 4; i++)
		cin >> a[i];

	cin >> m;
	if (a[0] > a[1])
		l = true;
	else
		l = false;

	for (int i = 0; i < 4; i++) {
		if (l == false) {
			if (a[i] > m && o == false) {
				cout << m << '\n';
				o = true;
			}
			cout << a[i] << '\n';
		} else {
			if (a[i] < m && o == false) {
				cout << m << '\n';
				o = true;
			}
			cout << a[i] << '\n';
		}
	}

	if (o == false)
		cout << m;
	return 0;
}
