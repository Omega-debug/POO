//
// Created by Mihnea Marinescu on 24.04.2023.
//

#include<iostream>
#include"teste.h";
#include"Service.h";
using namespace std;

void testTranzactie(){

    //Default Constructor Test
    Tranzactie T1;
    assert(T1.getSuma() == 0);
    assert(T1.getZiua() == 0);
    assert(T1.getTip() == NULL);

    //Parameters Constructor Tests
    Tranzactie T2(31, 500, "in", "descriere");
    assert(T2.getZiua() == 31);
    assert(T2.getSuma() == 500);
    assert(strcmp(T2.getTip(),"in") == 0);


    Tranzactie T3(25, 200, "out", "descriere");
    assert(T3.getZiua() == 25);
    assert(T3.getSuma() == 200);
    assert(strcmp(T3.getTip(),"out") == 0);

    // Using Operator;

    Tranzactie T4;
    T4 = T3;
    assert(T4.getZiua() == 25);
    assert(T4.getSuma() == 200);
    assert(strcmp(T4.getTip(),"out") == 0);

}

void testRepositoryTranzactie(){


    // Test GetAtPosition, addElement
    Tranzactie T5(30, 550, "in", "descriere");
    Tranzactie T6(5, 203, "out", "descriere");
    Tranzactie T7(31, 400, "out", "descriere");
    Tranzactie T8(6, 300, "in", "descriere" );
    Tranzactie T9(7,315,"out", "descriere");
    Tranzactie T10(8,505, "out", "descriere");
    Tranzactie T11(5, 220, "in", "descriere");
    RepositoryTranzactie repo;
    repo.addTranzactie(T5);
    repo.addTranzactie(T6);
    repo.addTranzactie(T7);

    assert(repo.getTranzactionAtPosition(0).getZiua() == 30);
    assert(repo.getTranzactionAtPosition(0).getSuma() == 550);
    assert(strcmp(repo.getTranzactionAtPosition(0).getTip(),"in") == 0);

    assert(repo.getTranzactionAtPosition(2).getZiua() == 31);
    assert(repo.getTranzactionAtPosition(2).getSuma() == 400);
    assert(strcmp(repo.getTranzactionAtPosition(2).getTip(), "out") == 0);


    // Test Modificare
    RepositoryTranzactie resulults;
    resulults.addTranzactie(T5);
    resulults.addTranzactie(T6);
    resulults.addTranzactie(T7);
    resulults.addTranzactie(T8);
    resulults.addTranzactie(T9);
    resulults.addTranzactie(T10);
    resulults.addTranzactie(T11);

    assert(resulults.getTranzactionAtPosition(0).getZiua() == 30);
    resulults.removeTranzactie(0);
    assert(resulults.getTranzactionAtPosition(0).getZiua() == 5);

    resulults.modificaTranzactie(0, 4, 500,"in", "descriere");
    assert(resulults.getTranzactionAtPosition(0).getZiua() == 4);

    //resulults.modificaTranzactie(5,8);
    //assert(resulults.getTranzactionAtPosition(1).getZiua() == 31);




}

void testService() {
    Tranzactie T5(30, 550, "in", "descriere");
    Tranzactie T6(5, 203, "out", "descriere");
    Tranzactie T7(31, 400, "out", "descriere");
    Tranzactie T8(6, 300, "in","descriere"  );
    Tranzactie T9(7,315,"out", "descriere");
    Tranzactie T10(8,505, "out","descriere");
    Tranzactie T11(5, 220, "in","descriere");
    RepositoryTranzactie repo;


    Service service(repo);

    Tranzactie T25(2,30,"in","descriere");
    Tranzactie T26(3,69,"out","descriere");
    Tranzactie T27(4,150,"out","descriere");

    service.addTranzactie(T25);
    service.addTranzactie(T26);
    service.addTranzactie(T27);
    service.addTranzactie(T11);
    service.addTranzactie(T8);
    service.addTranzactie(T9);
    service.addTranzactie(T10);

    assert(service.getTranzactieByPosition(0).getZiua() == 2);
    assert(service.getTranzactieByPosition(0).getSuma() == 30);
    assert(::strcmp(service.getTranzactieByPosition(0).getTip(),"in") == 0);

    //cout << service.getTranzactieByPosition(7).getZiua() << endl;

    // TESTE pentru elimina
    //service.eliminaTranzactii(2,5);

    //TEST pentru eliminarea unei singure tranzactii

    service.eliminaTranzactii(2,2);
    assert(service.getTranzactieByPosition(0).getZiua() == 3);
    assert(service.getTranzactieByPosition(0).getSuma() == 69);
    assert(::strcmp(service.getTranzactieByPosition(0).getTip(), "out") == 0);

    //assert(service.getTranzactieByPosition(0).getZiua() == 6);

    // TEST pentru eliminarea mai multor tranzactii

//    RepositoryTranzactie repo1;
//    Service service1(repo1);
//    service1.addTranzactie(T25);
//    service1.addTranzactie(T26);
//    service1.addTranzactie(T27);
//    service1.addTranzactie(T11);
//    service1.addTranzactie(T8);
//    service1.addTranzactie(T9);
//    service1.addTranzactie(T10);
//
//    service1.eliminaTranzactii(5,7);


// Test pentru remove
    assert(service.getTranzactieByPosition(0).getZiua() == 3);
    service.removeTranzactie(0);
    assert(service.getTranzactieByPosition(0).getZiua() == 4);

    for(auto Tranzactie: service.getAll()){
        cout << Tranzactie.getZiua() <<" " <<Tranzactie.getSuma() <<" " << Tranzactie.getTip() << endl;
    }

    cout << endl;

    // TESTE FilterByTip
    for(auto Tranzactie: service.filterByTip("in")){
        assert(strcmp(Tranzactie.getTip(),"in") == 0);
    }

    for(auto Tranzactie:service.filterByTip("out")){
        assert(::strcmp(Tranzactie.getTip(),"out") == 0);
    }

    // TESTE FilterByTipAndSum

    for(auto Tranzactie: service.filterByTipAndMaximSum("in", 100)){
        assert(strcmp(Tranzactie.getTip(),"in") == 0 && Tranzactie.getSuma()<100);
    }

    for(auto Tranzactie:service.filterByTipAndMaximSum("out", 200)){
        assert(::strcmp(Tranzactie.getTip(),"out") == 0 && Tranzactie.getSuma()<200);
    }


    //TESTE suma tranzactiilor de tip in/out

    int S = service.SUMinORout("in");
    assert(S == 520);

    int s = service.SUMinORout("out");
    assert(s == 970);

    // Test Maxim Tranzactie din Ziua Curenta

    RepositoryTranzactie repo2;
    Tranzactie m1(5,200,"in","descriere");
    Tranzactie m2(5,250,"in","descriere");
    Tranzactie m3(5,50,"out","descriere");
    Tranzactie m4(5, 12, "in","descriere");

    repo2.addTranzactie(m1);
    repo2.addTranzactie(m2);
    repo2.addTranzactie(m3);
    repo2.addTranzactie(m4);

    Service service2(repo2);

    int m = service2.MaxTranzaction_IN_OR_OUT("in", 5);
    assert(m == 250);

    // Test modifica
    Tranzactie m5(10,66,"out","descriere");
    service2.modificaTranzactie(m5, 3);
    assert(service2.getTranzactieByPosition(3).getZiua() == 10);
    assert(service2.getTranzactieByPosition(3).getSuma() == 66);
    assert(strcmp(service2.getTranzactieByPosition(3).getTip(),"out") == 0);

    RepositoryTranzactie repo1;
    Service service1(repo1);
    service1.addTranzactie(T25);
    service1.addTranzactie(T26);
    service1.addTranzactie(T27);
    service1.addTranzactie(T11);
    service1.addTranzactie(T8);
    service1.addTranzactie(T9);
    service1.addTranzactie(T10);

//    Tranzactie T25(2,30,"in");
//    Tranzactie T26(3,69,"out");
//    Tranzactie T27(4,150,"out");
//    Tranzactie T8(6, 300, "in" );
//    Tranzactie T9(7,315,"out");
//    Tranzactie T10(8,505, "out");
//    Tranzactie T11(5, 220, "in");

     // TEST Suma mai mare decat
     for(auto tranzactie:service1.Suma_Mai_Mare(100)){
         assert(tranzactie.getSuma() > 100);
     }

     // Test Suma egala
     for(auto tranzactie: service1.Suma_Egala(150)){
         assert(tranzactie.getSuma() == 150);
     }

     // Test Sold
     Tranzactie s1(10,1500,"in", "salariu baban");
     Tranzactie s2(10, 100, "in", "pacanele");
     Tranzactie s3(10, 500, "out", "pacanele");

     RepositoryTranzactie repoS;
     repoS.addTranzactie(s1);
     repoS.addTranzactie(s2);
     repoS.addTranzactie(s3);

     Service SS(repoS);
     int sold = SS.SOLD(10);
     assert(sold == 1100);


//    service1.remove_tranzactii_IN_or_OUT("in");
//    for(auto Tranzactie: repo.getAll()){
//        assert(strcmp(Tranzactie.getTip(),"out") == 0);
//    }

RepositoryTranzactie r;
Service pi(r);
Tranzactie t(10,250,"in","pizza");
pi.addTranzactie(t);
assert(pi.getTranzactieByPosition(0).getSuma() == 250);
Tranzactie q(10,150,"out","pizza");
pi.addTranzactie(q);
assert(pi.getTranzactieByPosition(1).getSuma() == 150);

Tranzactie T111(15,10,"in", "boabe");
}

