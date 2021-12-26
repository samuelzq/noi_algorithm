// 将字符分片根据前导'['或者']'插入队列头或尾部。

#include <bits/stdc++.h>

using namespace std;
char buf[100005];

int main(void)
{
	deque<string> output;
	string input;
	bool b_o_f = true;

	while (cin >> input) {
		int len = input.length();
		int l, i;
		l = 0, i = 0;
		while (i < len) {
			if (input[i] == '[') {
				if (l != 0) {
					buf[l] = 0;
					l = 0;
					string str = buf;
					if (b_o_f == true)
						output.push_front(str);
					else
						output.push_back(str);
					//cout << str << ' '  << b_o_f << endl;
				}
				b_o_f = true;
				i++;
				continue;
			}
			if (input[i] == ']') {
				if (l != 0) {
					buf[l] = 0;
					l = 0;
					string str = buf;
					if (b_o_f == true)
						output.push_front(str);
					else
						output.push_back(str);
					//cout << str << ' '  << b_o_f << endl;
				}
				b_o_f = false;
				i++;
				continue;
			}
			if (input[i] != '[' && input[i] != ']')
				buf[l++] = input[i];
			i++;
		}

		if (l) {
			buf[l] = 0;
			string str = buf;
			if (b_o_f == true)
				output.push_front(str);
			else
				output.push_back(str);
		}
		while (!output.empty()) {
			string str = output.front();
			output.pop_front();
			cout << str;
		}
		cout << endl;
	}
	return 0;
}