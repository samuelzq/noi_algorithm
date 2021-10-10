#include <bits/stdc++.h>

using namespace std;

const int N = 3003;
int c[N];

int main(void)
{
	int n, a, b;
	//freopen("UVA10038.out", "w", stdout);
	while (cin >> n) {
		bool j = true;
		memset(c, 0, sizeof(c));
		cin >> b;
		for (int i = 0; i < n - 1; i++) {
			int d;
			cin >> a;
			d = abs(a - b);
			if ((d > n - 1) || (c[d]) || j == false) {
				j = false;
				continue;
			}
			c[d] = 1;
			b = a;
		}

		cout << (j ? "Jolly\n" : "Not jolly\n");
	}
	//fclose(stdout);
	return 0;
}