#include <iostream>
#include <bitset>

using namespace std;

int main(void)
{
	int n, k;

	cin >> n >> k;

	if (n < k) {
		cout << "NO";
		return 0;
	}

	bitset<64>bs(n);
	if (bs.count() > k)
		cout << "NO";
	else
		cout << "YES";
	return 0;
}
