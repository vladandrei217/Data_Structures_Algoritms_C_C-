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
	void atribuire(string a,int i)
	{
		Nod* p;
		p = nodNou(a);
		p->index = i;
		p->next = curent->next;
		curent->next = p;
		curent = p;
		l++;
	}
	void adaugareOrd(string nume,int i)
	{
			curent = prim;
			while (curent->next != NULL)
			{
				if (curent->next->index > i || curent->next->next == NULL)
				{
					atribuire(nume,i);
					break;
				}
				curent = curent->next;
			}
	}
	void afisare()
	{
		curent = prim->next;
		while (curent->next != NULL)
		{
			cout << curent->n << endl;
			curent = curent->next;
		}
	}
};


int main()
{
	Lista l;
	int index;
	string nume;
	cin >> index;
	cin >> nume;
	l.adaugareOrd(nume, index);
	while (index!=0)
	{
		cin >> index;
		if (index == 0)
			break;
		cin >> nume;
		l.adaugareOrd(nume, index);
	}

	l.afisare();

	return 0;
}