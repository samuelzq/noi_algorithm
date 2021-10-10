#include <bits/stdc++.h>

using namespace std;

const int N = 1000;
int c[N];

int main(void)
{
	int n;

	scanf("%d", &n);
	while (n--) {
		int a, avg, sum;
		scanf("%d", &a);

		avg = sum = 0;
		for (int i = 0; i < a; i++) {
			scanf("%d", &c[i]);
			sum += c[i];
		}
		avg = sum / a;
		sum = 0;
		for (int i = 0; i < a; i++) {
			if (c[i] > avg)
				sum += 1;
		}
		printf("%.3f%c\n", 100 * (double)sum / (double)a, '%');
	}
	return 0;
}