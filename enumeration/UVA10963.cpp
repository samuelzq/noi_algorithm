#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n;

	scanf("%d", &n);

	while (n--) {
		int w, t;
		int y1, y2, g;
		scanf("%d", &w);
		t = g = 0;
		scanf("%d %d", &y1, &y2);
		g = y1 - y2;
		while (--w) {
			scanf("%d %d", &y1, &y2);
			if (t == 1)
				continue;
			else {
				if (g != y1 - y2)
					t = 1;
			}
		}
		if (t)
			printf("no\n");
		else
			printf("yes\n");
	}
	return 0;
}