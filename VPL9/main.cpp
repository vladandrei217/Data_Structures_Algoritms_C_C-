#include<iostream>
#include<string>

using namespace std;

class Nod
{
public:
	string n;
	int index;
	Nod* next;
};

class Lista
{
public:
	int l;
	Nod* prim;
	Nod* curent;
	Nod* ultim;
public:
	Lista()
	{
		prim = new Nod();
		ultim = new Nod();
		prim->n = '0';
		ultim->n = '0';
		prim->next = ultim;
		ultim->next = NULL;
		curent = prim;
		l = 1;
	}
	Nod* nodNou(string a)
	{
		Nod* p;
		p = new Nod();
		p->n = a;
		p->next = NULL;
		return p;
	}
	void atribuire(string a)
	{
		Nod* p;
		p = nodNou(a);
		p->index = l;
		p->next = curent->next;
		curent->next = p;
		curent = p;
		l++;
	}
	void adaugare(string a)
	{
		atribuire(a);
	}
	void adaugareOrd(string a)
	{
			curent = prim;
			while (curent->next != NULL)
			{
				if (curent->next->n > a || curent->next->next == NULL)
				{
					atribuire(a);
					break;
				}
				curent = curent->next;
			}
	}
	void actualizareIndexCresc()
	{
		int i = 1;
		curent = prim->next;
		while (curent->next != NULL)
		{
			curent->index = i;
			i++;
			curent = curent->next;
		}
	}
	Lista ordonare()
	{
		Lista l;
		curent = prim->next;
		while (curent->next != NULL)
		{
			l.adaugareOrd(curent->n);
			curent = curent->next;
		}
		l.actualizareIndexCresc();
		return l;
	}
	void afisare()
	{
		curent = prim->next;
		while (curent->next != NULL)
		{
			cout <<curent->index<<endl;
			curent = curent->next;
		}
	}
};

void atribuireIndex(Lista l1, Lista l2)
{
	l1.curent = l1.prim->next;
	while (l1.curent->next != NULL)
	{
		l2.curent = l2.prim->next;
		while (l2.curent->next != NULL)
		{
			if (l1.curent->n == l2.curent->n)
			{
				l1.curent->index = l2.curent->index;
				break;
			}
			l2.curent = l2.curent->next;
		}
		l1.curent = l1.curent->next;
	}
}


int main()
{
	Lista l;
	string nume;
	cin >> nume;
	while (nume != "stop")
	{
		l.adaugare(nume);
		cin >> nume;
	}
	atribuireIndex(l, l.ordonare());
	l.afisare();
	return 0;
}