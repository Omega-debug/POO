//
// Created by Mihnea Marinescu on 11.05.2023.
//

#include<vector>
#include"Produs.h"


class RepoFile {
private:
    vector<Produs> produse;
    char *fileName;
    void SaveToFile();

public:
    RepoFile();
    RepoFile(char *fileName);
    void add(Produs &produs);
    bool find(Produs &produs);
    bool remove(Produs &produs);
    bool update(Produs &produs1, Produs &produs2);
    vector<Produs> getAll();
    ~RepoFile();


};



