//
// Created by Mihnea Marinescu on 24.04.2023.
//

#include<vector>
#include"Tranzactie.h"
using namespace std;

class RepositoryTranzactie {
private:
    vector<Tranzactie> Tranzactii;
public:
    RepositoryTranzactie() = default;
    ~RepositoryTranzactie() = default;

    void addTranzactie(Tranzactie &tranzactie);
    void removeTranzactie(int pos);
    void modificaTranzactie(int pos, int zi, int suma, char *tip, char *descriere);
    Tranzactie getTranzactionAtPosition(int pos);
    vector<Tranzactie> getAll();
};





