#include <iostream>

using namespace std;
string str;

int main(void)
{
	int a, b;
	while (cin >> str) {
		if (str.length() == 1 && str[0] == '0')
			break;
		a= b = 0;
		for (int i = str.length() - 1; i >= 0 ; i -= 2)
			a += str[i] - '0';
		for (int i = str.length() - 2; i >= 0 ; i -= 2)
			b += str[i] - '0';
		a %= 11;
		b %= 11;
		if (a == b)
			cout << str << " is a multiple of 11.\n";
		else
			cout << str << " is not a multiple of 11.\n";
	}
	return 0;
}