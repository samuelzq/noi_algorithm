#include <iostream>

using namespace std;

int dp[1005];
int w[7] = {0, 1, 2, 3, 5, 10, 20};
int num[7];

int main(void)
{
	int t, sum = 0;
	for (int i = 1; i <= 6; i++) {
		cin >> num[i];
		sum += num[i] * w[i];
	}

	dp[0] = 1;
	for (int i = 1; i<= 6; i++) {
		for (int k = 1; k <= num[i]; k++)
			for (int j = sum; j >= k * w[i]; j--)
				if (dp[j - k * w[i]])
					dp[j] = 1;
	}

	t = 0;
	for (int i = 1; i <= sum; i++)
		if (dp[i])
			t++;
	cout << "Total=" << t;
	return 0;
}
