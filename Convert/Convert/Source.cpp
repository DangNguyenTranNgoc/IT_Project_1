#include "iostream"
#include "CMyStack.h"
#include "CConvert.h"
using namespace std;

void main()
{
	CConvert cv;
	char num[100], tmp[100];
	int base, tobase;
	do
	{
		system("cls");
		cout << "\nNhap so can doi(nhap -1 de thoat): ";
		cin >> num;
		strcpy_s(tmp, num);
		if (atoi(num) == -1)
			break;
		do
		{
			cout << "\nNhap co so cua so can doi: ";
			cin >> base;
		} while (base != 2 && base != 8 && base != 10 && base != 16);
		cv.Standardize(num);
		cout << "\nKet qua chuyen doi: " << endl;
		if (base == 2)
		{
			cout << "\nCo so 2: " << num;
		}
		else
		{
			cout << "\nCo so 2: " << cv.ToBinary(num, base);
			strcpy_s(num, tmp);
			cv.Standardize(num);
		}
		if (base == 8)
		{
			cout << "\nCo so 8: " << num;
		}
		else
		{
			cout << "\nCo so 8: " << cv.ToOctal(num, base);
			strcpy_s(num, tmp);
			cv.Standardize(num);
		}
		if (base == 10)
		{
			cout << "\nCo so 10: " << num;
		}
		else
		{
			cout << "\nCo so 10: " << cv.ToDecimal(num, base);
			strcpy_s(num, tmp);
			cv.Standardize(num);
		}
		if (base == 16)
		{
			cout << "\nCo so 16: " << num;
		}
		else
		{
			cout << "\nCo so 16: " << cv.ToHexa(num, base);
			strcpy_s(num, tmp);
			cv.Standardize(num);
		}
		cout << endl;
		system("pause");
	} while (1);
}