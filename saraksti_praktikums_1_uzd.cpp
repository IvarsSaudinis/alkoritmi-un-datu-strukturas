/*
 * TODO: Uzrakstīt C++ programmu, kas izveido saistīto sarakstu, kur elementu skaitu nosaka kā gadījuma skaitli (starp 20 un 50). Pēc tam programma saskaita, cik pāra elementu ir sarakstā. Programma izdrukā ekrānā – saraksta elementus un elementu skaitu.
 *
 * Write C++ program that creates linked list with N nodes, where N is random integer between 20 and 50. The the program counts the number of even nodes.
 * --
 * build with CLion/ch-0/183.5429.37/bin/cmake/linux/bin/cmake
 */
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct Saraksts                     // classic
{
int Dati;
Saraksts *Cits, *Iepr;
};



void izdruka(struct Saraksts *p )
{
while(p != NULL)
    {
        cout << p->Dati << " ";
p = p->Cits;
}
    cout << endl;
}

int main (){

    srand(time(0));                 // "random" sēkliņas izmešana
Saraksts *H, *p;

cout << "Original: " << endl;

H = new Saraksts;
H->Iepr = NULL;
H->Dati = rand() % 99 + 1;
p = H;

    for(int i=0; i < rand() % 31 + 21; i++)
    {
        p->Cits = new Saraksts;
p->Cits->Iepr = p;
p = p->Cits;
p->Dati = rand() % 99 + 1;
}
    p->Cits = NULL;

p = H;
izdruka(p);

cout << "Pāra elementu skaits:" << endl;
    int paari =0;
    while(p != NULL)
    {
if(p->Dati % 2 ==0)
        {
            paari++;
}
        p = p->Cits;
}

    cout << paari << endl;


    return 0;
}
