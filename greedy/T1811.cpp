#include <iostream>
#include <algorithm>

using namespace std;

int x[102] = {0, };
int y[102] = {0, };

int main(void)
{
	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x[i];
	for (int i = 0; i < n; i++)
		cin >> y[i];
	sort(x, x + n);
	sort(y, y + n);

	for (int i = 0; i < n; i++) {
		if (x[i] > y[i]) {
			cout << "NE";
			return 0;
		}
	}
	cout << "DA";
	return 0;
}
