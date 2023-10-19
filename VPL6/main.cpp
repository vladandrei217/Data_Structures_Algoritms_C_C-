#include<iostream>

using namespace std;

class Nod
{
public:
	char litera;
	Nod* next;
};

class Coduri
{
public:
	int l;
	int temp = 0;
	int const A = 0;
	int const E = 11;
	int const I = 101;
	int const O = 1000;
	int const U = 10010;
	Nod* prim;
	Nod* curent;
	Nod* ultim;
public:
	Coduri()
	{
		prim = new Nod();
		ultim = new Nod();
		prim->litera = 0;
		ultim->litera = 0;
		prim->next = ultim;
		ultim->next = NULL;
		curent = prim;
		l = 1;
	}
	Nod* nodNou(int a)
	{
		Nod* p;
		p = new Nod();
		p->litera = a;
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
		if (a == 1 && temp == 0)
			temp = 1;
		else
			temp = temp * 10 + a;

		if (temp == A)
		{
			atribuire('A');
		}
		else if (temp == E)
		{
			atribuire('E');
			temp = 0;
		}
		else if (temp == I)
		{
			atribuire('I');
			temp = 0;
		}
		else if (temp == O)
		{
			atribuire('O');
			temp = 0;
		}
		else if (temp == U)
		{
			atribuire('U');
			temp = 0;
		}
	}
	void afisare()
	{
		curent = prim->next;
		while (curent->next != NULL)
		{
			cout << curent->litera << endl;
			curent = curent->next;
		}
	}
};


int main()
{
	Coduri c;
	int nr;
	cin >> nr;
	while (nr != 2)
	{
		c.adaugare(nr);
		cin >> nr;
	}

	c.afisare();


	return 0;
}