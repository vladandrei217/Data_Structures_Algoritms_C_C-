#include<iostream>

using namespace std;

class Nod
{
public:
	int proces;
	Nod* next;
};

class ListaMultipli
{
public:
	int l;
	Nod* prim;
	Nod* curent;
	Nod* ultim;
public:
	ListaMultipli()
	{
		prim = new Nod();
		ultim = new Nod();
		prim->proces = 0;
		ultim->proces = 0;
		prim->next = ultim;
		ultim->next = NULL;
		curent = prim;
		l = 1;
	}
	Nod* nodNou(int a)
	{
		Nod* p;
		p = new Nod();
		p->proces = a;
		p->next = NULL;
		return p;
	}
	void adaugare(int a)
	{
		Nod* p;
		p = nodNou(a);
		p->next = curent->next;
		curent->next = p;
		curent = p;
		l++;
	}
	void afisare()
	{
		curent = prim->next;
		while (curent->next != NULL)
		{
			cout << curent->proces << endl;
			curent = curent->next;
		}
	}
};


int main()
{
	ListaMultipli m0;
	ListaMultipli m1;
	ListaMultipli m2;

	int nr;
	cin >> nr;
	while (nr)
	{
		if (nr % 3 == 0)
			m0.adaugare(nr);
		else if (nr % 3 == 1)
			m1.adaugare(nr);
		else
			m2.adaugare(nr);
		cin >> nr;
	}

	m0.afisare();
	m1.afisare();
	m2.afisare();

	return 0;
}