//
// Created by Mihnea Marinescu on 22.09.2023.
//

#include "Masina.h"
Masina::Masina(const std::string &marca, const std::string &model, int an, int putere): marca(marca), model(model), an(an), putere(putere) {}


const string &Masina::getMarca() const {
    return marca;
}

const string &Masina::getModel() const {
    return model;
}

int Masina::getAn() const {
    return an;
}

int Masina::getPutere() const {
    return putere;
}

void Masina::setMarca(const std::string marca) {
    Masina:: marca = marca;
}

void Masina::setModel(const std::string model) {
    Masina:: model = model;
}

void Masina::setAn(int an) {
    Masina:: an = an;
}

void Masina::setPutere(int putere) {
    Masina:: putere = putere;
}


