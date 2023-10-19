#include<iostream>

using namespace std;

class Nod
{
public:
	int proces;
	Nod* next;
};

class ListaPrioritate
{
public:
	int l;
	Nod* prim;
	Nod* curent;
	Nod* ultim;
public:
	ListaPrioritate()
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
	ListaPrioritate l1;
	ListaPrioritate l2;
	ListaPrioritate l3;
	int prioritate;
	int proces;
	
	cin >> proces;

	while (proces)
	{
		
		cin >> prioritate;
		if (prioritate == 1)
			l1.adaugare(proces);
		else if (prioritate == 2)
			l2.adaugare(proces);
		else
			l3.adaugare(proces);
		cin >> proces;
	}

	l1.afisare();
	l2.afisare();
	l3.afisare();

	return 0;
}