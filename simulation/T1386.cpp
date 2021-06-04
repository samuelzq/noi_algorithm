#include <iostream>

using namespace std;

int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool check(int y)
{
	if (y % 4 == 0 && y % 100 != 0)
		return true;
	else if (y % 400 == 0)
		return true;
	else
		return false;
}

int main(void)
{
	int y, m, d, ans;

	cin >> y >> m >> d;
	ans = 0;
	for (int i = 0; i < m - 1; i++)
		ans += days[i];
	ans += d;
	if (m > 2 && check(y))
		ans += 1;
	cout << ans;
	return 0;
}
