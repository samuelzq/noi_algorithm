#include <iostream>

using namespace std;

int main(void)
{
	int k, s1, s2, s3;
	bool f = false;

	cin >> k;

	for (int i = 10000; i <= 30000; i++) {
		s1 = i % 1000;
		s2 = (i / 10) % 1000;
		s3 = i / 100;

		if (s1 % k == 0 && s2 % k == 0 && s3 % k == 0) {
			f = true;
			cout << i << '\n';
		}
	}

	if (f == false)
		cout << "No";
	cout << endl;
	return 0;
}
