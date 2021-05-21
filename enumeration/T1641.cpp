#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int len, ans;
	string str;

	cin >> len;
	cin >> str;
	len = str.length();

	ans = 0;
	for (int i = 0; i < len - 1; i++) {
		if (str[i] == 'V' && str[i+1] == 'K') {
			str[i] = str[i+1] = ' ';
			i++;
			ans++;
			continue;
		}
	}
	for (int i = 0; i < len - 1; i++) {
		if (str[i] == 'V' && str[i+1] == 'V') {
			i++;
			ans++;
			break;
		}
		if (str[i] == 'K' && str[i+1] == 'K') {
			i++;
			ans++;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
