#include <iostream>

using namespace std;
bool f = true;
void dfs(void)
{
	long long n;

	cin >> n;
	if (n == 0)
		return;
	dfs();
	if (f == true)
		f = false;
	else
		cout << ' ';
	cout << n;
}

int main(void)
{
	dfs();
	return 0;
}
