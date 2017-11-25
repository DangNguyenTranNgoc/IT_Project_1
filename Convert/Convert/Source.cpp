#include "iostream"
#include "CMyStack.h"
#include "CConvert.h"
using namespace std;

void main()
{
	CConvert cv;
	char a[10] = "001100111";
	int b = cv.ToThapPhan(a);
	cout << b;
	cout << endl;
	system("pause");
}