#include <iostream>

using namespace std;

int main(void)
{
	int n, m, i, sum, t;

	cin >> n >> m;

	i = 1;
	sum = 0;
	t = n;
	while (n) {
		sum += i * 2;
		if (i % m == 0) {
			cout << sum / m << ' ';
			sum = 0;
		}
		i++;
		n--;
	}
	if (sum)
		cout << sum / (t % m);

	return 0;
}
