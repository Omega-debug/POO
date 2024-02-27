#include"teste.h"
#include"Produs.h"
#include<iostream>
#include<cassert>
using namespace std;

void testProdus(){

    Produs P1;
    assert(P1.getCod() == 0);
    assert(P1.getNume() == "");
    assert(P1.getPret() == 0);
    P1.~Produs();
    Produs P2(10,"bere", 145);
    assert(P2.getCod() == 10);
    assert(P2.getNume() == "bere");
    assert(P2.getPret() == 145);

    Produs P3 = P2;
    assert(P3.getCod() == 10);
    assert(P3.getNume() == "bere");
    assert(P3.getPret() == 145);

    P2.~Produs();
    P3.~Produs();
}