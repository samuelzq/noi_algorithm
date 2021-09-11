#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int cost[1005];

int main(void)
{
	int t;
	string ss;

	cin >> t;

	while (t--) {
		int len, c;
		cin >> ss;

		len = ss.length();
		for (int i = 0; i < len; i++) {
			c = 0;
			for (int j = 0; j < len; j++) {
				if (i == j)
					continue;
				if (ss[i] < ss[j])
					c += ss[i]- ss[j]+26;
				else
					c += ss[i] - ss[j];
			}
			cost[i] = c;
		}
		sort(&cost[0], &cost[len]);
		cout << cost[0] << '\n';
	}
	cout << endl;
	return 0;
}
