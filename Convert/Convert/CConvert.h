#pragma once
#include "iostream"
#include "CMyStack.h"
#include "regex"
#include "string"
using namespace std;

class CConvert
{
private:
	int _Decimal;
	char* _Bin;
	char* _Oct;
	char* _Hex;
	CMyStack _MS = CMyStack();
public:
	CConvert();
	~CConvert();
	friend void BackWardsNumber(char* str);
	int ToInt(char value);//chuyen chu thanh so
	char ToChar(int value);//chuyen so thanh chu
	int getBaseName(char* value);//tra ve co so cua chuoi, lan luot la 2,8,10 va 16(dung regex)
	int ToDecimal(char* value, int base);//chuyen doi ve co so 10
	char* ToBinary(char* value, int base);//chuyen doi ve co so 2
	char* ToOctal(char* value, int base);//chuyen doi ve co so 8
	char* ToHexa(char* value, int base);//chuyen doi ve co so 16
	void Standardize(char* value);//chuan hoa chuoi
	int StringToInt(char* value);
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

int CConvert::ToInt(char value)
{
	return value - '0';
}

char CConvert::ToChar(int value)
{
	return value + '0';
}

int CConvert::getBaseName(char* value)
{
	regex BinPattern("(1|0)\\d{1,34)}");
	regex OctPattern("([0-7])\\d{1,12}");
	regex DecPattern("([0-9])\\d{1,12}");
	regex HexPattern("([A-F0-9])\\d{1,9}");
	if (regex_match(value,BinPattern))
		return 2;
	if (regex_match(value, OctPattern))
		return 8;
	if (regex_match(value, DecPattern))
		return 10;
	if (regex_match(value, HexPattern))
		return 16;
	return 0;
}

int CConvert::ToDecimal(char* value, int base)
{
	_MS.Free();
	_MS.Init();
	int Dec = 0;
	int len = strlen(value);
	BackWardsNumber(value);
	if (base != 16)
	{
		for (int i = 0; i < len; i++)
			_MS.Add(ToInt(value[i])*pow(base, i));
	}
	else
	{
		for(int i=0;i<len;i++)
			if (ToInt(value[i]) >= 0 && ToInt(value[i]) <= 9)
			{
				_MS.Add(ToInt(value[i])*pow(16, i));
			}
			else
			{
				int tmp = 0;
				switch (value[i])
				{
				case 'A':
					tmp = 10;
					break;
				case 'B':
					tmp = 11;
					break;
				case 'C':
					tmp = 12;
					break;
				case 'D':
					tmp = 13;
					break;
				case 'E':
					tmp = 14;
					break;
				default:
					tmp = 15;
					break;
				}
				_MS.Add(tmp*pow(16,i));
			}
	}
	Dec = _MS.getSum();
	_Decimal = Dec;
	return Dec;
}

char* CConvert::ToBinary(char* value, int base)
{
	_MS.Free();
	_MS.Init();
	if (base == 10)
	{
		int dec = atoi(value);
		while (dec > 0)
		{
			_MS.Add(dec % 2);
			dec /= 2;
		}
		int len = _MS.getSize();
		char* bin = new char[len + 1];
		for (int i = 0; i < len; i++)
		{
			bin[i] = ToChar(_MS.Pop());
		}
		bin[len] = '\0';
		return bin;
	}
	else
	{
		int dec = ToDecimal(value, base);
		while (dec > 0)
		{
			_MS.Add(dec % 2);
			dec /= 2;
		}
		int len = _MS.getSize();
		char* bin = new char[len + 1];
		for (int i = 0; i < len; i++)
		{
			bin[i] = ToChar(_MS.Pop());
		}
		bin[len] = '\0';
		return bin;
	}
}

char* CConvert::ToOctal(char* value, int base)
{
	_MS.Free();
	_MS.Init();
	if (base == 10)
	{
		int dec = atoi(value);
		while (dec > 0)
		{
			_MS.Add(dec % 8);
			dec /= 8;
		}
		int len = _MS.getSize();
		char* bin = new char[len + 1];
		for (int i = 0; i < len; i++)
		{
			bin[i] = ToChar(_MS.Pop());
		}
		bin[len] = '\0';
		return bin;
	}
	else
	{
		int dec = ToDecimal(value, base);
		while (dec > 0)
		{
			_MS.Add((int)dec % 8);
			dec /= 8;
		}
		int len = _MS.getSize();
		char* bin = new char[len];
		for (int i = 0; i < len; i++)
		{
			bin[i] = ToChar(_MS.Pop());
		}
		bin[len] = '\0';
		return bin;
	}
}

char* CConvert::ToHexa(char* value, int base)
{
	_MS.Free();
	_MS.Init();
	if (base == 10)
	{
		int dec = atoi(value);
		while (dec > 0)
		{
			_MS.Add(dec % 16);
			dec /= 16;
		}
		int len = _MS.getSize();
		char* bin = new char[len + 1];
		for (int i = 0; i < len; i++)
		{
			int tmp = ToChar(_MS.Pop());
			if (tmp > 9)
			{
				switch (tmp)
				{
				case 10:
					bin[i] = 'A';
					break;
				case 11:
					bin[i] = 'B';
					break;
				case 12:
					bin[i] = 'C';
					break;
				case 13:
					bin[i] = 'D';
					break;
				case 14:
					bin[i] = 'E';
					break;
				default:
					bin[i] = 'F';
					break;
				}
			}
			else
			{
				bin[i] = ToChar(tmp);
			}
		}
		bin[len] = '\0';
		return bin;
	}
	else
	{
		int dec = ToDecimal(value, base);
		while (dec > 0)
		{
			_MS.Add(dec % 16);
			dec /= 16;
		}
		int len = _MS.getSize();
		char* bin = new char[len];
		for (int i = 0; i < len; i++)
		{
			int tmp = ToChar(_MS.Pop());
			if (tmp > 9)
			{
				switch (tmp)
				{
				case 10:
					bin[i] = 'A';
					break;
				case 11:
					bin[i] = 'B';
					break;
				case 12:
					bin[i] = 'C';
					break;
				case 13:
					bin[i] = 'D';
					break;
				case 14:
					bin[i] = 'E';
					break;
				default:
					bin[i] = 'F';
					break;
				}
			}
			else
			{
				bin[i] = ToChar(tmp);
			}
		}
		bin[len] = '\0';
		return bin;
	}
}

void CConvert::Standardize(char* value)
{
	int len = strlen(value);
	int i = 0;
	while (value[i] != '\0')
	{
		if (value[i] == ' ')
		{
			for (int j = i; j < len; j++)
			{
				value[j] = value[j + 1];
			}
			value[len - 1] = '\0';
			len--;
		}
		if (value[i] >= 97 && value[i] <= 122)
		{
			value[i] -= 32;
		}
		i++;
	}
}

int CConvert::StringToInt(char* value)
{
	int sum = 0;
	int i = 0;
	while (value[i] != '\0')
	{
		sum += ToInt(value[i])*pow(10, i);
		i++;
	}
	return sum;
}