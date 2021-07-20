#include <string.h>
#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

string a, b, target;
int num;

int dfs(string s1, string s2, int step)
{
	if (s1 + s2 == target)
		return step;

	string temp = "";
	for (int i = 0; i < num; i++)
		temp = temp + s2[i] + s1[i];

	s1 = temp.substr(0, num);
	s2 = temp.substr(num, num);
	if (s1.compare(a) == 0 && s2.compare(b) == 0)
		return -1;
	else
		return dfs(s1, s2, step + 1);
}

int main(void)
{
	int Case;
	cin >> Case;

	for (int T = 1; T <= Case; T++) {
		cin >> num >> a >> b >> target;
		cout << T << ' ' << dfs(a, b, 0) << endl;
	}
	return 0;
}
