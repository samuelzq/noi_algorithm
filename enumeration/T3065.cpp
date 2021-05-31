#include <iostream>

const int mod = 1000000007;

using namespace std;

long long a[100005];
int main(void)
{
	bool flag = false;
	int n;
	long long ans, maxn = -999999999;
	long long sum = 0, maxn1 = 0;

	cin >> n;
	ans = 0;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n - 1; i++) {
		if(a[i] > a[i + 1]) {
			flag = true;
			for (int j = i; j < n - 1; j++) {
				if(a[i] > a[j + 1]) {
					sum = a[i] - a[j + 1];
					maxn1=max(sum,maxn1);
				} else {
					i = j;
					break;
				}
			}
		}
		maxn = max(maxn1, maxn);
	}
	if (flag)
		cout << maxn << endl;
	else
		cout << 0 << endl;
	return 0;
}
