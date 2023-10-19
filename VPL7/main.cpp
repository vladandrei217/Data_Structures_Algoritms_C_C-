#include<iostream>

using namespace std;

class Lista
{
public:
	int l;
	class Nod
	{
	public:
		int n;
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
	Nod* nodNou(int a)
	{
		Nod* p;
		p = new Nod();
		p->n = a;
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
	void adaugareOrd(int a)
	{
		curent = prim;
		while (curent->next != NULL)
		{
			if (curent->next->n > a || curent->next->next == NULL)
			{
				adaugare(a);
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
			cout << curent->n << ",";
			curent = curent->next;
		}
	}
};


class ListaAfisare
{
private:
	int lungime;
	class NodLista
	{
	public:
		Lista l;
		NodLista* next;
	};
	NodLista* prim;
	NodLista* curent;
	NodLista* ultim;
public:
	ListaAfisare()
	{
		prim = new NodLista();
		ultim = new NodLista();
		prim->l;
		ultim->l;
		prim->next = ultim;
		ultim->next = NULL;
		curent = prim;
		lungime = 1;
	}
	NodLista* nodNou()
	{
		NodLista* p;
		p = new NodLista();
		p->l;
		p->next = NULL;
		return p;
	}
	void adaugareNod()
	{
		NodLista* p;
		p = nodNou();
		p->next = curent->next;
		curent->next = p;
		curent = p;
		lungime++;
	}
	void adaugare(Lista lista)
	{
		adaugareNod();
		lista.curent = lista.prim->next;
		while (lista.curent->next != NULL)
		{
			curent->l.adaugare(lista.curent->n);
			lista.curent = lista.curent->next;
		}
	}
	void afisare()
	{
		curent = prim->next;
		while (curent->next != NULL)
		{
			curent->l.afisare();
			cout << endl;
			curent = curent->next;
		}
	}
};

int main()
{
	Lista l;
	ListaAfisare la;
	int x;
	cin >> x;
	while (x)
	{
		
		l.adaugareOrd(x);
		la.adaugare(l);
		cin >> x;
	}

	la.afisare();

	return 0;
}