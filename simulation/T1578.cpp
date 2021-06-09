#include <iostream>

using namespace std;

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int leaps(int y1, int y2)
{
	int l = 0;
	for (int i = y1 + 1; i < y2; i++) {
		if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))
			l++;
	}
	return l;
}

bool leap(int y)
{
	return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}
int main(void)
{
	int y1, m1, d1;
	int y2, m2, d2;
	long long ans = 0;

	cin >> y1 >> m1 >> d1;
	cin >> y2 >> m2 >> d2;

	ans = (y2 - y1) * 365 + leaps(y1, y2);
	if (leap(y1) && m1 <= 2)
		ans++;
	if (m2 > 2 && leap(y2))
		ans++;

	if (m2 == m1) {
		ans += d2 - d1;
	} else if (m2 > m1) {
		ans += days[m1] - d1;
		for (int i = m1 + 1; i < m2; i++)
			ans += days[i];
		ans += d2;
	} else {
		ans -= days[m2] - d2;
		for (int i = m2 + 1; i < m1; i++)
			ans -= days[i];
		ans -= d1;
	}
	cout << ans;
	return 0;
}
