#include <iostream>
#include <string>

using namespace std;

char b[100];

int main(void)
{
	int i, l, r;
	string str;

	cin >> str;
	l = (str.length() + 1) / 2 - 1;
	r = l + 1;
	for (i = 0; i <= str.length(); i += 2) {
		b[i] = str[l];
		b[i + 1] = str[r];
		l--;
		r++;
	}
	if (i > str.length())
		b[i-1] = str[l];
	b[i] = 0;
	cout << b;
	return 0;
}
