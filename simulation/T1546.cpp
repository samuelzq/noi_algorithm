#include <iostream>
#include <algorithm>

using namespace std;

int buf[1005];
int n;

int main(void)
{
	int a, l;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> buf[i];

	sort(buf, buf + n);

	l = n;
	a = buf[0];
	for (int i = 1; i < n; i++) {
		if (buf[i] == a)
			l--;
		a = buf[i];
	}
	cout << l << '\n';
	a = buf[0];
	cout << a << ' ';
	for (int i = 1; i < n - 1; i++) {
		if (buf[i] != a)
			cout << buf[i] << ' ';
		a = buf[i];
	}
	if (buf[n - 1] != a)
		cout << buf[n - 1];

	return 0;
}
