//
// Created by Mihnea Marinescu on 22.09.2023.
//
#include<iostream>
#include<cstring>
using namespace std;

#ifndef PROIECT_AUTO_MASINA_H
#define PROIECT_AUTO_MASINA_H


class Masina {

private:
    int an;
    string marca;
    string model;
    int putere;

public:
    Masina() = default;
    Masina(const string &marca, const string &model, int an, int putere);

    const string &getMarca() const;
    const string &getModel() const;
    int getAn() const;
    int getPutere() const;

    void setMarca(const string marca);
    void setModel(const string model);
    void setAn(int an);
    void setPutere(int putere);





};


#endif //PROIECT_AUTO_MASINA_H
