#include <iostream>
#include <cstdlib>

using namespace std;

int main(void)
{
	int n, m, a;

	cin >> n >> m;

	a = 1;

	while (a <= n && (a == m || n % a != 0 || n % abs(m -a) != 0))
		a++;

	if (a > n)
		cout << -1;
	else
		cout << a;
	return 0;
}
