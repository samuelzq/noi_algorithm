#include <iostream>

using namespace std;

int num[1005];

int main(void)
{
	bool f = false;
	int n, k;

	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> num[i];

	for (int i = 0; i < n - 1 && f == false; i++) {
		for (int j = i + 1; j < n && f == false; j++) {
			if (num[i] + num[j] == k)
				f = true;
		}
	}

	if (f)
		cout << "yes";
	else
		cout << "no";

	return 0;
}
