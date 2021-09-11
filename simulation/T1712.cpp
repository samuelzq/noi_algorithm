#include <cstdio>
#include <string>
#include <iostream>

using namespace std;
char bf[100] = {0,};

int str2i(string &str)
{
	int a = 0;

	for (int i = 0; i < str.length(); i++)
		a = 10 * a + str[i] - '0';
	return a;
}

int main(void)
{
	int n;
	string str;
	char op = 0;
	cin >> n;

	while (n--) {
		string c;
		int o1, o2, i, l, d;
		cin >> c;

		if (c[0] == 'a') {
			op = '+';
			cin >> c;
		} else if (c[0] == 'b') {
			op = '-';
			cin >> c;
		} else if (c[0] == 'c') {
			op = '*';
			cin >> c;
		}
		o1 = str2i(c);
		cin >> c;
		o2 = str2i(c);
		if (op == '+') {
			d = o1 + o2;
		} else if (op == '*') {
			d = o1 * o2;
		} else if (op == '-') {
			d = o1 - o2;
		}

		l = sprintf(bf, "%d%c%d=%d", o1, op, o2, d);
		printf("%s\n%d\n", bf, l);
	}
	return 0;
}
