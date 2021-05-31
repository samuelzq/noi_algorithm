#include <iostream>

using namespace std;

const char digs[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'K', 'L', 'M', 'N', 'O'};

char org[32] = {0};
char bits[32] = {0};

int main(void)
{
	int b, n, s, l, lo, t;

	cin >> b;

	for (int i = 1; i <= 300; i++) {
		int j = 0;
		s = i * i;
		t = i;
		lo = 0;
		while (t) {
			int idx = t % b;
			org[lo] = digs[idx];
			lo++;
			t /= b;
		}
		t = s;
		l = 0;
		while (t) {
			int idx = t % b;
			bits[l] = digs[idx];
			l++;
			t /= b;
		}

		for (j = 0; j < l / 2; j++) {
			if (bits[j] != bits[l - 1 - j])
				break;
		}
		if (j == l / 2) {
			for (int j = lo - 1; j >= 0; j--)
				cout << org[j];
			cout << ' ';
			for (int j = l - 1; j >= 0; j--)
				cout << bits[j];
			cout << '\n';
			//cout << i << ' ' << s << '\n';
		}
	}
	return 0;
}
