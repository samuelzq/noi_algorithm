#include <iostream>

using namespace std;

int main(void)
{
	int a, b;
	bool f = false;

	cin >> a >> b;

	for (int i = a * 100 / b; i < (a + 1) *100 / b + 1; i++) {
		int t = i * b;
		if (t >= a * 100 && t < (a + 1) * 100) {
			f = true;
			cout << t << '\n';
		}
	}
	if (f == false)
		cout << -1;
	return 0;
}
