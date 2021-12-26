#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	long long a, b, k;
	k = 0;
	while (scanf("%lld%lld", &a, &b)) {
		if (a < 0 && b < 0)
			break;
		k++;
		long long s, n;
		n = a;
		s = 1;
		while (n > 1) {
			if (n & 1)
				n = n * 3 + 1;
			else
				n /= 2;
			//printf("%d ", n);
			if (n > b)
				break;
			s++;
		}
		printf("Case %d: A = %lld, limit = %lld, number of terms = %lld\n",
			   k, a, b, s);
	}
	return 0;
}