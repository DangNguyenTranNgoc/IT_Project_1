#include "iostream"
#include "LinkedList.h"
using namespace std;

void main()
{
	int chon, value, tmp;
	LIST list;
	Init(list);
	Import(list);
	do
	{
		system("clr");
		cout << "\n0. Thoat";
		cout << "\n1. Nhap danh sach";
		cout << "\n2. Them dau";
		cout << "\n3. Them cuoi";
		cout << "\n4. Xoa dau";
		cout << "\n5. Xoa cuoi";
		cout << "\n6. Sua phan tu";
		cout << "\n====================";
		cout << "\nBan chon ...";
		cin >> chon;
		switch (chon)
		{
		case 1:
			cout << "\nMoi ban nhap danh sach:" << endl;
			Import(list);
			cout << "\nDanh sach sau khi nhap: " << endl;
			Print(list);
			break;
		case 2:
			cout << "\nThem dau danh sach" << endl;
			cout << "\nNhap gia tri can them: " << endl;
			cin >> value;
			AddFirst(list, value);
			cout << "\nDanh sach sau khi them: " << endl;
			Print(list);
			break;
		case 3:
			cout << "\nThem cuoi danh sach";
			cout << "\nNhap gia tri can them: " << endl;
			cin >> value;
			AddLast(list, value);
			cout << "\nDanh sach sau khi them: " << endl;
			Print(list);
			break;
		case 4:
			cout << "\nXoa phan tu dau danh sach";
			DelFirst(list);
			cout << "\nDanh sach sau khi xoa: " << endl;
			Print(list);
			break;
		case 5:
			cout << "\nXoa phan tu dau danh sach";
			DelFirst(list);
			cout << "\nDanh sach sau khi xoa: " << endl;
			Print(list);
			break;
		case 6:
			cout << "\nSua phan tu";
			cout << "\nNhap gia tri phan tu can sua: ";
			cin >> value;
			cout << "\nNhap phan gia tri thay the: ";
			cin >> tmp;
			if (Replace(list, value, tmp))
			{
				cout << "\nThay the thanh cong! Danh sach sau khi sua: " << endl;
				Print(list);
			}
			else
				cout << "\nThay the khong thanh cong!";
			break;
		default:
			break;
		}
	} while (chon != 0);
	cout << endl;
	system("pause");
}