#include <iostream>
#include <string>

using namespace std;

int cc[26] = {
	1, 2, 3, 1, 2, 3,
	1, 2, 3, 1, 2, 3, 1, 2, 3,
	1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};

int main(void)
{
	string str;
	int ans = 0;

	getline(cin, str);
	for (string::iterator it = str.begin(); it < str.end(); it++) {
		if (*it == ' ')
			ans += 1;
		else
			ans += cc[*it - 'a'];
	}
	cout << ans;
	return 0;
}
