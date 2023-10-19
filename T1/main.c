#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

struct Dnod
{
    int n;
    struct Dnod* prev;
    struct Dnod* next;
};
struct Dlist
{
    int nrElem;
    struct Dnod* prim;
    struct Dnod* curent;
    struct Dnod* ultim;
};
void creareDlist(struct Dlist* lista);
struct Dnod* dnodNou(struct Dlist* lista, int a);
int dadaugare(struct Dlist* lista, int a);
void nafisare(struct Dlist* lista);
void rafisare(struct Dlist* lista);
void dafisare(struct Dlist* lista);

struct Nod
{
    struct Dlist* grup;
    struct Nod* next;
};
struct Lista
{
    int l;
    struct Nod *prim;
    struct Nod *curent;
    struct Nod *ultim;
};
void creareLista(struct Lista* list);
struct Nod* nodNou(struct Lista* list, int a);
void atribuire(struct Lista* list, int a);
void adaugare(struct Lista* list, int a);
void afisare(struct Lista* list);

struct Lista* l;
int n;

int main()
{
    creareLista(l);
    scanf_s("%d",&n);
    while (n)
    {
        adaugare(l,n);
        scanf_s("%d",&n);
    }

   afisare(l);

    return 0;
}

void creareDlist(struct Dlist* lista)
{
lista->prim = (struct Dnod *)malloc(sizeof(struct Dnod));
lista->ultim = (struct Dnod *)malloc(sizeof(struct Dnod));
lista->prim->n = 0;
lista->ultim->n = 0;
lista->prim->prev = NULL;
lista->prim->next = lista->ultim;
lista->ultim->next = NULL;
lista->ultim->prev = lista->prim;
lista->curent =lista->prim;
lista->nrElem = 0;
}
struct Dnod* dnodNou(struct Dlist* lista, int a)
{
    struct Dnod* p;
    p = (struct Dnod *)malloc(sizeof(struct Dnod));
    p->n = a;
    p->prev = lista->curent;
    p->next = lista->curent->next;
    lista->curent->next = p;
    lista->ultim->prev = p;
    lista->curent = p;
    lista->nrElem++;
    return p;
}
int dadaugare(struct Dlist* lista, int a)
{
    if (lista->nrElem == 3)
    {
        return 0;
    }
    else
    {
        struct Dnod* p;
        p = dnodNou(lista, a);
        return 1;
    }
}
void nafisare(struct Dlist* lista)
{
    lista->curent = lista->prim->next;
    while (lista->curent->next != NULL)
    {
        printf("%d",lista->curent->n);
        lista->curent = lista->curent->next;
    }
}
void rafisare(struct Dlist* lista)
{
    lista->curent = lista->ultim->prev;
    while (lista->curent->prev != NULL)
    {
        printf("%d",lista->curent->n);
        lista->curent = lista->curent->prev;
    }
}
void dafisare(struct Dlist* lista)
{
    if (lista->nrElem == 3)
        rafisare(lista);
    else
        nafisare(lista);
}

void creareLista(struct Lista* list)
{
    list->prim = (struct Nod *)malloc(sizeof(struct Nod));
    list->ultim = (struct Nod *)malloc(sizeof(struct Nod));
    creareDlist(list->prim->grup);
    creareDlist(list->ultim->grup);
    list->prim->next = list->ultim;
    list->ultim->next = NULL;
    struct Nod* p;
    p = (struct Nod *)malloc(sizeof(struct Nod));
    creareDlist(p->grup);
    p->next = list->prim->next;
    list->prim->next = p;
    list->curent = p;
    list->l = 1;
}
struct Nod* nodNou(struct Lista* list, int a)
{
    struct Nod* p;
    p = (struct Nod *)malloc(sizeof(struct Nod));
    creareDlist(p->grup);
    dadaugare(p->grup, a);
    p->next = NULL;
    return p;
}
void atribuire(struct Lista* list, int a)
{
    struct Nod* p;
    p = nodNou(list, a);
    p->next = list->curent->next;
    list->curent->next = p;
    list->curent = p;
    list->l++;
}
void adaugare(struct Lista* list, int a)
{
    if (dadaugare(list->curent->grup, a))
    {

    }
    else
        atribuire(list, a);
}
void afisare(struct Lista* list)
{
    list->curent = list->prim->next;
    while (list->curent->next != NULL)
    {
        dafisare(list->curent->grup);
        list->curent = list->curent->next;
    }
}