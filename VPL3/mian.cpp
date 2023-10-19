#include<iostream>

using namespace std;

class Dlist
{
private:
	class Dnod
	{
		public:
		int n;
		Dnod* prev;
		Dnod* next;
	};
	const int N = 3;
	int nrElem;
	Dnod* prim;
	Dnod* curent;
	Dnod* ultim;
public:
	Dlist()
	{
		prim = new Dnod();
		ultim = new Dnod();
		prim->n = 0;
		ultim->n = 0;
		prim->prev = NULL;
		prim->next = ultim;
		ultim->next = NULL;
		ultim->prev = prim;
		curent = prim;
		nrElem = 0;
	}
	Dnod* nodNou(int a)
	{
		Dnod* p;
		p = new Dnod();
		p->n = a;
		p->prev = curent;
		p->next = curent->next;
		curent->next = p;
		ultim->prev = p;
		curent = p;
		nrElem++;
		return p;
	}
	int adaugare(int a)
	{
		if (nrElem == 3)
		{
			return 0;
		}
		else
		{
			Dnod* p;
			p = nodNou(a);
			return 1;
		}

	}
	void nafisare()
	{
		curent = prim->next;
		while (curent->next != NULL)
		{
			cout << curent->n << endl;
			curent = curent->next;
		}
	}
	void rafisare()
	{
		curent = ultim->prev;
		while (curent->prev != NULL)
		{
			cout << curent->n << endl;
			curent = curent->prev;
		}
	}
	void afisare()
	{
		if (nrElem == 3)
			rafisare();
		else
			nafisare();
	}

};

class Lista
{
public:
	class Nod
	{
	public:
		Dlist grup;
		Nod* next;
	};
	int l;
	Nod* prim;
	Nod* curent;
	Nod* ultim;
public:
	Lista()
	{
		prim = new Nod();
		ultim = new Nod();
		prim->grup;
		ultim->grup;
		prim->next = ultim;
		ultim->next = NULL;
		Nod* p;
		p = new Nod();
		p->grup;
		p->next = prim->next;
		prim->next = p;
		curent = p;
		l = 1;
	}
	Nod* nodNou(int a)
	{
		Nod* p;
		p = new Nod();
		p->grup;
		p->grup.adaugare(a);
		p->next = NULL;
		return p;
	}
	void atribuire(int a)
	{
		Nod* p;
		p = nodNou(a);
		p->next = curent->next;
		curent->next = p;
		curent = p;
		l++;
	}
	void adaugare(int a)
	{
			if (curent->grup.adaugare(a))
			{

			}
			else
				atribuire(a);
	}
	void afisare()
	{
		curent = prim->next;
		while (curent->next != NULL)
		{
			curent->grup.afisare();
			curent = curent->next;
		}
	}

};

int main()
{
	Lista l;
	int n;
	cin >> n;
	while (n)
	{
		l.adaugare(n);
		cin >> n;
	}

	l.afisare();

	return 0;
}