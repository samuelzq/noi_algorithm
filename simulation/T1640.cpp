#include <iostream>

using namespace std;
int code[35];
int ans[8];
int t[8];

int main(void)
{
	int n, i;

	cin >> n;
	for (i = 0; i < 7; i++) {
		int c;
		cin >> c;
		code[c] = 1;
	}

	while (n--) {
		int g, m = 0;
		for (i = 0; i < 7; i++) {
			cin >> g;
			if (code[g])
				m++;
		}
		t[7 - m]++;
	}

	for (i = 0; i < 6; i++)
		cout << t[i] << ' ';
	cout << t[6];
	return 0;
}
