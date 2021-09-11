#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int x, y, t, l;
	string str;

	x = y = 0;
	cin >> str;
	cin >> t;
	l = str.length();
	for (int i = 0; i < l; i++) {
		switch (str[i % l]) {
			case 'E':
				x += 1;
				break;
			case 'S':
				y -= 1;
				break;
			case 'W':
				x -= 1;
				break;
			case 'N':
				y += 1;
				break;
		}
	}
	x = x * (t / l);
	y = y * (t / l);

	for (int i = 0; i < t % l; i++) {
		int l = str.length();
		switch (str[i % l]) {
			case 'E':
				x += 1;
				break;
			case 'S':
				y -= 1;
				break;
			case 'W':
				x -= 1;
				break;
			case 'N':
				y += 1;
				break;
		}
	}
	cout << x << ' ' << y;
	return 0;
}
