#include<cstring>
#include <string>

using namespace std;

class Produs {
private:
    int cod;
    string nume;
    int pret;
public:
    Produs();
    Produs(int cod, string nume, int pret);
    Produs(const Produs& produs);
    int getCod();
    string getNume();
    int getPret();
    void setCod(int cod);
    void setNume(string nume);
    void setPret(int pret);
    Produs& operator=(const Produs& produs);
    bool operator==(const Produs& produs);
    bool operator<(const Produs& produs);
    string ToString();
    ~Produs();
};
