#include <iostream>
#include <iomanip>

using namespace std;

long long d[12][12] = {0, };

int main(void)
{
	int n;
	double ans = 0;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> d[i][j];

			if (i > 1 && j > 2) {
				long long t;
				t = d[i - 1][j -  1] + d[i][j - 1] +
				    d[i - 1][j] + d[i][j];
				if (t > ans)
					ans = (float)t;
			}
		}
	}
	cout<<fixed<<setprecision(2);
	cout << ans / 4.0 << endl;
	return 0;
}

