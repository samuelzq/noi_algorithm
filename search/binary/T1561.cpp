#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 1e6+5;
int id[N] = {0, };

int main(void)
{
	int m, n;

	cin >> m >> n;
	for (int i = 0; i < m; i++)
		scanf("%d", &id[i]);
	sort(id, id + m);

	while (n--) {
		int k, l, r, mid = m / 2;
		scanf("%d", &k);
		l = 0;
		r = m - 1;
		while (l <= r) {
			mid = l + (r - l)/2;
			if (id[mid] == k) {
				r = mid - 1;
			} else if (id[mid] > k) {
				r = mid - 1;
			} else if (id[mid] < k) {
				l = mid + 1;
			}
		}
		if (l >= m)
			printf("%d\n", -1);
		else
			printf("%d\n", id[l]);
	}
	return 0;
}
