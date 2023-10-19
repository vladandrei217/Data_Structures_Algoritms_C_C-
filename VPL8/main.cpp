#include<iostream>

using namespace std;

class Nod
{
public:
	int n;
	Nod* next;
};

class Lista
{
private:
	int l;
	Nod* prim;
	Nod* curent;
	Nod* ultim;
public:
	Lista()
	{
		prim = new Nod();
		ultim = new Nod();
		prim->n = 0;
		ultim->n = 0;
		prim->next = ultim;
		ultim->next = NULL;
		curent = prim;
		l = 0;
	}
	Nod* nodNou(int a)
	{
		Nod* p;
		p = new Nod();
		p->n = a;
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
		bool ok = true;
		curent = prim;
		while (curent->next != NULL && a!=0)
		{
			if (curent->n == a)
				ok = false;
			curent = curent->next;
		}
		if (ok == true)
		{
			curent = prim;
			if (l == 0)
			{
				atribuire(a);
			}
			else
			{
				while (curent->next != NULL)
				{
					if (curent->next->n < a || curent->next->next == NULL)
					{
						atribuire(a);
						break;
					}
					curent = curent->next;
				}

			}
		}

	}
	void afisare()
	{
		curent = prim->next;
		while (curent->next != NULL)
		{
			cout << curent->n <<endl;
			curent = curent->next;
		}
	}
};

int main()
{
	Lista l;
	int nr;
	cin >> nr;
	while (nr)
	{
		l.adaugare(nr);
		cin >> nr;
	}

	l.afisare();

	return 0;
}