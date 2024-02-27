//
// Created by Mihnea Marinescu on 29.04.2023.
//

#include "UI.h"
#include<iostream>
using namespace std;

UI::UI(Service &otherService) {
    this->service = otherService;
}

int UI::printMenu() {
    cout << "Please choose an option:" << endl;
    cout << "1. Adauga o tranzactie." << endl;
    cout << "2. Sterge toate tranzactiile dintr-o zi data. " << endl;
    cout << "3. Modifica Tranzactia cu numarul dat: " << endl ;
    cout << "4. Afiseaza toate tranzactiile din lista." << endl;
    cout << "5. Afiseaza toate tranzactiile de tip IN din lista." << endl;
    cout << "6. Afiseaza toate tranzactiile de tip OUT din lista." << endl;
    cout << "7. Afiseaza toate tranzactiile din lista cu suma mai mare decat un numar dat." << endl;
    cout << "8. Afiseaza toate tranzactiile din lista cu suma egala cu un numar dat." << endl;
    cout << "9. Afiseaza SOLD-ul unei zile." << endl;
    cout << "10. Afiseaza Suma totala a tranzactiilor de tip IN" << endl;
    cout << "11. Afiseaza cea mai valoroasă tranzacție de tip OUT dintr-o zii data." << endl;
    cout << "12. Filtreaza lista cu tranzactii de tip IN." << endl;
    cout << "13. Filtreaza lista cu tranzactii de tip IN si suma mai mica decat un numar dat." << endl;
    cout << "14. UNDO." << endl;
    cout << "15. Exit" << endl;
    cout << "Your option: ";
    int option;
    cin >> option;
    cout << endl;
    return option;
}

void UI::addTranzaction() {
    int ziua, suma;
    char tip[100], descriere[100];

    cout <<"Introdu ziua tranzactiei: ";
    cin >> ziua;
    if(ziua<1 || ziua>31){
        throw invalid_argument("ziua nu este valida");
    }
    cout <<"Introdu suma tranzactiei: ";
    cin >> suma;

    cout <<"Introdu tip-ul tranzactiei: ";
    cin >> tip;

    cout <<"Introdu descierea tranzactiei: ";
    cin >> descriere;

    cout << endl;

    this->service.addTranzactie(Tranzactie(ziua,suma,tip,descriere));

}

void UI::modificaTranzactie() {
    int ziua, suma, pozitia;
    char tip[100], descriere[100];
    cout << "Introdu numarul tranzactiei: ";
    cin >> pozitia;
    cout << endl;
    cout << "Introdu noua zi: ";
    cin >> ziua;
    cout << endl;
    cout <<"Introdu noua suma: ";
    cin >> suma;
    cout << endl;
    cout <<"Introdu noul tip: ";
    cin >> tip;
    cout << endl;
    cout <<"Introdu noua descriere: ";
    cin >> descriere;
    cout << endl;
    Tranzactie t(ziua, suma, tip, descriere);
    this->service.modificaTranzactie(t,pozitia);
}

void UI::removeTranzactionZii() {
    int ziua;
    cout << "Introdu ziua pentru care doresti sa fie sterse tranzactiile: ";
    cin >> ziua;
    cout << endl;

    this->service.removeTranzactieZii(ziua);

}


void UI::printAll() {
    for(auto tranzactie:this->service.getAll()){
        cout << tranzactie.getZiua() << " " << tranzactie.getSuma() << " " << tranzactie.getTip() << " " << tranzactie.getDescriere() << endl;
    }
    cout << endl;
}

void UI::printAll_IN() {
    for(auto tranzactie: this->service.filterByTip("in")){
        cout << tranzactie.getZiua() << " " << tranzactie.getSuma() << " " << tranzactie.getTip() << " " << tranzactie.getDescriere() << endl;
    }
    cout << endl;
}

void UI::printAll_OUT() {
    for(auto tranzactie:this->service.filterByTip("out")) {
        cout << tranzactie.getZiua() << " " << tranzactie.getSuma() << " " << tranzactie.getTip() << " " << tranzactie.getDescriere() << endl;
    }
    cout << endl;
}

void UI::printAll_Mai_Mare_Ca() {
    int suma;
    cout <<"Introduceti minimul sumei: ";
    cin >> suma;
    cout << endl;

    for(auto tranzactie: this->service.Suma_Mai_Mare(suma)){
        cout << tranzactie.getZiua() <<" "<< tranzactie.getSuma() <<" " << tranzactie.getTip() <<" " << tranzactie.getDescriere() << endl;
    }
}

void UI::printAll_Egal() {
    int suma;
    cout <<"Introduceti suma dorita: ";
    cin >> suma;
    cout << endl;

    for(auto tranzactie:this->service.Suma_Egala(suma)){
        cout << tranzactie.getZiua() <<" "<< tranzactie.getSuma() <<" " << tranzactie.getTip() <<" " << tranzactie.getDescriere() << endl;
    }
}

void UI::soldulet() {
    int ziua;
    cout <<"Introduceti ziua pentru care doriti sa fie facuta SOLD-ul:";
    cin >> ziua;


    cout << this->service.SOLD(ziua);
    cout << endl;
}

void UI::SUMA_IN() {
    cout << this->service.SUMinORout("in");
    cout << endl;
}

void UI::T_MAX_OUT() {
    int ziua;
    cout <<"Introdu ziua dorita: ";
    cin >> ziua;

    cout << this->service.MaxTranzaction_IN_OR_OUT("out", ziua);
}

void UI::FiltruIN() {
    service.FiltruIN();
}

void UI::FiltruIN2() {
    int suma;
    cout << "Introdu suma maxima: ";
    cin >> suma;
    cout << endl;
    service.FiltruIN2(suma);
}

void UI::UNDO() {
    this->service.Undo();
}

void UI::start() {
    int option;

    while(true) {
        option = this->printMenu();

        switch (option) {
            case 1:
                this->addTranzaction();
                break;
            case 2:
                this->removeTranzactionZii();
                break;
            case 3:
                this->modificaTranzactie();
                break;
            case 4:
                this->printAll();
                break;
            case 5:
                this->printAll_IN();
                break;
            case 6:
                this->printAll_OUT();
                break;
            case 7:
                this->printAll_Mai_Mare_Ca();
                break;
            case 8:
                this->printAll_Egal();
                break;
            case 9:
                this->soldulet();
                break;
            case 10:
                this->SUMA_IN();
                break;
            case 11:
                this->T_MAX_OUT();
                break;
            case 12:
                this->FiltruIN();
                break;
            case 13:
                this->FiltruIN2();
                break;
            case 14:
                this->UNDO();
                break;
            case 15:
                cout << "Exiting..." << endl;
                return;
        }

    }
}












