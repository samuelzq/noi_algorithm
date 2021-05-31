#include <iostream>

using namespace std;

// suanfan
int al = 0;
int allB = 1;
long long blocks[4][8];

string expr1[] = {
	"B+C*B",
	"B*C+B",
	"B-C*B",
	"B*C-B",
	"B+C-B",
	"B-C+B",
	"B"
};

string expr2[] = {
	"B+B*B",
	"B*B+B",
	"B-B*B",
	"B*B-B",
	"B+B-B",
	"B-B+B",
	"B"
};

int func0(int b, int c)
{
	return (b + c) * b;
}

int func1(int b, int c)
{
	return b * c + b;
}

int func2(int b, int c)
{
	return (b - c) * b;
}

int func3(int b, int c)
{
	return b * c - b;
}

int func4(int b, int c)
{
	return b + c - b;
}

int func5(int b, int c)
{
	return b - c + b;
}

int func6(int b, int c)
{
	return b;
}

int (*ff[] )(int b, int c) = {
	func0,
	func1,
	func2,
	func3,
	func4,
	func5,
	func6,
};

int main(void)
{
	bool f = false;
	int i, j;
	for (i = 0; i < 7; i++)
		cin >> blocks[2][i];
	for (i = 0; i < 8; i++)
		cin >> blocks[3][i];

	for (j = 0; j < 7; j++) {
		for (i = 0; i < 7; i++) {
			if (blocks[2][i] != ff[j](blocks[3][i], blocks[3][i + 1]))
				break;
		}
		if (i == 7)
			break;
	}
	if (j == 7)  {// all in B?
		allB = 0;
	for (j = 0; j < 7; j++) {
		for (i = 0; i < 7; i++) {
			if (blocks[2][i] != ff[j](blocks[3][i], blocks[3][i]))
				break;
		}
		if (i == 7)
			break;
	}
	}

	for (i = 0; i < 6; i++)
		blocks[1][i] = ff[j](blocks[2][i], blocks[2][i + allB]);
	for (i = 0; i < 5; i++)
		blocks[0][i] = ff[j](blocks[1][i], blocks[1][i + allB]);

	for (i = 0; i < 4; i++) {
		int k;
		for (k = 0; k < 4 + i; k++)
			cout << blocks[i][k] << ' ';
		cout << blocks[i][k] << '\n';
	}
	if (allB)
		cout << "A=" << expr1[j];
	else
		cout << "A=" << expr2[j];

	return 0;
}

