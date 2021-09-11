#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int l, c, ans;
	string stra, strb, strc;

	cin >> stra >> strb >> strc;

	ans = 0;
	l = stra.length();
	for (int i = 0; i < l; i++) {
		if ((stra[i] == strb[i] && strb[i] != strc[i]) ||
		    (stra[i] == strc[i] && stra[i] != strb[i]) ||
		    (strb[i] == strc[i] && stra[i] != strb[i]))
			ans += 1;
		else if (stra[i] != strb[i] && strb[i] != strc[i] && strc[i] != stra[i])
			ans += 2;
	}
	cout << ans;
	return 0;
}
