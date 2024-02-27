//
// Created by Mihnea Marinescu on 24.04.2023.
//

#include "RepositoryTranzactie.h"

Tranzactie RepositoryTranzactie::getTranzactionAtPosition(int pos) {
    return this -> Tranzactii[pos];
}

void RepositoryTranzactie::addTranzactie(Tranzactie &tranzactie) {
    this -> Tranzactii.push_back(tranzactie);
}

void RepositoryTranzactie::removeTranzactie(int pos) {
    this -> Tranzactii.erase(Tranzactii.begin() + pos );

}

void RepositoryTranzactie::modificaTranzactie(int pos, int zi, int suma, char *tip, char *descriere) {
    Tranzactii[pos].setTip(tip);
    Tranzactii[pos].setZiua(zi);
    Tranzactii[pos].setSuma(suma);
    Tranzactii[pos].setDescriere(descriere);
}

vector<Tranzactie> RepositoryTranzactie::getAll() {
    return this -> Tranzactii;
}

