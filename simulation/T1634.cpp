#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int m, l;
	string str;

	cin >> m >> str;

	l = str.length();
	for (int i = 0; i < l - 1; i++) {
		if (str[i] != '0')
			cout << str[i] << '*' << m << '^' << l-1-i << '+';
	}
	cout << str[l - 1] << '*' << m << '^' << 0;
	return 0;
}
