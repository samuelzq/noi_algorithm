// 从首尾同时递增，直至首位指针相遇

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int t;
	
	scanf("%d", &t);
	
	while (t--) {
		int x, y, steps;
		scanf("%d %d", &x, &y);
		steps = 0;
		for (int i = 1; x < y; i++) {
			x += i;
			steps++;
			if (x >= y)
				break;
			y -= i;
			steps++;
		}
		printf("%d\n", steps);
	}
	return 0;
}