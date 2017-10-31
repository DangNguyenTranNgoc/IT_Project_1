#include "iostream" #include "LinkedList.h" using namespace std;  void main() { 	int chon, value, tmp; 	ptr node; 	LIST list; 	Init(list); 	Import(list); 	do 	{ 		system("CLS"); 		cout << "\n0. Thoat"; 		cout << "\n1. Nhap danh sach"; 		cout << "\n2. Them dau"; 		cout << "\n3. Them cuoi"; 		cout << "\n4. Them sau phan tu"; 		cout << "\n5. Xoa dau"; 		cout << "\n6. Xoa cuoi"; 		cout << "\n7. Xoa sau phan tu"; 		cout << "\n8. Sua phan tu"; 		cout << "\n9. Tim phan tu"; 		cout << "\n10. Sap xep danh sach"; 		cout << "\n===================="; 		cout << "\nBan chon ..."; 		cin >> chon; 		switch (chon) 		{ 		case 1: 			cout << "\nMoi ban nhap danh sach:" << endl; 			Import(list); 			cout << "\nDanh sach sau khi nhap: " << endl; 			Print(list); 			cout << endl; 			system("pause"); 			break; 		case 2: 			cout << "\nThem dau danh sach" << endl; 			cout << "\nNhap gia tri can them: " << endl; 			cin >> value; 			AddFirst(list, value); 			cout << "\nDanh sach sau khi them: " << endl; 			Print(list); 			cout << endl; 			system("pause"); 			break; 		case 3: 			cout << "\nThem cuoi danh sach"; 			cout << "\nNhap gia tri can them: " << endl; 			cin >> value; 			AddLast(list, value); 			cout << "\nDanh sach sau khi them: " << endl; 			Print(list); 			cout << endl; 			system("pause"); 			break; 		case 4: 			cout << "\nNhap vi tri can them "; 			cin >> tmp; 			cout << "\nNhap gia tri can them "; 			cin >> value; 			node = Search(list, tmp); 			if (node == NULL) 				cout << "\nKhong tim thay phan tu!"; 			else 				AddAfter(list, node, value); 			cout << "\nThem thanh cong! Danh sach sau khi them: " << endl; 			Print(list); 			cout << endl; 			system("pause"); 			break; 		case 5: 			cout << "\nXoa phan tu dau danh sach"; 			DelFirst(list); 			cout << "\nDanh sach sau khi xoa: " << endl; 			Print(list); 			cout << endl; 			system("pause"); 			break; 		case 6: 			cout << "\nXoa phan tu dau danh sach"; 			DelLast(list); 			cout << "\nDanh sach sau khi xoa: " << endl; 			Print(list); 			cout << endl; 			system("pause"); 			break; 		case 7: 			cout << "\nNhap phan tu "; 			cin >> tmp; 			node = Search(list, tmp); 			if (node == NULL) 				cout << "\nKhong tim thay!"; 			else 				DelAfter(list, node); 			cout << "\nDanh sach su khi xoa:" << endl; 			Print(list); 			cout << endl; 			system("pause"); 			break; 		case 8: 			cout << "\nSua phan tu"; 			cout << "\nNhap gia tri phan tu can sua: "; 			cin >> value; 			cout << "\nNhap phan gia tri thay the: "; 			cin >> tmp; 			if (Replace(list, value, tmp)) 			{ 				cout << "\nThay the thanh cong! Danh sach sau khi sua: " << endl; 				Print(list); 			} 			else 				cout << "\nThay the khong thanh cong!"; 			cout << endl; 			system("pause"); 			break; 		case 9: 			cout << "\nNhap gia tri can tim "; 			cin >> tmp; 			if (Search(list,tmp) == NULL) 				cout << "\nKhong tim thay!"; 			else 				cout << Search(list, tmp)->value; 			cout << endl; 			system("pause"); 			break; 		case 10: 			cout << "\nDanh sach truoc khi sap xep: " << endl; 			Print(list); 			cout << "\nDanh sach sau khi sap xep: " << endl; 			SapXep(list); 			Print(list); 			cout << endl; 			system("pause"); 			break; 		default: 			cout << "\nThoat chuong trinh" << endl; 			break; 		} 	} while (chon != 0); 	cout << endl; 	system("pause"); }