// 使用二维数组保存计算过程中每一步的结果。
//  V1 V2 ....  Vn 
//  W1 W2 ....  Wn
//        ....
//  S1 S2 ....  Sn
// 利用递推公式依次推出Vi并输出。

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int ops_num;
	string ops;

	while (cin >> ops) {
		vector<int> nums;	// 缓存初始操作数
		vector<char> oper;  // 缓存运算符
		int cnt, n;
		cin >> n;
		cnt = 0;
		for (int i = 0; i < ops.size(); i++) {
			if (ops[i] == '*' || ops[i] == '+') {
				oper.push_back(ops[i]);
			} else if (ops[i] >= '0' && ops[i] <= '9') {
				int sign = 1;
				int temp;
				if (ops[i - 1] == '-')
					sign = -1;
				temp = 0;
				while (ops[i] >= '0' && ops[i] <= '9') {
					temp = temp * 10 + (ops[i] - '0');
					i++;
				}
				i--;
				temp *= sign;
				nums.push_back(temp);
			} else if (ops[i] == ']') {
				cnt++;
			}
		}
		int ans[cnt][n] = {0, };
		
		// 计算第一个值
		ans[cnt - 1][0] = nums[cnt - 1];
		for (int i = cnt - 2; i >= 0; i--) {
			if (oper[i] == '+')
				ans[i][0] = nums[i];
			else if (oper[i] == '*')
				ans[i][0] = nums[i]  * ans[i + 1][0];
		}
		cout << ans[0][0];
		
		// 递推后续值
		for (int i = 1; i < n; i++) {
			ans[cnt - 1][i] = nums[cnt - 1];

			for (int j = cnt - 2; j >= 0; j--) {
				if (oper[j] == '+')
					ans[j][i] = ans[j][i - 1] + ans[j + 1][i - 1];
				else if (oper[j] == '*')
					ans[j][i] = ans[j][i - 1] * ans[j + 1][i];
			}
			cout << ' ' << ans[0][i];
		}
		cout << endl;
	}
	return 0;
}