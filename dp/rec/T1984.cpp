#include <iostream>

using namespace std;#include <iostream>

using namespace std;

const int mod = 1000000007;
const int N = 2004;
int dp[N] = {0, };
int main(void)
{
	int n, m, tmp, tmp1;

	cin >> n >> m;
	tmp = dp[0] = 1;

	for (int i = 1; i <= n; i++) {
		tmp = dp[0];
		for (int j = 1; j <= i; j++) {

			if (j == i)
				dp[j] = 1;
			else {
				tmp1 = dp[j];
				dp[j] = (tmp + dp[j])% mod;
			}
			tmp = tmp1;
			//cout << dp[j] << '_' << tmp1 << ' ';
		}
		//cout << '\n';
	}
	cout << dp[m];
}