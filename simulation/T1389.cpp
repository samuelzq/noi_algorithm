#include <iostream>
#include <string>

int w[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 24};
char m[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
using namespace std;

int main(void)
{
	int n, c, sum;
	string id;

	cin >> n;

	c = 0;
	while (n--) {
		int i;
		cin >> id;
		sum = 0;
		i = 0;
		for (string::iterator it = id.begin(); it < id.end() - 1; it++) {
			if (*it < '0' || *it > '9') {
				sum = -1;
				c++;
				break;
			} else {
				int d = *it - '0';
				sum = sum + d * w[i];
			}
			i++;
		}
		if (sum == -1)
			cout << id << '\n';
		else {
			int crc = sum % 11;
			if (m[crc] != id[id.length() - 1]) {
				cout << id << '\n';
				c++;
			}
		}
	}
	if (c == 0)
		cout << "All passed";
	return 0;
}
