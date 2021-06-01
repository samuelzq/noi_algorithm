#include <iostream>
#include <string>

using namespace std;

string p[] = {
	"ling",
	"yi",
	"er",
	"san",
	"si",
	"wu",
	"liu",
	"qi",
	"ba",
	"jiu"
};

int main(void)
{
	string str;

	cin >> str;

	if (str[0] == '-')
		cout << "fu";
	else
		cout << p[str[0] - '0'];
	for (int i = 1; i < str.length(); i++) {
		cout << ' ' << p[str[i] - '0'];
	}
	return 0;
}
