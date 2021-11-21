#include <iostream>

using namespace std;
const int N = 55;
int s[N * 2][2];

int main(void)
{
	int n, m, sum;
	while (scanf("%d", &n) && n) {
		m = 2 * n;
		for (int i = 0; i < m; i++)
			scanf("%d%d", &s[i][0], &s[i][1]);

		while (1) {
			int i = rand() % 1001 - 500;
			int j = rand() % 1001 - 500;
			sum = 0;
			for (int k = 0; k < m; k++) {
				if (i * s[k][0] + j * s[k][1] > 0)
					sum++;
				else if (i * s[k][0] + j * s[k][1] == 0)
					break;
			}
			if (sum == n) {
				printf("%d %d\n", i, j);
				break;
			}
		}
	}
	return 0;
}