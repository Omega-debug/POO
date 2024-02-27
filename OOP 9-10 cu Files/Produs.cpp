#include "Produs.h"

Produs::Produs() {
    cod = 0;
    nume = "";
    pret = 0;
}

Produs::Produs(int cod, string nume, int pret) {
    this->cod = cod;
    this->nume = nume;
    this->pret = pret;
}

Produs::Produs(const Produs &produs) {
    this->cod = produs.cod;
    this->nume = produs.nume;
    this->pret = produs.pret;
}

int Produs::getCod() {
    return this->cod;
}

string Produs::getNume() {
    return this->nume;
}

int Produs::getPret() {
    return this->pret;
}

void Produs::setCod(int cod) {
    this->cod = cod;
}

void Produs::setNume(string nume) {
    this->nume = nume;
}

void Produs::setPret(int pret) {
    this->pret = pret;
}

Produs &Produs::operator=(const Produs &produs) {
    if(this!=&produs){
        this->cod = produs.cod;
        this->nume = produs.nume;
        this->pret = produs.pret;
    }
    return *this;
}

bool Produs::operator==(const Produs &student) {
    return (this->nume == student.nume and this->pret == student.pret and this->cod == student.cod);
}

bool Produs::operator<(const Produs &student) {
    return (this->nume<student.nume);
}

string Produs::ToString() {
    return std::to_string(this->cod) + " " + this->nume+" "+std::to_string(this->pret);
}

Produs::~Produs() {

}