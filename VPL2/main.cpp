#include <iostream>
#include <string>

using namespace std;

class Lista
{
public:
	int l;
	class Nod
	{
	public:
		string n;
		Nod* next;
	};
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
		p->next = curent->next;
		curent->next = p;
		curent = p;
		l++;
	}
	void adaugareOrd(string nume)
	{
		curent = prim;
		while (curent->next != NULL)
		{
			if (curent->next->n > nume || curent->next->next == NULL)
			{
				if (curent->n == nume)
				{
					break;
				}
				else
				{
					atribuire(nume);
					break;
				}
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

class ListaCat
{
private:
	int lungime;
	class NodLista
	{
	public:
		string categorie;
		Lista l;
		NodLista* next;
	};
	NodLista* prim;
	NodLista* curent;
	NodLista* ultim;
public:
	ListaCat()
	{
		prim = new NodLista();
		ultim = new NodLista();
		prim->categorie = '0';
		prim->l;
		ultim->categorie = '0';
		ultim->l;
		prim->next = ultim;
		ultim->next = NULL;
		curent = prim;
		lungime = 1;
	}
	NodLista* nodNou(string a, string b)
	{
		NodLista* p;
		p = new NodLista();
		p->categorie = a;
		p->l;
		p->l.adaugareOrd(b);
		p->next = NULL;
		return p;
	}
	void atribuire(string a, string b)
	{
		NodLista* p;
		p = nodNou(a, b);
		p->next = curent->next;
		curent->next = p;
		curent = p;
		lungime++;
	}
	void adaugareOrd(string a, string b)
	{
		curent = prim;
		while (curent->next != NULL)
		{
			if (curent->next->categorie > a || curent->next->next == NULL)
			{
				if (curent->categorie == a)
				{
					curent->l.adaugareOrd(b);
					break;
				}
				else
				{
					atribuire(a, b);
					break;
				}
			}
			curent = curent->next;
		}
	}
	void afisare()
	{
		curent = prim->next;
		while (curent->next != NULL)
		{
			cout << curent->categorie << endl;
			curent->l.afisare();
			curent = curent->next;
		}
	}
};


int main()
{
	ListaCat l;
	string categorie;
	string nume;
	cin >> categorie;
	cin >> nume;
	l.adaugareOrd(categorie, nume);
	while (categorie != "0")
	{
		cin >> categorie;
		if (categorie == "0")
			break;
		cin >> nume;
		l.adaugareOrd(categorie, nume);
	}

	l.afisare();
	return 0;
}
