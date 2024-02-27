//
// Created by Mihnea Marinescu on 24.04.2023.
//

#include "Tranzactie.h"
#include<iostream>
#include"string.h";
using namespace std;

Tranzactie::Tranzactie() {
    cout << "Default Constructor" << endl;
    this -> ziua = 0;
    this -> suma = 0;
    this -> tip = NULL;
    this -> descriere = NULL;
}

Tranzactie::Tranzactie(int ziua, int suma, char *tip, char *descriere) {
    cout << "Parameters Constructor" << endl;
    this -> ziua = ziua;
    this -> suma = suma;
    this -> tip = new char[strlen(tip) + 1];
    strncpy(this->tip, tip, strlen(tip));
    this -> descriere = new char[strlen(descriere)+1];
    strncpy(this->descriere, descriere, strlen(descriere));

}


Tranzactie::Tranzactie(const Tranzactie &otherTranzactie) {

    cout << "Copy Constructor" << endl;
    this -> ziua = otherTranzactie.ziua;
    this -> suma = otherTranzactie.suma;
    this -> tip = new char[strlen(otherTranzactie.tip) + 1];
    strncpy(this->tip, otherTranzactie.tip, strlen(otherTranzactie.tip));
    this -> descriere = new char[strlen(otherTranzactie.descriere)+1];
    strncpy(this->descriere, otherTranzactie.descriere, strlen(otherTranzactie.descriere));

}

Tranzactie::~Tranzactie() {
    delete [] this -> tip;
    delete [] this -> descriere;
}

Tranzactie &Tranzactie::operator=(const Tranzactie &otherTranzactie) {
    cout << "Using = operator" << endl;
    if(this == &otherTranzactie) {
        return *this;
    }

    this -> ziua = otherTranzactie.ziua;
    this -> suma = otherTranzactie.suma;
    this -> tip = new char[strlen(otherTranzactie.tip) + 1];
    strncpy(this->tip, otherTranzactie.tip, strlen(otherTranzactie.tip));
    this -> descriere = new char[strlen(otherTranzactie.descriere) +1];
    strncpy(this->descriere, otherTranzactie.descriere, strlen(otherTranzactie.descriere));
    return *this;

}

bool Tranzactie::operator==(const Tranzactie &t) {
    return ((strcmp(this->tip, t.tip)) && (this->ziua == t.ziua) && (this->suma == suma) && (strcmp(this->descriere, t.descriere) == 0));
}

int Tranzactie::getZiua() {
    return this -> ziua;
}

int Tranzactie::getSuma() {
    return this -> suma;
}

char *Tranzactie::getTip() {
    return this -> tip;
}

char *Tranzactie::getDescriere() {
    return this -> descriere;
}

void Tranzactie::setSuma(int suma) {
    this -> suma = suma;
}

void Tranzactie::setZiua(int ziua) {
    this -> ziua = ziua;
}

void Tranzactie::setTip(char *tip) {
    if(this->tip){
        delete []this->tip;
    }

    this -> tip = new char[strlen(tip)+1];
    strncpy(this->tip, tip, strlen(tip));
}

void Tranzactie::setDescriere(char *descriere) {
    if(this->descriere){
        delete []this->descriere;
    }

    this ->descriere = new char[::strlen(descriere)+1];
    strncpy(this->descriere, descriere, strlen(descriere));
}

Tranzactie::Tranzactie(Tranzactie &&other) {
    cout << "move constructor" << endl;
    // Move the name and age from the other object
    tip = other.tip;
    ziua = other.ziua;
    suma = other.suma;
    descriere = other.descriere;

    // Reset the other object's fields to a valid state
    other.tip = nullptr;
    other.ziua = 0;
    other.suma = 0;
    other.descriere = nullptr;
}
