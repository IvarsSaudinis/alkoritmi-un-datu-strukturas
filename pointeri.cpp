/*
Uzrakstīt programmu, kurā nodefinēti int tipa mainīgie x un y un int* pointera mainīgie p un q. 
Piešķirt x un y sākuma vērtības. Pointerim mainīgajam p piešķirt mainīgā x adresi, un pointera 
mainīgajam q – mainīgā y adresi. Izdrukāt šādu informāciju:

1) x adrese un x vērtība;
2) p vērtība un *p vērtība;
3)  y adrese un y vērtība;
4) q vērtība un *q vērtība;
5) p adresi (ne saturu);
6) q adresi (ne saturu).
*/
#include <iostream>

using namespace std;

int main() {

int y = 111;
int x = 222;

int* p;
int* q;

p = &x;
q = &y;

// 1) x adrese un x vērtība;
cout << "x adrese: " << &x << "\t" << "x vertiba: "<< x << endl;

// 2) p vērtība un *p vērtība;
cout << "p vertiba: " << p << "\t" << "*p vertiba: "<< *p << endl;

// 3)  y adrese un y vērtība;
cout << "y adrese: " << &y <<  "\t" << "y vertiba: "<< y << endl;

// 4) q vērtība un *q vērtība;
cout << "q vertiba: " << q <<  "\t" << "*q vertiba: "<< *q << endl;

// 5) p adresi (ne saturu);
cout << "p adrese: " << &p  << endl;

// 6) q adresi (ne saturu).
cout << "q adrese: " << &q  << endl;

return 0;
}
