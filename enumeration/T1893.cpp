#include <iostream>
#include <algorithm>

using namespace std;

int a[100005];
int n;
int main()
{
	cin >> n;
	int minn = 0x3f3f3f3f;

    for (int i = 1; i <= n; i++)
		cin >> a[i];

	sort(a + 1, a + 1 + n);

	for (int i = 0; i <= 100-17; i++) {
		int ans=0;
		for (int j = 1; j <= n; j++) {
				 if (a[j] < i)
					ans = ans + (a[j] - i) *(a[j] - i);
				 else if (a[j] > i + 17)
					ans = ans + (a[j] - i - 17) *(a[j] - i - 17);
		}
		minn = min(minn, ans);
	}
	cout << minn;
	return 0;
}
