/*
Uzrakstīt C++ programmu, kas
a) izveido 30 pseidogadījuma skaitļu (visas vērtības ir starp 1 un 99) sarakstu;
b) izvada tā saturu ekrānā;
c) izvada ekrānā izveidotā saraksta nepāra skaitļus;
d) izvada ekrānā no izveidotā saraksta skaitļus, ka ir mazāki par 20 vai lielāki par 80
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct Saraksts
{
int Dati;
Saraksts * Cits;
};

int main() {

    srand(time(0));

Saraksts *H, *p;
// pirma ieraksta izveide
H = new Saraksts;
H->Dati = rand() % 99 + 1;
p = H;

for(int i=0; i<29; i++)
    {
        p->Cits = new Saraksts;
p = p->Cits;
p->Dati = rand() % 99 + 1;
}

// lai programma tālāk nemeklētu sarakstā (uzskatītu, ka nav nekā) to definejam kā NULL
p->Cits = NULL;

p = H;
// izvada sarakstu
while(p != NULL)
    {
        cout << p->Dati << " ";
p = p->Cits;
}
    cout << endl;
// jāatgriežas sākumpozīcijā lai atkal var pārbaudes veikt
p = H;
// izvada ekrānā izveidotā saraksta nepāra skaitļus
while(p != NULL)
    {
if(p->Dati % 2 == 1)
        {
            cout << p->Dati << " ";
}

        p = p->Cits;
}

    cout << endl;
p = H;
// izvada ekrānā no izveidotā saraksta skaitļus, ka ir mazāki par 20 vai lielāki par 80
while(p != NULL)
    {
if(p->Dati < 20 || p->Dati > 80)
        {
            cout << p->Dati << " ";
}

        p = p->Cits;
}


return 0;
}
