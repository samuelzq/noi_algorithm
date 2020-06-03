#ifndef _HP_TEMPLATE_H
#define _HP_TEMPLATE_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio>
#include <cstring>

#define DLEN 4             // MAX length can not exceed 4
#define MAXN 9999          // 99999^2 = 9,999,800,001 overload for int
#define MAXSIZE 10024


#define CLR(a)      memset((a), 0, sizeof(a))
#define MAX(x, y)   ((x) > (y) ? (x) : (y))
class BigNum {
public:
	BigNum() {
		len = 1;
		CLR(a);
		negative = false;
	}
	BigNum(const int);
	BigNum(const char*);
	BigNum(const BigNum&);
	BigNum(const std::string);
	BigNum& operator=(const int&);
	BigNum& operator=(const BigNum&);
	BigNum operator+(const BigNum&) const;
	BigNum operator-(const BigNum&) const;
	BigNum operator*(const BigNum&) const;
	BigNum operator/(const int&) const;
	BigNum operator/(const BigNum& T) const;
	BigNum operator^(const int&) const;
	BigNum operator^(const BigNum&) const;
	
	int operator%(const int&) const;
	BigNum operator%(const BigNum&) const;
	bool operator==(const int&) const;
	bool operator<(const BigNum&) const;
	bool operator<(const int& t) const;
	void print() const;
protected:
	int a[MAXSIZE], len;
	bool negative;
};

BigNum::BigNum(const int b)
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

BigNum::BigNum(const char *s)
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
		while (k <= i) {
			if (s[k] >= '0' && s[k] <= '9')
				t = t * 10 + s[k++] - '0';
			else {
				CLR(a);
				len = 1;
				return;
			}
		}
		a[index++] = t;
	}
}

BigNum::BigNum(const std::string s)
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
		while (k <= i) {
			if (s[k] >= '0' && s[k] <= '9')
				t = t * 10 + s[k++] - '0';
			else {
				CLR(a);
				len = 1;
				return;
			}
		}
		a[index++] = t;
	}
}

BigNum::BigNum(const BigNum& T) : len(T.len)
{
	CLR(a);
	for (int i = 0; i < len; i++)
		a[i] = T.a[i];
}

BigNum& BigNum::operator=(const BigNum& T)
{
	CLR(a);
	len = T.len;
	for (int i = 0; i < len; i++)
		a[i] = T.a[i];
	return *this;
}

BigNum& BigNum::operator=(const int& n)
{
	BigNum t(n);
	CLR(a);
	len = t.len;
	for (int i = 0; i < len; i++)
		a[i] = t.a[i];
	return *this;
}

BigNum BigNum::operator+(const BigNum& T) const
{
	BigNum t(*this);
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

BigNum BigNum::operator-(const BigNum& T) const
{
	int big;
	bool negative;
	BigNum t1, t2;

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

BigNum BigNum::operator*(const BigNum& T) const
{
	BigNum res;
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

BigNum BigNum::operator/(const int& b) const
{
	BigNum res;
	int down = 0;
	for (int i = len - 1; i >= 0; i--) {
		res.a[i] = (a[i] + down * (MAXN + 1)) / b;
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

bool BigNum::operator==(const int &n) const
{
	BigNum b(n);
	if (b.len != len)
		return false;

	for (int i = 0; i < len; i++) {
		if (a[i] != b.a[i])
			return false;
	}
	return true;
}

BigNum BigNum::operator/(const BigNum& T) const
{
	BigNum res, q;
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

int BigNum::operator%(const int& b) const
{
	int d = 0;
	for (int i = len - 1; i >= 0; i--)
		d = (d * (MAXN + 1) % b + a[i]) % b;
	return d;
}

BigNum BigNum::operator%(const BigNum& T) const
{
	BigNum res;
	if (T == 0)
		return res;

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
		}
	}
	while (res.len > 1 && res.a[res.len - 1] == 0)
		--res.len;
	return res;
}

BigNum BigNum::operator^(const int& n) const
{
	BigNum res(1);
	int y = n;
	while (y--)
		res = res * (*this);
	return res;
}

BigNum BigNum::operator^(const BigNum& T) const
{
	BigNum res(1);
	for (int i = 0; i < T.len; i++) {
		int y = T.a[i];
		while (y--)
			res = res * (*this);
	}
	return res;
}

bool BigNum::operator<(const BigNum& T) const
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

inline bool BigNum::operator<(const int& t) const
{
	BigNum tee(t);
	return *this < tee;
}

inline void BigNum::print() const
{
	std::cout << a[len - 1];
	for (int i = len - 2; i >= 0; i--)
		std::cout << std::setfill('0') << std::setw(DLEN) << a[i];
}
#endif
