#include "iostream"
using namespace std;

typedef struct NODE* ptr;
struct NODE
{
	ptr next;
	int value;
};
struct LIST
{
	ptr First;
	ptr Last;
	int count;
};

//Khởi tạo
void Init(LIST &L);
//Tạo node mới
ptr CreateNode(int value);
//Thêm node đầu list
void AddFirst(LIST &L, int value);
//Thêm node cuối list
void AddLast(LIST &L, int value);
//Thêm node sau một phần tử
void AddAfter(LIST &L, ptr node, int value);
//Xóa node đầu list
void DelFirst(LIST &L);
//Xóa node cuối list
void DelLast(LIST &L);
//Xóa node sau một phần tử
void DelAfter(LIST &L, ptr Node);
//Tìm node theo giá trị, trả về node đầu tiên tìm thấy
ptr Search(LIST &L, int value);
//Nhập list
void Import(LIST &L);
//Xuất list
void Print(LIST &L);
//Xóa list
void Free(LIST &L);
//Sửa phần tử
bool Replace(LIST &L, int ValueFind, int ValueReplace);