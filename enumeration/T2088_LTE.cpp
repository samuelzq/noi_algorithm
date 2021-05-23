// 该解法无法AC。 LTE。


#include <iostream>
#include <algorithm>

using namespace std;

typedef struct {
	int idx;
	int m;
	int a;
	int b;
	int c;
	int d;
} MAGIC;

MAGIC magic[40005] = {0};

bool cmp_magic(MAGIC m1, MAGIC m2)
{
	if (m1.m == m2.m)
		return m1.idx < m2.idx;
	return m1.m < m2.m;
}

bool cmp_idx(MAGIC m1, MAGIC m2)
{
	return m1.idx < m2.idx;
}

int main(void)
{
	int n, m;

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> magic[i].m;
		magic[i].idx = i;
	}
	sort(&magic[1], &magic[m + 1], cmp_magic);

	for (int i = 1; i <= m - 3; i++) {
		if (magic[i].m > n)
			continue;
		for (int j = i + 1; j <= m - 2; j++) {
			if (magic[j].m > n)
				continue;
			if (magic[i].m == magic[j].m)
				continue;
			for (int k = j + 1; k <= m - 1; k++) {
				if (magic[k].m > n)
					continue;
				if (magic[k].m == magic[j].m)
					continue;
				for (int l = k + 1; l <= m; l++) {
					if (magic[l].m > n)
						continue;
					if (magic[l].m == magic[k].m)
						continue;
					if (magic[j].m - magic[i].m == 2 * (magic[l].m - magic[k].m) &&
							3 * (magic[j].m - magic[i].m) < magic[k].m - magic[j].m) {
						magic[i].a++;
						magic[j].b++;
						magic[k].c++;
						magic[l].d++;
					}
				}
			}
		}
	}
	sort(&magic[1], &magic[m + 1], cmp_idx);

	for (int i = 1; i <= m; i++)
		cout << magic[i].a << ' ' << magic[i].b << ' ' << magic[i].c << ' ' << magic[i].d << '\n';
	return 0;
}
