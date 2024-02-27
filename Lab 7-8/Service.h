//
// Created by Mihnea Marinescu on 25.04.2023.
//



#include"RepositoryTranzactie.h"
class Service {
private:
    RepositoryTranzactie repo;
    vector<string> historyActions;
    vector<Tranzactie> history;
public:
    Service() = default;
    Service(RepositoryTranzactie otherRep);
    ~Service() = default;

    vector<Tranzactie> getAll();
    Tranzactie getTranzactieByPosition(int position);
    void addTranzactie(Tranzactie tran);
    void removeTranzactie(int pos);
    void eliminaTranzactii(int ziuaInceput, int ziuaFinal);
    void remove_tranzactii_IN_or_OUT(char *tip);
    void modificaTranzactie(Tranzactie tranzactie, int pos);
    vector<Tranzactie> filterByTip(char *tip);
    vector<Tranzactie> filterByTipAndMaximSum(char *tip, int sum);

    int SUMinORout(char *tip);
    int MaxTranzaction_IN_OR_OUT(char *tip, int ziua);

    void removeTranzactieZii(int ziua);
    vector<Tranzactie> Suma_Mai_Mare(int suma);
    vector<Tranzactie> Suma_Egala(int suma);
    int SOLD(int ziua);

    void FiltruIN();
    void FiltruIN2(int suma);

    void Undo();

};