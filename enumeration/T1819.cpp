javascript:void(0)#include <iostream>

using namespace std;

const int sq[6][3] = {
	{1, 2, 3},
	{1, 3, 2},
	{2, 1, 3},
	{2, 3, 1},
	{3, 2, 1},
	{3, 1, 2}
};

long long ef[4][4] = {0};

int main(void)
{
	long long t, ans = 0;

	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			cin >> ef[i][j];

	for (int i = 0; i < 6; i++) {
		t = ef[1][sq[i][0]] + ef[2][sq[i][1]] + ef[3][sq[i][2]];
		if (ans < t)
			ans = t;
	}
	cout << ans;
	return 0;
}
