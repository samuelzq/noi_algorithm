#include <iostream>

using namespace std;

int main(void)
{
	int n, k, x = 0;

	cin >> n >> k;

	while ((x/k)*(x%k) != n)
		x++;
	cout << x << endl;
	return 0;
}
