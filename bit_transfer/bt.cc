// 用户输入一个以bit为单位的给定长度，本程序将它转化为
// “×mb×kb×byte×bit”的表示形式。
//
// 如用户输入“×mb×kb×byte×bit”的形式，则它将被转换为“×bit”的形式。
// 用户也可自行选择需要转换的单位。


#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "hp_template.h"

const int byte_size = 8;
const int k_size = 1024;


using namespace std;

enum b_types {
	ERR = -1,
	BIT  = 0,
	BYTE,
	KB,
	MB,
	GB,
	TB,
	PB,
	EB,
	ZB,
	YB,
	byte_types,
};

class net_stream {
public:
	net_stream() {CLR(b); zero = false;};
	net_stream(const char *s) {
		CLR(b);
		zero = false;
		BigNum t(s);
		left = t;};
	~net_stream(){};
	net_stream& operator=(const char *);
	int get_input(void);
	void bit2byte(void);
	void byte2bit(void);
private:
	bool zero, inf;
	BigNum left;
	int bit;

	// +--------+-----+-------+
	// | 千字节 |  KB | 10^3  |
	// +--------+-----+-------+
	// | 兆字节 |  MB | 10^6  |
	// +--------+-----+-------+
	// | 吉字节 |  GB | 10^9  |
	// +--------+-----+-------+
	// | 太字节 |  TB | 10^12 |
	// +--------+-----+-------+
	// | 拍字节 |  PB | 10^15 |
	// +--------+-----+-------+
	// | 艾字节 |  EB | 10^18 |
	// +--------+-----+-------+
	// | 泽字节 |  ZB | 10^21 |
	// +--------+-----+-------+
	// | 尧字节 |  YB | 10^24 |
	// +--------+-----+------+
	int b[byte_types];
	const string name[byte_types] = {
		"bit",
		"Byte",
		"KB",
		"MB",
		"GB",
		"TB",
		"PB",
		"EB",
		"ZB",
		"YB",
	};
	string in;
};

net_stream& net_stream::operator=(const char *s)
{
	string tmp(s);
	in = tmp;
	return *this;
}

int net_stream::get_input(void)
{
	if (inf == true)
		cout << "Please input a value to be transfered (CTRL+D to exist): ";
	if (cin >> in) {
		BigNum tmp(in);
		if (tmp == 0)
			zero = true;
		left = tmp;
		return 1;
	} else {
		return 0;
	}
}

void net_stream::bit2byte(void)
{
	if (zero == true) {
		cout << "0xbit" << endl;
		return;
	}
	bit = left % byte_size;
	left = left / byte_size;

	for (int i = 1; i < byte_types; i++) {
		b[i] = left % k_size;
		left = left / k_size;
	}
	if (!(left == 0)) {
		left.print();
		cout << "xBB";

	}
	for (int i = byte_types - 1; i >= 0; i--) {
		if (b[i])
			cout << b[i] << 'x' << name[i];
	}
	if (bit)
		cout << bit << "xbit" << "\n";
	cout << endl;
}


inline int current_state(string &b, size_t pos)
{
	int c_state = -1;
	if (toupper(b[pos + 2]) == 'B') {
		int bb = (int)toupper(b[pos + 1]);
		switch (bb) {
			case 'Y':
				c_state = YB;
				break;
			case 'Z':
				c_state = ZB;
				break;
			case 'E':
				c_state = EB;
				break;
			case 'P':
				c_state = PB;
				break;
			case 'T':
				c_state = TB;
				break;
			case 'G':
				c_state = GB;
				break;
			case 'M':
				c_state = MB;
				break;
			case 'K':
				c_state = KB;
				break;
			default:
				break;
		}
	} else if (toupper(b[pos + 1]) == 'B') {
		if (toupper(b[pos + 2]) == 'I' &&
		    toupper(b[pos + 3]) == 'T')
			c_state = BIT;
		else if (toupper(b[pos + 2]) == 'Y' &&
				   toupper(b[pos + 3]) == 'T' &&
				   toupper(b[pos + 4]) == 'E')
			c_state = BYTE;
	}
	return c_state;
}

void net_stream::byte2bit(void)
{
	int cur_state = ERR, l_state = ERR;
	size_t pos = 0, n = 0;
	string strs = in;

	pos = strs.find('x', n);

	while (pos != strs.npos) {
		int i = 0;
		string temp = strs.substr(n, pos - n);
		BigNum num(temp);

		if (num == 0) {
			// 非法输入
			goto err;
		}
		cur_state = current_state(in, pos);
		if (cur_state == ERR || 
		    (l_state != ERR && l_state <= cur_state))
			goto err; // 错误的输入参数

		l_state = cur_state;

		if (cur_state ==  BIT) {
			left = num + left;
			i = 4;
		} else if  (cur_state ==  BYTE) {
			left = num * byte_size + left;
			i = 5;
		} else {
			for (int k = KB; k <= cur_state; k++)
				num = num * k_size;
			left = left + num * byte_size;
			i = 3;
		}
		n = pos + i;
		pos = strs.find('x', n);
	}
	if (cur_state != ERR) {
		left.print();
		cout << "bits" << endl;
		return;
	}
err:
	// Clear invalid input
	cout << "Invalid input" << endl;
	return;
}

inline void remap_io(char *file)
{
	return;
}

inline void unmap_io(void)
{

}
int main(int argc, char **argv)
{
	bool file = false, b2B = true;
	char *cvalue = NULL;
	char *filename = NULL;
	int c;
	while ((c = getopt (argc, argv, "?hf:b::B::")) != -1) {
		switch (c) {
			case 'f': // 由文件输入
				file = true;
				filename = optarg;
				break;
			case 'b':
			case 'B': // 将byte转换bit
				cvalue = optarg;
				b2B = false;
				break;
			case '?':
			case 'h': // 输出帮助信息
				return 1;
			default: // 非法参数
				cvalue = optarg;
				break;
		}
	} // 互斥的参数

	// 用户是否输入了未声明类型的参数
	// 为声明类型的参数将被视为待转换数值
	if ((optind < argc) && cvalue == NULL)
		cvalue = argv[optind];

	if (filename) { // 将文件IO重定向
		remap_io(filename);
		cvalue = NULL; // 命令行输入参数被抛弃
	}

	if (b2B == true) { // bit to xmbxkbxbytexbit
		class net_stream ns;
		if (cvalue)
			ns = cvalue;
		else {
			if (file == false) // 需要和用户在命令行交互
				cout << "Please input a value (CTRL+D to exist): ";
			ns.get_input();
		}
		do {
			if (file == false) // 需要和用户在命令行交互
				cout << "The result is: ";
			ns.bit2byte();
			if (file == false) // 需要和用户在命令行交互
				cout << "Please input a value (CTRL+D to exist): ";
		} while (ns.get_input());
	} else {
		class net_stream ns;
		if (cvalue)
			ns = cvalue;
		else {
			if (file == false) // 需要和用户在命令行交互
				cout << "Please input a value (CTRL+D to exist): ";
			ns.get_input();
		}
		do {
			if (file == false) // 需要和用户在命令行交互
				cout << "The result is: ";
			ns.byte2bit();
			if (file == false) // 需要和用户在命令行交互
				cout << "Please input a value (CTRL+D to exist): ";
		} while (ns.get_input());
	}
exit:
	if (file == true)
		unmap_io();
}
