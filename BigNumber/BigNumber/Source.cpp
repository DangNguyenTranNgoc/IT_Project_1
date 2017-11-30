#include "iostream"
#include "CBigNumber.h"
using namespace std;

void main()
{
	int chon;
	CBigNumber a = CBigNumber();
	CBigNumber b = CBigNumber();
	cout << "\nMoi nhap so:" << endl;
	cin >> a;
	do
	{
		system("cls");
		cout << a;
		cout << "\n==============";
		cout << "\n==== Menu ====";
		cout << "\n==============";
		cout << "\n= 0. Thoat   =";
		cout << "\n= 1. Cong    =";
		cout << "\n= 2. Tru     =";
		cout << "\n= 3. Nhan    =";
		cout << "\n= 4. Chia    =";
		cout << "\n==============";
		cout << "\nban chon ...";
		cin >> chon;
		switch (chon)
		{
		case 0:
			cout << "Hen gap lai!" << endl;
			system("pause");
			break;
		case 1:
			cout << "Nhap so can cong vao:" << endl;
			cin >> b;
			cout << a + b;
			system("pause");
			break;
		case 2:
			cout << "Nhap so can tru vao:" << endl;
			cin >> b;
			cout << a + b;
			system("pause");
			break;
		case 3:
			cout << "Nhap so can nhan vao:" << endl;
			cin >> b;
			cout << a + b;
			system("pause");
			break;
		case 4:
			cout << "Nhap so can chia vao:" << endl;
			cin >> b;
			cout << a + b;
			system("pause");
			break;
		default:
			cout << "\nVui long chon lai!";
			system("pause");
			break;
		}
	} while (chon != 0);
}