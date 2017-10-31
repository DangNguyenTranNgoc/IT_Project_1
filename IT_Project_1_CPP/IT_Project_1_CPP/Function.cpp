#include "iostream"
#include "LinkedList.h"
using namespace std;


void Init(LIST &L)
{
	L.Last = L.First = NULL;
	L.count = 0;
}

ptr CreateNode(int value)
{
	NODE* p = new NODE;
	p->value = value;
	p->next = NULL;
	return p;
}

void AddFirst(LIST &L, int value)
{
	ptr newnode = CreateNode(value);
	if (L.First == NULL)
	{
		L.First = L.Last = newnode;
		L.Last->next = L.First;
	}
	else
	{
		newnode->next = L.First;
		L.First = newnode;
	}
	L.count++;
}

void AddLast(LIST &L, int value)
{
	ptr newnode = CreateNode(value);
	if (L.First == NULL)
	{
		L.First = L.Last = newnode;
		L.Last->next = L.First;
	}
	else
	{
		L.Last->next = newnode;
		L.Last = newnode;
		L.Last->next = L.First;
	}
	L.count++;
}

void AddAfter(LIST &L, ptr node, int value)
{
	ptr newnode = CreateNode(value);
	if (L.First == NULL)
	{
		L.First = L.Last = newnode;
		L.Last->next = L.First;
	}
	else if (node == L.Last)
	{
		node->next = newnode;
		L.Last = newnode;
	}
	else
	{
		newnode->next = node->next;
		node->next = newnode;
	}
	L.count++;
}

void DelFirst(LIST &L)
{
	ptr p = L.First;
	if (p != NULL)
	{
		if (L.First == L.Last)
			L.First = L.Last = NULL;
		else
		{
			L.First = p->next;
			if (L.First == L.Last)
				L.First = L.Last = NULL;
		}
		delete(p);
	}
	L.count--;
}

void DelLast(LIST &L)
{
	ptr p = L.First;
	if (p != NULL)
	{
		if (L.First == L.Last)
			L.First = L.Last = NULL;
		else
		{
			while (p->next != L.Last)
				p = p->next;
			L.Last = p;
			
			p = p->next;
			L.Last->next = L.First;
		}
		delete(p);
	}
	L.count--;
}

void DelAfter(LIST &L, ptr Node)
{
	ptr p;
	if (Node == L.First)
		DelFirst(L);
	else if (Node == L.Last)
		DelLast(L);
	else
	{
		p = Node->next;
		Node->next = p->next;
		delete(p);
		L.count--;
	}
}

ptr Search(LIST &L, int value)
{
	ptr p = L.First;
	if (p != NULL)
	{
		while (p != L.Last)
		{
			if (p->value == value)
				return p;
			p = p->next;
		}
	}
	return p;
}

void Import(LIST &L)
{
	int n;
	do
	{
		cout << "\nNhap gia tri phan tu (nhap -99 de thoat): ";
		cin >> n;
		if (n == -99)
			break;
		AddLast(L, n);
	} while (1);
}

void Print(LIST &L)
{
	ptr p = L.First;
	if (p != NULL)
	{
		while (p != L.Last)
		{
			cout << p->value << "\t";
			p = p->next;
		}
		cout << L.Last->value;
	}
}

void Free(LIST &L)
{
	if (L.First != NULL)
	{
		ptr p = L.First;
		ptr node;
		while (p != L.Last)
		{
			node = p;
			p = p->next;
			delete(node);
		}
		L.First = NULL;
	}
}
bool Replace(LIST &L, int ValueFind, int ValueReplace)
{
	ptr p = Search(L, ValueFind);
	if (p == NULL)
		return false;
	p->value = ValueReplace;
	return true;
}
void SapXep(LIST &L)
{
	ptr i, j;
	if (L.First != NULL)
	{
		for (i = L.First; i->next != L.First; i = i->next)
			for (j = i->next; j->next != L.First; j = j->next)
				if (i->value > j->value)
					swap(i->value, j->value);
	}
}