#include <iostream>
#include <cstdio>

using namespace std;

int ans = 0;
int main(void)
{
	char c;
	while ((c = cin.get()) != EOF) {
		if (c == '(')
			ans++;
		else if (c == ')')
			ans--;
	}
	if (!ans)
		printf("YES");
	else
		printf("NO");
	return 0;
}
