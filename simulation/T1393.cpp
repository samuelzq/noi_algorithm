#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string str;

	cin >> str;

	for (string::iterator it = str.begin(); it < str.end(); it++) {
		if (*it == 'X')
			*it = 'A';
		else if (*it == 'Y')
			*it = 'B';
		else if (*it == 'Z')
			*it = 'C';
		else if (*it == 'x')
			*it = 'a';
		else if (*it == 'y')
			*it = 'b';
		else if (*it == 'z')
			*it = 'c';
		else if ((*it >= 'A' && *it <= 'W') ||
			 (*it >= 'a' && *it <= 'w'))
			*it = *it + 3;
		else
			continue;
	}
	cout << str;
	return 0;
}
