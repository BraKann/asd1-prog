#include<iostream>
#include<math.h>
using namespace std;

int main()
{

  //VARIABLES
    int a;
    int b;
    int c;

    int* p1;
    int* p2;

  //DEBUT
    a = 5;
    b = 7;
    c = 9;

    p1 = &a;
    p2 = &c;

    //cout << *p1 << " " << *p2 << endl;
    *p1 = (*p2)++; //a cette place le ++ s'effectue sur *p2 aprés l'affectation
    //cout << *p1 << " " << *p2 << endl;

    p1 = p2;
    p2 = &b;

    *p1 -= *p2;
    ++(*p2);

    *p1 *= *p2;

    a = (++(*p2)) * *p1;//a cette place le ++ s'effectue en premier

    p1 = &a;

    *p2 = *p1 /= *p2;

    cout << "a" << endl;
    cout << a << endl;
    cout << &a << endl;
    cout << endl;

    cout << "b" << endl;
    cout << b << endl;
    cout << &b << endl;
    cout << endl;

    cout << "c" << endl;
    cout << c << endl;
    cout << &c << endl;
    cout << endl;

    cout << "p1" << endl;
    cout << p1 << endl;
    cout << *p1 << endl;
    cout << endl;

    cout << "p2" << endl;
    cout << p2 << endl;
    cout << *p2 << endl;

    return 0;
}














































































































//chris u crazy :OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
