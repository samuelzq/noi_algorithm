#include <iostream>

using namespace std;

int cnt[7] = {0, };
int m[12] = {31, 31, 28, 31, 30, 31, 30,
		 31, 31, 30, 31, 30};

bool leap(int y)
{
	return (y % 4 == 0 && y % 100) || y % 400 == 0;
}

int main(void)
{
	int y, n, i, j, d;

	cin >> n;
	y = 1900;
	d = 3;
	for (j = y; j < y + n; j++) {
		if (leap(j))
			m[2] = 29;
		else
			m[2] = 28;
		for (i = 0; i <= 11; i++) {
			d = (d + m[i]) % 7;
			cnt[d]++;
		}
	}

	cout << cnt[6] << ' ' << cnt[0];
	for (i = 1; i < 6; i++)
		cout << ' ' << cnt[i];
	return 0;
}
