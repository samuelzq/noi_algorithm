#include <bits/stdc++.h>

using namespace std;
const int N = 1e6+3;
bool student[N];

int josephus(int n, int k)
{
	int i, cur;

	for (i = 0; i < n; i++)
		student[i] = true;

	cur = 0;
	for (i = 1; i < n; i++)  {
		//跑n次
		int count = k;

		while (count) {
			count--;
			if (!count)
				student[cur] = false;

			if (i & 1) {
				do {
					cur++;
					if (cur == n)
						cur = 0;
				} while (!student[cur]);
			} else {
				do {
					cur--;
					if (cur < 0)
						cur = n - 1;
				} while (!student[cur]);
			}
		}
	}
	return cur;
}

int main(void)
{
	int n, k;

	while (scanf("%d %d", &n, &k) != EOF && n && k) {
		printf("%d\n", josephus(n, k) + 1);
	}
	return 0;

}
