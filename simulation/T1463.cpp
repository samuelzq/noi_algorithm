#include <iostream>
#include <cmath>

int prm[100000] = {0, };

using namespace std;

void initp(void)
{
	prm[0] = prm[1] = prm[4] = 1;
	for (int i = 2; i < 99992; i++) {
		if (!prm[i]) {
			if ((long long)i * i < 99992) {
				for (int j = i * i; j <= 99992; j += i)
					prm[j] = 1;
			} else {
				break;
			}
		}
	}
}

bool check(int n)
{
	int rev, t;

	t = n;
	while (t) {
		rev = rev * 10 + t % 10;
		t /= 10;
	}
	return n == rev;
}

int main(void)
{
	int n = 5;
	initp();
	while (n--) {
		int m;
		cin >> m;

		if (m > 99991)
			cout << "No\n";
		else if (!prm[m] && check(m))
			cout << "Yes\n";
		else
			cout <<"No\n";
	}
	return 0;
}
