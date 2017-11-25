#pragma once
#include "iostream"
#include "CMyStack.h"
using namespace std;

typedef char BIN[34];//Co so 2
typedef int DEC;//Co so 10
typedef char OCT[12];//Co so 8
typedef char HEX[10];//Co so 16

class CConvert
{
private:
	BIN* _Bin;
	DEC _Dec;
	OCT* _Oct;
	HEX* _Hex;
	CMyStack _MS = CMyStack();
public:
	CConvert();
	~CConvert();
	friend void BackWardsNumber(char* str);
	char* ToNhiPhan(DEC value);
	char* ToNhiPhan(OCT value);
	char* ToNhiPhan(HEX value);
	int ToThapPhan(BIN value);
	int ToThapPhan(OCT value);
	int ToThapPhan(HEX value);
	char* ToBatPhan(BIN value);
	char* ToBatPhan(DEC value);
	char* ToBatPhan(HEX value);
	char* ToThapLucPhan(BIN value);
	char* ToThapLucPhan(DEC value);
	char* ToThapLucPhan(OCT value);
};

CConvert::CConvert()
{
}

CConvert::~CConvert()
{
}

void BackWardsNumber(char* str)
{
	int len = strlen(str);
	for (int i = 0; i < len / 2; i++)
		swap(str[i], str[len - 1 - i]);
}

char* CConvert::ToNhiPhan(DEC value)
{
	char* tmp = new char[34];
	int i = 0;
	while (value > 0)
	{
		_MS.Add(value % 2);
		value /= 2;
	}
	while (!_MS.Empty())
	{
		tmp[i] = _MS.Pop + '0';
	}
	return tmp;
}
char* CConvert::ToNhiPhan(OCT value)
{
	return "";
}
char* CConvert::ToNhiPhan(HEX value)
{
	return "";
}
int CConvert::ToThapPhan(BIN value)
{
	int Number = 0;
	int len = strlen(value);
	BackWardsNumber(value);
	for (int i = 0; i < len; i++)
	{
		Number += (value[i] - '0')*(int)pow(2, i);
	}
	return Number;
}
int CConvert::ToThapPhan(OCT value)
{
	int Number = 0;
	int len = strlen(value);
	BackWardsNumber(value);
	for (int i = 0; i < len; i++)
	{
		Number += (value[i] - '0')*(int)pow(8, i);
	}
	return Number;
}
int CConvert::ToThapPhan(HEX value)
{
	int Number = 0;
	int len = strlen(value);
	BackWardsNumber(value);
	for (int i = 0; i < len; i++)
	{
		Number += (value[i] - '0')*(int)pow(16, i);
	}
	return Number;
}
char* CConvert::ToBatPhan(BIN value)
{
	return "";
}
char* CConvert::ToBatPhan(DEC value)
{
	return "";
}
char* CConvert::ToBatPhan(HEX value)
{
	return "";
}
char* CConvert::ToThapLucPhan(BIN value)
{
	return "";
}
char* CConvert::ToThapLucPhan(DEC value)
{
	return "";
}
char* CConvert::ToThapLucPhan(OCT value)
{
	return "";
}