#include <iostream>

using namespace std;

int a[3][3];

int main(void)
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			cin >> a[i][j];

	cout << a[0][0] + a[1][1] + a[2][2] << ' '
		<< a[2][0] + a[1][1] + a[0][2];
	return 0;
}
