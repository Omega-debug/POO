//
// Created by Mihnea Marinescu on 22.09.2023.
//

#ifndef PROIECT_AUTO_SERVICE_H
#define PROIECT_AUTO_SERVICE_H

#include "Repository.h"
class Service {

private:
    Repository repo;

public:
    Service() = default;
    Service(Repository otherService);
    ~Service() = default;

    vector<Masina> getAll();

    void addMasina(Masina m);

    Masina getMasinaAtPos(int pos);



};


#endif //PROIECT_AUTO_SERVICE_H
