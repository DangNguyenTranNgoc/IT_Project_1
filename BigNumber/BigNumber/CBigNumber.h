#include "iostream"
#include "CMyStack.h"
#include "string"
#pragma once
class CBigNumber
{
private:
	CMyStack _Data = CMyStack();//Chua chua so
	int _Len;
	bool _Sign;//Dau cua so, true la duong
public:
	CBigNumber();
	~CBigNumber();
	CBigNumber(CMyStack ms, bool sign, int len)
	{
		this->_Data = ms;
		this->_Sign = sign;
		this->_Len = len;
	}
	CBigNumber(const CBigNumber& bignum)
	{
		this->_Data = bignum._Data;
		this->_Len = bignum._Len;
		this->_Sign = bignum._Sign;
	}
	CBigNumber& operator=(const CBigNumber& bignum)
	{
		this->_Data = bignum._Data;
		this->_Len = bignum._Len;
		this->_Sign = bignum._Sign;
		return *this;
	}
	friend ostream & operator<<(ostream &out, CBigNumber &x);
	friend istream & operator>>(istream &in, CBigNumber &x);
	CBigNumber operator+(CBigNumber bignum);
	CBigNumber operator-(CBigNumber bignum);
	CBigNumber operator*(CBigNumber bignum);
	CBigNumber operator/(CBigNumber bignum);
	CBigNumber operator+=(CBigNumber bignum);
	int ToInt(char value);
	char ToChar(int value);
	void Init();
};

CBigNumber::CBigNumber()
{
	Init();
}

CBigNumber::~CBigNumber()
{
}

ostream & operator<<(ostream &out, CBigNumber &x)
{
	CMyStack tmp = x._Data;
	if (!x._Sign)
		out << "-";
	out << tmp;
	return out;
}

istream & operator>>(istream &in, CBigNumber &x)
{
	char tmp[100];
	int i = 0;
	cout << "\nNhap so: ";
	gets_s(tmp);
	if (tmp[i] == '-')
	{
		x._Sign = false;
	}
	else if (tmp[i] == '+')
	{
		x._Sign = true;
	}
	else
	{
		x._Sign = true;
		x._Data.Add(x.ToInt(tmp[i++]));
	}
	while (tmp[i] != '\0')
	{
		x._Data.Add(x.ToInt(tmp[i++]));
	}
	x._Len = i;
	return in;
}

CBigNumber CBigNumber::operator+(CBigNumber bignum)
{
	int MaxLen, MinLen, Carry, tmp;
	bool flag = true;
	CBigNumber backup = *this;
	CBigNumber result = CBigNumber();
	if (this->_Sign&&bignum._Sign)
	{
		result._Sign = true;
	}
	if (!this->_Sign && !bignum._Sign)
	{
		result._Sign = false;
	}
	if (this->_Len > bignum._Len)
	{
		MaxLen = this->_Len;
		MinLen = bignum._Len;
	}
	else
	{
		MaxLen = bignum._Len;
		MinLen = this->_Len;
		flag = false;
	}
	Carry = 0;
	for (int i = 0; i < MinLen; i++)
	{
		tmp = this->_Data.Pop() + bignum._Data.Pop() + Carry;
		Carry = tmp / 10;
		result._Data.Add(tmp % 10);
		result._Len++;
	}
	if (flag)
	{
		for (int i = MinLen; i < MaxLen; i++)
		{
			tmp = this->_Data.Pop() + 0 + Carry;
			Carry = tmp / 10;
			result._Data.Add(tmp % 10);
			result._Len++;
		}
	}
	else
	{
		for (int i = MinLen; i < MaxLen; i++)
		{
			tmp = bignum._Data.Pop() + 0 + Carry;
			Carry = tmp / 10;
			result._Data.Add(tmp % 10);
			result._Len++;
		}
	}
	*this = backup;
	return result;
}
CBigNumber CBigNumber::operator-(CBigNumber bignum)
{
	int MaxLen, MinLen, Carry, tmp;
	bool flag = true;
	CBigNumber backup = *this;
	CBigNumber result = CBigNumber();
	if (this->_Sign&&bignum._Sign)
	{
		result._Sign = true;
	}
	if (!this->_Sign && !bignum._Sign)
	{
		result._Sign = false;
	}
	if (this->_Len >= bignum._Len)
	{
		MaxLen = this->_Len;
		MinLen = bignum._Len;
	}
	else
	{
		MaxLen = bignum._Len;
		MinLen = this->_Len;
		flag = false;
	}
	Carry = 0;
	if (flag)
	{
		for (int i = 0; i < MinLen; i++)
		{
			tmp = 10 + this->_Data.Pop() - bignum._Data.Pop() - Carry;
			Carry = 1 - tmp / 10;
			result._Data.Add(tmp % 10);
		}
		for (int i = MinLen; i < MaxLen; i++)
		{
			tmp = 10 + this->_Data.Pop() - 0 - Carry;
			Carry = 1 - tmp / 10;
			result._Data.Add(tmp % 10);
		}
	}
	else
	{
		for (int i = 0; i < MinLen; i++)
		{
			tmp = 10 + bignum._Data.Pop() - this->_Data.Pop() - Carry;
			Carry = 1 - tmp / 10;
			result._Data.Add(tmp % 10);
		}
		for (int i = MinLen; i < MaxLen; i++)
		{
			tmp = 10 + bignum._Data.Pop() - 0 - Carry;
			Carry = 1 - tmp / 10;
			result._Data.Add(tmp % 10);
		}
	}
	*this = backup;
	return result;
}

CBigNumber CBigNumber::operator*(CBigNumber bignum)
{
	int ALen, BLen, Carry, tmp, num;
	bool flag = true;
	CBigNumber backup = *this;
	CBigNumber result = CBigNumber();
	CBigNumber remember = CBigNumber();
	ALen = this->_Len;
	BLen = bignum._Len;
	Carry = 0;
	for (int i = 0; i < BLen; i++)
	{
		remember.Init();
		num = bignum._Data.Pop();
		if (i != 0)
		{
			for (int j = 0; j < i; j++)
			{
				remember._Data.Add(0);
				remember._Len++;
			}
		}
		for (int j = 0; j < ALen; j++)
		{
			cout << remember._Data.Top() << endl;
			tmp = abs(num*this->_Data.Pop() + Carry);
			Carry = tmp / 10;
			remember._Data.Add(tmp % 10);
			remember._Len++;
		}
		if (Carry != 0)
		{
			remember._Data.Add(Carry);
			remember._Len++;
		}
		if (i==0)
		{
			result = remember;
		}
		else
		{
			result += remember;
		}
	}
	*this = backup;
	return result;
}
CBigNumber CBigNumber::operator/(CBigNumber bignum)
{
	int ALen, BLen, Carry, tmp, num, deviation;
	CBigNumber backup = *this;
	CBigNumber result = CBigNumber();
	CBigNumber Astorage = CBigNumber();
	CBigNumber Bstorage = CBigNumber();
	ALen = this->_Len;
	BLen = bignum._Len;
	if (bignum._Data.getSum() == 0 || this->_Data.getSum() == 0 || BLen > ALen)
	{
		result._Data.Add(0);
		return result;
	}
	deviation = ALen - BLen;
	for (int i = 0; i < ALen; i++)
	{
		Astorage._Data.Add(this->_Data.Pop());
	}
	for (int i = 0; i < BLen; i++)
	{
		Bstorage._Data.Add(bignum._Data.Pop());
	}
	return result;
}

CBigNumber CBigNumber::operator+=(CBigNumber bignum)
{
	int MaxLen, MinLen, Carry, tmp;
	bool flag = true;
	CBigNumber backup = *this;
	CBigNumber result = CBigNumber();
	if (this->_Sign&&bignum._Sign)
	{
		result._Sign = true;
	}
	if (!this->_Sign && !bignum._Sign)
	{
		result._Sign = false;
	}
	if (this->_Len > bignum._Len)
	{
		MaxLen = this->_Len;
		MinLen = bignum._Len;
	}
	else
	{
		MaxLen = bignum._Len;
		MinLen = this->_Len;
		flag = false;
	}
	Carry = 0;
	for (int i = 0; i < MinLen; i++)
	{
		tmp = this->_Data.Pop() + bignum._Data.Pop() + Carry;
		Carry = tmp / 10;
		result._Data.Add(tmp % 10);
		result._Len++;
	}
	if (flag)
	{
		for (int i = MinLen; i < MaxLen; i++)
		{
			tmp = this->_Data.Pop() + 0 + Carry;
			Carry = tmp / 10;
			result._Data.Add(tmp % 10);
			result._Len++;
		}
	}
	else
	{
		for (int i = MinLen; i < MaxLen; i++)
		{
			tmp = bignum._Data.Pop() + 0 + Carry;
			Carry = tmp / 10;
			result._Data.Add(tmp % 10);
			result._Len++;
		}
	}
	*this = result;
	return *this;
}

int CBigNumber::ToInt(char value)
{
	return value - '0';
}

char CBigNumber::ToChar(int value)
{
	return value + '0';
}

void CBigNumber::Init()
{
	_Data.Init();
	_Len = 0;
	_Sign = true;
}