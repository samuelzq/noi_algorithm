#include <iostream>

using namespace std;

typedef struct {
	int x_sum;
	int y_sum;
} SUM;
SUM num[1005][1005] = {0,};
int d[1005][1005] = {0,};

int main(void)
{
	int n, k, sum, ans = 0;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> k;
			d[i][j] = k;
			num[i][j].x_sum = k + num[i][j-1].x_sum;
			num[i][j].y_sum = k + num[i-1][j].y_sum;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j] != 0)
				continue;
			sum = num[i][n].x_sum + num[n][j].y_sum;
			if (sum > ans)
				ans = sum;
		}
	}
	cout << ans << endl;
	return 0;
}
