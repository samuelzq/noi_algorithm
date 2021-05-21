#include <iostream>

using namespace std;

long long num[12];
const long long P = 12*11*10*9*8*7*6*5*4*3*2;

int main(void)
{
	int n, ans = 0;

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> num[i];

	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (P == num[i] * num[j])
				ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
