#include <iostream>
#include <algorithm>

using namespace std;


int sum[90] = {0,};

int main(void)
{
	int s1, s2, s3, k, ans = 0;

	cin >> s1 >> s2 >> s3;

	for (int i = 1; i <= s1; i++) {
		for (int j = 1; j <=s2; j++) {
			for (int k = 1; k <= s3; k++) {
				int idx = i + j + k;
				sum[idx]++;
			}
		}
	}

	for (int i = 3; i <= s1 + s2 + s3; i++) {
		if (k < sum[i]) {
			k = sum[i];
			ans = i;
		}
	}
	cout << ans << endl;
	return 0;
}
