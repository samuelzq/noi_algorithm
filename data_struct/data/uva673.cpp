/**
 * Parentheses Balance UVA - 673
 * https://vjudge.net/problem/UVA-673
 *
 * 使用stack记录所有的做括号，然后比对输入。
 * 非法输入的情况有以下几种：
 *     1、“[”遇到“)”或者“(”遇到“]”
 *     2、stack中有尚未匹配的左括号
 *     3、空字符串应该视为合法输入
 *
 * @File:   uva514.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2021-12-27
 *
 **/

#include <bits/stdc++.h>

using namespace std;
stack<char> lbrace;
char buf[256];

int geti(void)
{
	char c;
	int ret = 0;
	while (c = getchar()) {
		if (c < '0' || c > '9')
			break;
		ret = ret * 10 + (c - '0');
	}
	return ret;
}

int main(void)
{
	int n;
	bool correct = true;
	n = geti();
	while (n--) {
		gets(buf);
		correct = true;

		for (int i = 0; i < strlen(buf) && correct == true; i++) {
			if (buf[i] == '(' || buf[i] == '[')
				lbrace.push(buf[i]);
			else if (buf[i] == ']') {
				if (lbrace.empty()) {
					correct = false;
					break;
				} else {
					if (lbrace.top() != '[')
						correct = false;
					lbrace.pop();
				}
			} else if (buf[i] = ')') {
				if (lbrace.empty()) {
					correct = false;
					break;
				} else {
					if (lbrace.top() != '(')
						correct = false;
					lbrace.pop();
				}
			}
		}

		while (!lbrace.empty()) {
			lbrace.pop();
			correct = false;
		}
		if (correct == true)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}