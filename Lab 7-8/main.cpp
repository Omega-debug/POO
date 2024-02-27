#include <iostream>
#include"teste.h"
#include"UI.h"
using namespace std;

int main() {
    testTranzactie();
    testRepositoryTranzactie();
    testService();

    RepositoryTranzactie repo;
    Service service(repo);
    UI ui(service);
    ui.start();

    return 0;
}
