#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int main(void)
{
	int t;

	scanf("%d",&t);

	while (t--) {
		int n, f, m2, m1;

		scanf("%d %d %d", &n, &m2, &m1);
		f = 0;
		for (int i = 2; i <= n; i++) {
			if (i % 2 == 0)   //  偶数，使用m1进行递推
				f = (f + m1) % i;
			else              //  奇数，使用m2进行递推
				f = (f + m2) % i;
		}
		printf("%d\n", f);
	}
	return 0;
}
