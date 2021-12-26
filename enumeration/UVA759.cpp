#include <bits/stdc++.h>

using namespace std;

const int N = 500;
char rome[N];
char rome2[N];

const char rcode[13][3] = {"M", "CM", "D", "CD", "C", "XC", "L",
					"XL", "X", "IX", "V", "IV", "I"};
const int val[14] = {1000, 900, 500, 400, 100, 90, 50,
					40, 10, 9, 5, 4, 1, 0};

char* toRoman(int num)
{
    char *roman = rome2, idx = 0;
    int i;
    for(i = 0; i < 13; i++) {
        while(num >= val[i]) {
            num -= val[i];
            roman[idx++] = rcode[i][0];
            if(rcode[i][1] != '\0')
                roman[idx++] = rcode[i][1];
        }
    }
    roman[idx] = '\0';
    return roman;
}

char *to_digit(char *rome, int &v)
{

	char tmp[3] = {0};
	int val1, val2, idx;

	tmp[0] = rome[0];
	for (idx = 0; idx < 13; idx++) {
		if (!strcmp(tmp, rcode[idx]))
			break;
	}
	val1 = val[idx];

	if (!rome[1]) {
		v = val1;
		return rome + 1;
	}

	tmp[1] = rome[1];
	for (idx = 0; idx < 13; idx++) {
		if (!strcmp(tmp, rcode[idx]))
			break;
	}
	val2 = val[idx];
	if (val1 > val2) {
		v = val1;
		return rome + 1;
	} else {
		v = val2;
		return rome + 2;
	}
}

int main(void)
{
	while (gets(rome)) {
		char *buf = rome;
		int d, last, len;
		bool valid;
		map<int, int> dup;
		valid = true;
		d = 0, last = 1000;
		len = strlen(rome);
		while (*buf) {
			int val = 0;
			int t;
			buf = to_digit(buf, val);
			if (val == 0 || last < val) {
				valid = false;
				break;
			} else {
				if (dup.count(val)) {
					t = dup[val];
					t++;
					dup[val] = t;
				} else {
					t = 1;
					dup[val] = t;
				}

				if (last == val && (val != 1000 && val != 100 && val != 10 && val != 1)) {
					valid = false;
					break;
				}

				d += val;
				last = val;
			}
			if (t > 3) {
				valid = false;
				break;
			}
		}
		if (valid == true) {
			if (strcmp(rome, toRoman(d)))
				printf("This is not a valid number\n");
			else
				printf("%d\n", d);
		} else
			printf("This is not a valid number\n");
	}
	return 0;
}