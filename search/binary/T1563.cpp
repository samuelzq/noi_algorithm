#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 1e6+5;
int id[N] = {0, };

int main(void)
{
	int m, n, r1, l1;

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
				l = mid + 1;
			} else if (id[mid] > k) {
				r = mid - 1;
			} else if (id[mid] < k) {
				l = mid + 1;
			}
		}
		if (r < l && id[l - 1] != k) {
			printf("%d\n", 0);
			continue;
		}
		r1 = l;
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
		printf("%d\n", r1 - l);
	}
	return 0;
}
