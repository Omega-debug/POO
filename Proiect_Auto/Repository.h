//
// Created by Mihnea Marinescu on 22.09.2023.
//

#ifndef PROIECT_AUTO_REPOSITORY_H
#define PROIECT_AUTO_REPOSITORY_H


#include<vector>
#include"Masina.h"


class Repository {
private:
    vector<Masina> masini;

public:
    Repository() = default;
    ~Repository() = default;

    void addMasina(Masina &m);
    void removeMasina(int pos);
    void modificaMasina(const string &marca, const string &model, int an, int putere, int pos);
    Masina getAtPos(int pos);
    vector<Masina> getAll();


};


#endif //PROIECT_AUTO_REPOSITORY_H
