//
// Created by Mihnea Marinescu on 22.09.2023.
//

#include "Service.h"

void Service::addMasina(Masina m) {
    this -> repo.addMasina();
}

vector<Masina> Service::getAll() {
    this -> repo.getAll();
}

Masina Service::getMasinaAtPos(int pos) {
    return this->repo.getAtPos(pos);
}
