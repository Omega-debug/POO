//
// Created by Mihnea Marinescu on 25.04.2023.
//

#include "Service.h"
#include<cstring>
#include<iostream>
using namespace std;

Service::Service(RepositoryTranzactie otherRep) {
    this->repo = otherRep;
}

vector <Tranzactie> Service::getAll() {
    return this -> repo.getAll();
}


Tranzactie Service::getTranzactieByPosition(int position) {
    return this -> repo.getTranzactionAtPosition(position);
}

void Service::addTranzactie(Tranzactie tranzactie) {
    Tranzactie oldEntity = tranzactie;
    historyActions.push_back("add");
    history.push_back(oldEntity);
    this -> repo.addTranzactie(tranzactie);
}

void Service::removeTranzactie(int pos) {
//    Tranzactie oldEntity = repo.getTranzactionAtPosition(pos);
//    historyActions.push_back("delete");
//    history.push_back(oldEntity);
    this-> repo.removeTranzactie(pos);
}

void Service::modificaTranzactie(Tranzactie tranzactie, int pos) {
    Tranzactie oldEntity = tranzactie;
    historyActions.push_back("update");
    history.push_back(oldEntity);
    this-> repo.modificaTranzactie(pos,tranzactie.getZiua(), tranzactie.getSuma(), tranzactie.getTip(), tranzactie.getDescriere());
}



void Service::eliminaTranzactii(int ziuaInceput, int ziuaFinal) {
    int pos = 0;
    for(auto tranzactie:this->repo.getAll()){
        if(ziuaInceput <= tranzactie.getZiua() && tranzactie.getZiua()<= ziuaFinal){
            this->repo.removeTranzactie(pos);
        }
        pos++;
    }
}

void Service::removeTranzactieZii(int ziua) {
    int pos = 0;
    Tranzactie oldEntity = repo.getTranzactionAtPosition(pos);
    historyActions.push_back("delete");
    history.push_back(oldEntity);
    for(auto tranzactie:this->repo.getAll()){
        if(tranzactie.getZiua() == ziua){
            this->repo.removeTranzactie(pos);
        }
    }
    pos++;
}

vector<Tranzactie> Service::filterByTip(char *tip) { //Filtrarea tranzactiilor de tip IN/OUT
    vector<Tranzactie> results;

    for(auto tranzactie:this->repo.getAll()){
        if(strcmp(tranzactie.getTip(),tip)==0){
            results.push_back(tranzactie);
        }
    }
    return results;
}

vector<Tranzactie> Service::filterByTipAndMaximSum(char *tip, int sum) { // Filtrarea tranzactiilor de tip in/out cu suma mai mica decat sum
    vector<Tranzactie> rezultat;
    for(auto tranzactie: this->repo.getAll()){
        if(strcmp(tranzactie.getTip(),tip) == 0 && tranzactie.getSuma()<sum){
            rezultat.push_back(tranzactie);
        }
    }
    return rezultat;
}

int Service::SUMinORout(char *tip) {   // Suma totala a tranzactiilor de tip in sau out
    int S = 0;
    for(auto tranzactie: this->repo.getAll()){
        if(strcmp(tranzactie.getTip(),tip) == 0) S = S + tranzactie.getSuma();
    }
    return S;
}

int Service::MaxTranzaction_IN_OR_OUT(char *tip, int ziua) {
    int maxi = -1;
    for(auto tranzactie: this->repo.getAll()) {
        if(tranzactie.getSuma()>maxi && tranzactie.getZiua() == ziua) maxi = tranzactie.getSuma();
    }
    return maxi;
}

void Service::remove_tranzactii_IN_or_OUT(char *tip) {
    int pos = 0;
    for(auto tranzactie: this->repo.getAll()){
        if(strcmp(tranzactie.getTip(),"out") == 0){
            this->repo.removeTranzactie(pos);
        }
        pos++;
    }

}

vector<Tranzactie> Service::Suma_Mai_Mare(int suma) {
    vector<Tranzactie> res;
    for(auto tranzactie:this->repo.getAll()){
        if(tranzactie.getSuma() > suma){
            res.push_back(tranzactie);
        }
    }
    return res;
}

vector<Tranzactie> Service::Suma_Egala(int suma) {
    vector<Tranzactie> res1;
    for(auto tranzactie: this->repo.getAll()){
        if(tranzactie.getSuma() == suma){
            res1.push_back(tranzactie);
        }
    }
    return res1;
}

int Service::SOLD(int ziua) {
    int s1 = 0, s2 = 0;

    for(auto tranzactie:this->repo.getAll()){
        if(tranzactie.getZiua() == ziua) {
            if (strcmp(tranzactie.getTip(), "in") == 0) {
                s1 = s1 + tranzactie.getSuma();
            }
            if (strcmp(tranzactie.getTip(), "out") == 0) {
                s2 = s2 + tranzactie.getSuma();
            }
        }
    }
    return s1-s2;

}

void Service::FiltruIN() {
    int pos = 0;

    for(auto tranzactie:this->repo.getAll()){
        if(strcmp(tranzactie.getTip(),"out")==0){
            Tranzactie oldEntity = repo.getTranzactionAtPosition(pos);
            historyActions.push_back("delete");
            history.push_back(oldEntity);
            this->repo.removeTranzactie(pos);
        }
        pos++;
    }
}

void Service::FiltruIN2(int suma) {
    int pos = 0;

    for(auto tranzactie:this->repo.getAll()){
        if(strcmp(tranzactie.getTip(),"out")==0 || (tranzactie.getSuma() > suma)){
            Tranzactie oldEntity = repo.getTranzactionAtPosition(pos);
            historyActions.push_back("delete");
            history.push_back(oldEntity);
            this->repo.removeTranzactie(pos);
        }
        pos++;
    }
}

void Service::Undo()
{
    if(historyActions.empty()) {
        cout << "Nu exista actiuni de anulat "<< endl;
        return;
    }
    string lastAction = historyActions.back();
    historyActions.pop_back();

    Tranzactie lastEntity = history.back();
    history.pop_back();

    if(lastAction == "add") {
        repo.removeTranzactie(repo.getAll().size()-1);
    }
    else if(lastAction == "update") {
        Tranzactie oldEntity = lastEntity;
        repo.modificaTranzactie(history.size(), oldEntity.getZiua(), oldEntity.getSuma(), oldEntity.getTip(), oldEntity.getDescriere());
    }

    else if(lastAction == "delete") {
        Tranzactie deleteEntity = lastEntity;
        repo.addTranzactie(deleteEntity);
    }
}





