#include "iostream"
using namespace std;

#pragma once
typedef struct NODE* ptr;
struct NODE
{
	int value;
	ptr link;
};

class CMyStack
{
private:
	ptr _Head;
	int _Count;
public:
	CMyStack();
	CMyStack(ptr list);
	CMyStack(const CMyStack& ms);
	~CMyStack();
	friend ostream & operator<<(ostream &out, CMyStack& ms);
	friend istream & operator>>(istream &in, CMyStack& ms);
	CMyStack& operator=(const CMyStack& ms);
	ptr CreateNode(int value);//Tao node tra ve mot node
	void Add(int value);//Them phan tu vao stack
	bool Empty();//Kiem tra rong, tra ve true la rong
	int Pop();//Lay phan tu dau tien va xoa, tra ve -1 neu khong lay duoc
	int Top();//Lay phan tu dau tien nhung khong xoa, tra ve -1 neu khong lay duoc
	bool Free();//Giai phong stack, tra ve true neu thanh cong
	int getSize();//Tra ve so luong phan tu trong stack
};

CMyStack::CMyStack()
{
	_Head = NULL;
	_Count = 0;
}

CMyStack::CMyStack(ptr list)
{
	_Head = list;
	ptr p = list;
	int count = 0;
	while (p != NULL)
	{
		count++;
		p = p->link;
	}
	_Count = count;
}

CMyStack::CMyStack(const CMyStack& ms)
{
	this->_Head = ms._Head;
	this->_Count = ms._Count;
}

CMyStack::~CMyStack()
{
	Free();
}

ostream& operator<<(ostream& out, CMyStack& ms)
{
	if (ms._Head != NULL)
	{
		cout << "Cac phan tu trong stack: " << endl;
		ptr p = ms._Head;
		while (p != NULL)
		{
			cout << p->value << "\t";
			p = p->link;
		}
		cout << endl;
		cout << "Trong stack co " << ms._Count << " phan tu" << endl;
	}
	return out;
}

istream& operator>>(istream& in, CMyStack& ms)
{
	int count = 0, tmp;
	do
	{
		cout << "\nNhap phan tu cua stack (nhap -99 de thoat)";
		cin >> tmp;
		if (tmp == -99)
			break;
		count++;
		ms.Add(tmp);
	} while (1);
	ms._Count = count;
	return in;
}

CMyStack& CMyStack::operator=(const CMyStack& ms)
{
	this->_Head = ms._Head;
	this->_Count = ms._Count;
	return *this;
}

ptr CMyStack::CreateNode(int value)
{
	ptr p = new NODE;
	p->value = value;
	p->link = NULL;
	return p;
}

void CMyStack::Add(int value)
{
	ptr Node = CreateNode(value);
	if (_Head == NULL)
	{
		_Head = Node;
	}
	else
	{
		Node->link = _Head;
		_Head = Node;
	}
}

bool CMyStack::Empty()
{
	if (_Head == NULL)
		return true;
	return false;
}

int CMyStack::Pop()
{
	int value = -1;
	ptr p = _Head;
	if (p!=NULL)
	{
		_Head = _Head->link;
		value = p->value;
		delete(p);
	}
	return value;
}

int CMyStack::Top()
{
	if (_Head!=NULL)
	{
		return _Head->value;
	}
	return -1;
}

bool CMyStack::Free()
{
	ptr p = _Head;
	ptr before = NULL;
	if (p != NULL)
	{
		while (p != NULL)
		{
			before = p;
			p = p->link;
			delete(before);
		}
		return true;
	}
	return false;
}
int CMyStack::getSize()
{
	return _Count;
}