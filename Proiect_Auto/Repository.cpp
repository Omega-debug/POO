//
// Created by Mihnea Marinescu on 22.09.2023.
//

#include "Repository.h"

void Repository::addMasina(Masina &m) {
    this->masini.push_back(m);
}

void Repository::removeMasina(int pos) {
    this->masini.erase(masini.begin()+pos);
}

Masina Repository::getAtPos(int pos) {
    return this->masini[pos];

}

void Repository::modificaMasina(const std::string &marca, const std::string &model, int an, int putere, int pos) {
    masini[pos].setPutere(putere);
    masini[pos].setAn(an);
    masini[pos].setModel(model);
    masini[pos].setMarca(marca);
}

vector<Masina> Repository::getAll() {
    return this->masini;
}