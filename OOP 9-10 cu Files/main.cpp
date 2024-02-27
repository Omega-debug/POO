#include <iostream>
#include "RepoFile.h"
#include "teste.h"

int main() {

    //testProdus();

    RepoFile repository("Produse.txt");
    vector<Produs> v = repository.getAll();
        Produs s1(333,"Miere",20);
        repository.add(s1);
    cout<<repository.find(s1)<<endl;
    Produs s2(250,"Tigari", 40);
    repository.update(s1,s2);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
