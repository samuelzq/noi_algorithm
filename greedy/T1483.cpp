#include <iostream>
#include <algorithm>

using namespace std;

int a[100005] = {0, };

int main(void)
{
	int n, b, c;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n);
	b = a[n - 2] - a[0];
	c = a[n - 1] - a[1];
	cout << (b > c ? c : b);
	return 0;
}
