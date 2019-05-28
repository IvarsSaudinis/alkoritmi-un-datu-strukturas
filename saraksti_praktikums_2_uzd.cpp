/*
 * TODO: Uzrakstīt C++ programmu, kas izveido 20 elementu saistīto sarakstu; pēc tam - ļauj lietotājam ievadīt skaitli N un aiz saraksta N-tā elementa pievieno jauno elementu (gadījuma skaitli).
 *
 * Write C++ program that creates the linked list with 20 nodes (random integers), allows to input integer and add new node to the linked list after the N-th node.
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
    Saraksts *H, *p, *t, *k;

    cout << "Original: " << endl;

    H = new Saraksts;
    H->Iepr = NULL;
    H->Dati = rand() % 99 + 1;
    p = H;

    for(int i=0; i < 20; i++)
    {
        p->Cits = new Saraksts;
        p->Cits->Iepr = p;
        p = p->Cits;
        p->Dati = rand() % 99 + 1;
    }
    p->Cits = NULL;

    p = H;
    izdruka(p);

    int N = -1;
    // elementa ievade, kas aptuveni iekļaujas saraksta plašumā
    while(N<0||N>20)
    {
        cout << "Ievadi skaitli N aiz kura pievieno jaunu elementu: "; cin >> N;
    }

    // pievienojam jaunu gadījuma elementu
    p = H;
    // atrodam pēdējo elementu
    for(int o=1; o< N+1; o++)
    {
        p = p->Cits;
        k = p->Cits;
    }

    // Saglabājam jauno ierakstu atmiņā
    t = new Saraksts;
    t->Dati = rand() % 99 + 1;
    p->Cits = t;
    p->Cits->Cits = k;

    p = H;
    izdruka(p);

    return 0;
}
