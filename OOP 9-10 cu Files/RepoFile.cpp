//
// Created by Mihnea Marinescu on 11.05.2023.
//

#include "RepoFile.h"
#include <algorithm>
#include <fstream>
using namespace std;

RepoFile::RepoFile() {
    this->fileName = nullptr;
}

RepoFile::RepoFile(char *fileName) {
    this->fileName = fileName;
    ifstream f(fileName);
    while(!f.eof()){
        int cod;
        string nume;
        int pret;
        f >> cod >> nume >> pret;
        Produs p(cod,nume,pret);
        produse.push_back(p);
}
    f.close();
}

void RepoFile::add(Produs &produs) {
    this->produse.push_back(produs);
    SaveToFile();
}

bool RepoFile::find(Produs &produs) {
    vector<Produs> ::iterator it = std::find(produse.begin(), produse.end(), produs);
    if(it == produse.end())
        return false;
    else return true;

}

bool RepoFile::remove(Produs &produs){
    vector<Produs>::iterator it = std::find(produse.begin(),produse.end(),produs);
    if(it!=produse.end()){
        produse.erase(it);
        SaveToFile();
        return true;
    }
    return false;
}

bool RepoFile::update(Produs &produs1, Produs &produs2) {
    vector<Produs>::iterator it = std::find(produse.begin(), produse.end(), produs1);
    if (it != produse.end()) {
        produse[it - produse.begin()] = produs2;
        SaveToFile();
        return true;
    }
    return false;
}


vector<Produs> RepoFile::getAll() {
    return this->produse;
}

RepoFile::~RepoFile(){
}


void RepoFile::SaveToFile() {
    ofstream  f(fileName);
    for(Produs crt:produse)
        f<<crt.ToString()<<endl;
    f.close();
}
