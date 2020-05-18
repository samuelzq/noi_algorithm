#ifndef _HP_TEMPLATE_H
#define _HP_TEMPLATE_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio>
#include <cstring>

#define DLEN 4             // MAX length
#define MAXN 9999          // 99999^2 = 9,999,800,001‬
#define MAXSIZE 10024


#define CLR(a)      memset((a), 0, sizeof(a))
#define MAX(x, y)   ((x) > (y) ? (x) : (y))
class Big {
public:
	Big() {
		len = 1;
		CLR(a);
		negative = false;
	}
	Big(const int);
	Big(const char*);
	Big(const Big&);
	Big(const std::string);
	Big& operator=(const int&);
	Big& operator=(const Big&);
	//由于OI中要求效率
	//此处不使用泛型函数
	//故不重载
	// istream& operator>>(istream&,  BigNum&);
	// ostream& operator<<(ostream&,  BigNum&);
	Big operator+(const Big&) const;
	Big operator-(const Big&) const;
	Big operator*(const Big&) const;
	Big operator/(const int&) const;
	Big operator/(const Big& T) const;
	Big operator^(const int&) const;
	// TODO: Big ^ Big;
	
	// TODO: Big Bitwise;
	
	int operator%(const int&) const;
	bool operator==(const int&) const;
	// TODO: Big % Big;
	bool operator<(const Big&) const;
	bool operator<(const int& t) const;
	void print() const;
protected:
	int a[MAXSIZE], len;
	bool negative;	
};

Big::Big(const int b)
{
	int c, d = b;

	len = 0;
	CLR(a);
	while (d > MAXN) {
		c = d - (d / (MAXN + 1) * (MAXN + 1));
		d = d / (MAXN + 1);
		a[len++] = c;
	}
	a[len++] = d;
}

Big::Big(const char *s)
{
	int t, k, index, l;
	CLR(a);
	l = strlen(s);
	len = l / DLEN;
	if (l % DLEN)
		len++;
	index = 0;
	for (int i = l - 1; i >= 0; i -= DLEN) {
		t = 0;
		k = (i >= DLEN - 1) ? (i - DLEN + 1) : 0;
		while (k <= i)
			t = t * 10 + s[k++] - '0';
		a[index++] = t;
	}
}

Big::Big(const std::string s)
{
	int t, k, index, l;
	CLR(a);
	l = s.length();
	len = l / DLEN;
	if (l % DLEN)
		len++;
	index = 0;
	for (int i = l - 1; i >= 0; i -= DLEN) {
		t = 0;
		k = (i >= DLEN - 1) ? (i - DLEN + 1) : 0;
		while (k <= i)
			t = t * 10 + s[k++] - '0';
		a[index++] = t;
	}
}

Big::Big(const Big& T) : len(T.len)
{
	CLR(a);
	for (int i = 0; i < len; i++)
		a[i] = T.a[i];
	// TODO: reload?
}

Big& Big::operator=(const Big& T)
{
	CLR(a);
	len = T.len;
	for (int i = 0; i < len; i++)
		a[i] = T.a[i];
	return *this;
}

Big& Big::operator=(const int& n)
{
	Big t(n);
	CLR(a);
	len = t.len;
	for (int i = 0; i < len; i++)
		a[i] = t.a[i];
	return *this;
}

Big Big::operator+(const Big& T) const
{
	Big t(*this);
	int big = (T.len > len) ? T.len : len;

	for (int i = 0; i < big; i++) {
		t.a[i] += T.a[i];
		if (t.a[i] > MAXN) {
			++t.a[i + 1];
			t.a[i] -= MAXN + 1;
		}
	}
	if (t.a[big])
		t.len = big + 1;
	else
		t.len = big;
	return t;
}

Big Big::operator-(const Big& T) const
{
	int big;
	bool negative;
	Big t1, t2;

	if (*this < T) {
		t1 = T;
		t2 = *this;
		negative = true;
	} else {
		t1 = *this;
		t2 = T;
		negative = false;
	}

	big = t1.len;
	int j = 0;
	for (int i = 0; i < big; i++) {
		if (t1.a[i] < t2.a[i]) {
			j = i + 1;
			while (t1.a[j] == 0)
				++j;
			--t1.a[j--];
			// WTF?
			while (j > i)
				t1.a[j--] += MAXN;
			t1.a[i] += MAXN + 1 - t2.a[i];
		} else
			t1.a[i] -= t2.a[i];
	}
	t1.len = big;
	while (t1.len > 1 && t1.a[t1.len - 1] == 0) {
		--t1.len;
		--big;
	}
	if (negative)
		t1.a[big - 1] = -t1.a[big - 1];
	t1.negative = negative;
	return t1;
}

Big Big::operator*(const Big& T) const
{
	Big res;
	int up;
	int te, tee;
	for (int i = 0; i < len; i++) {
		up = 0;
		for (int j = 0; j < T.len; j++) {
			te = a[i] * T.a[j] + res.a[i + j] + up;
			if (te > MAXN) {
				tee = te - te / (MAXN + 1) * (MAXN + 1);
				up = te / (MAXN + 1);
				res.a[i + j] = tee;
			} else {
				up = 0;
				res.a[i + j] = te;
			}
		}
		if (up) res.a[i + T.len] = up;
	}
	res.len = len + T.len;
	while (res.len > 1 && res.a[res.len - 1] == 0)
		--res.len;
	return res;
}

Big Big::operator/(const int& b) const
{
	Big res;
	int down = 0;
	for (int i = len - 1; i >= 0; i--) {
		res.a[i] = (a[i] + down * (MAXN + 1) / b);
		down = a[i] + down * (MAXN + 1) - res.a[i] * b;
	}
	res.len = len;
	while (res.len > 1 && res.a[res.len - 1] == 0)
		--res.len;
	return res;
}

inline bool greater_eq(int a[], const int b[], int last_dg, int len)
{
	// devidend is longer than devisor
	if (a[last_dg + len] != 0)
		return true;

	// compare each bit
	for (int i = len - 1; i >= 0; --i) {
		if (a[last_dg + i] > b[len - i - 1])
			return true;
		if (a[last_dg + i] < b[len - i - 1])
			return false;
	}
	// eq
	return true;
}

bool Big::operator==(const int &n) const
{
	Big b(n);
	if (b.len != len)
		return false;

	for (int i = 0; i < len; i++) {
		if (a[i] != b.a[i])
			return false;
	}
	return true;
}

Big Big::operator/(const Big& T) const
{
	Big res, q;
	if (T == 0)
		return q;

	res = *this;
	for (int i = len - T.len; i >= 0; --i) {
		// get the ith bit
		while (greater_eq(res.a, T.a, i, T.len)) {
			// High precision subtraction
			for (int j = 0; j < T.len; ++j) {
				res.a[i + j] -= T.a[j];
				if (res.a[i + j] < 0) {
					res.a[i + j + 1] -= 1;
					res.a[i + j] += MAXN + 1;
				}
			}
			q.a[i] += 1;
			if (q.a[i] > MAXN) {
				++q.a[i + 1];
				q.a[i] -= MAXN + 1;
			}
		}
	}
	q.len = len;
	while (q.len > 1 && q.a[q.len - 1] == 0)
		--q.len;
	return q;
}

int Big::operator%(const int& b) const
{
	int d = 0;
	for (int i = len - 1; i >= 0; i--)
		d = (d * (MAXN + 1) % b + a[i]) % b;
	return d;
}
Big Big::operator^(const int& n) const
{
	Big t(n), res(1);
	int y = n;
	while (y) {
		if (y & 1)
			res = res * t;
		t = t * t;
		y >>= 1;
	}
	return res;
}

bool Big::operator<(const Big& T) const
{
	int ln;
	if (len < T.len)
		return true;
	if (len == T.len) {
		ln = len - 1;
		while (ln >= 0 && a[ln] == T.a[ln])
			--ln;
		if (ln >= 0 && a[ln] < T.a[ln])
			return true;
		return false;
	}
	return false;
}

inline bool Big::operator<(const int& t) const
{
	Big tee(t);
	return *this < tee;
}

inline void Big::print() const
{
	std::cout << a[len - 1];
	for (int i = len - 2; i >= 0; i--)
		std::cout << std::setfill('0') << std::setw(DLEN) << a[i];
}
#endif